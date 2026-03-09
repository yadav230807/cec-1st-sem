#include <stdio.h>

#define MAX_SIGNALS 50

typedef struct {
    int id;
    float distanceFromStartKm;
    int normalGreenSeconds;
    int clearanceSeconds;
} TrafficSignal;

int main(void) {
    TrafficSignal signals[MAX_SIGNALS];
    int signalCount;
    float ambulanceSpeedKmph;
    int preClearBufferSeconds;
    float lastDistance = 0.0f;

    printf("=== Ambulance Priority Traffic Clearance Planner ===\n");
    printf("Enter ambulance speed (km/h): ");
    if (scanf("%f", &ambulanceSpeedKmph) != 1 || ambulanceSpeedKmph <= 0) {
        printf("Invalid speed. Please enter a positive number.\n");
        return 1;
    }

    printf("Enter pre-clear buffer (seconds before ambulance arrival): ");
    if (scanf("%d", &preClearBufferSeconds) != 1 || preClearBufferSeconds < 0) {
        printf("Invalid buffer. Please enter zero or a positive integer.\n");
        return 1;
    }

    printf("Enter number of traffic signals on route (max %d): ", MAX_SIGNALS);
    if (scanf("%d", &signalCount) != 1 || signalCount <= 0 || signalCount > MAX_SIGNALS) {
        printf("Invalid signal count.\n");
        return 1;
    }

    printf("\nEnter each signal as:\n");
    printf("<SignalID> <DistanceFromStart(km)> <NormalGreen(seconds)> <ClearanceNeeded(seconds)>\n");

    for (int i = 0; i < signalCount; i++) {
        if (scanf("%d %f %d %d",
                  &signals[i].id,
                  &signals[i].distanceFromStartKm,
                  &signals[i].normalGreenSeconds,
                  &signals[i].clearanceSeconds) != 4) {
            printf("Invalid input for signal %d.\n", i + 1);
            return 1;
        }

        if (signals[i].distanceFromStartKm < lastDistance) {
            printf("Distances must be in non-decreasing order.\n");
            return 1;
        }
        if (signals[i].normalGreenSeconds <= 0 || signals[i].clearanceSeconds <= 0) {
            printf("Green and clearance times must be positive.\n");
            return 1;
        }

        lastDistance = signals[i].distanceFromStartKm;
    }

    printf("\n=== Clearance Schedule ===\n");
    printf("Signal | ETA(s) | Start Pre-Clear(s) | Green Extension(s) | Action\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < signalCount; i++) {
        float etaSeconds = (signals[i].distanceFromStartKm / ambulanceSpeedKmph) * 3600.0f;
        float preClearAt = etaSeconds - (float)preClearBufferSeconds;
        if (preClearAt < 0) {
            preClearAt = 0;
        }

        int extraGreen = signals[i].clearanceSeconds - signals[i].normalGreenSeconds;
        if (extraGreen < 0) {
            extraGreen = 0;
        }

        printf("%6d | %6.1f | %17.1f | %16d | ",
               signals[i].id,
               etaSeconds,
               preClearAt,
               extraGreen);

        if (extraGreen > 0) {
            printf("Force GREEN (+%ds)\n", extraGreen);
        } else {
            printf("Normal green sufficient\n");
        }
    }

    printf("\nDispatch Tip: Send schedule to traffic controllers and IoT signal units in real time.\n");
    return 0;
}
