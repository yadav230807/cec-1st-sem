#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Car {
    int ticket_id;
    char car_number[15];
    char entry_time[20];
    char exit_time[20];
    float charges;
    int slot_number;
    int is_parked; // 1 for parked, 0 for exited
};

void parkCar() {
    struct Car car;
    FILE *f = fopen("parking.txt", "a");
    
    printf("Enter Car Number: ");
    getchar();
    fgets(car.car_number, 15, stdin);
    car.car_number[strcspn(car.car_number, "\n")] = 0;
    
    printf("Enter Slot Number: ");
    scanf("%d", &car.slot_number);
    
    car.ticket_id = rand() % 10000 + 1000;
    car.charges = 0.0;
    car.is_parked = 1; // Mark as parked
    
    // Get current time
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(car.entry_time, 20, "%Y-%m-%d %H:%M:%S", tm_info);
    strcpy(car.exit_time, "Not Exited");
    
    fprintf(f, "%d | %s | %d | %s | %s | %.2f | %d\n", 
            car.ticket_id, car.car_number, car.slot_number, 
            car.entry_time, car.exit_time, car.charges, car.is_parked);
    fclose(f);
    
    printf("Car parked successfully!\n");
    printf("Ticket ID: %d, Slot: %d\n", car.ticket_id, car.slot_number);
}

void viewParkedCars() {
    char line[200];
    FILE *f = fopen("parking.txt", "r");
    if (!f) { printf("No cars parked!\n"); return; }
    
    printf("\nCurrently Parked Cars:\n");
    printf("Ticket ID | Car Number | Slot | Entry Time\n");
    printf("------------------------------------------\n");
    
    while(fgets(line, 200, f)) {
        struct Car car;
        sscanf(line, "%d | %14[^|] | %d | %19[^|] | %19[^|] | %f | %d", 
               &car.ticket_id, car.car_number, &car.slot_number, 
               car.entry_time, car.exit_time, &car.charges, &car.is_parked);
        
        if(car.is_parked == 1) {
            printf("%d | %s | %d | %s\n", 
                   car.ticket_id, car.car_number, car.slot_number, car.entry_time);
        }
    }
    fclose(f);
}

void exitCar() {
    int ticket_id, found = 0;
    char line[200], temp_line[200];
    FILE *f = fopen("parking.txt", "r");
    FILE *t = fopen("temp.txt", "w");
    
    printf("Enter Ticket ID to exit: ");
    scanf("%d", &ticket_id);
    
    while(fgets(line, 200, f)) {
        strcpy(temp_line, line);
        
        struct Car car;
        sscanf(temp_line, "%d | %14[^|] | %d | %19[^|] | %19[^|] | %f | %d", 
               &car.ticket_id, car.car_number, &car.slot_number, 
               car.entry_time, car.exit_time, &car.charges, &car.is_parked);
        
        if(car.ticket_id == ticket_id && car.is_parked == 1) {
            found = 1;
            
            // Calculate charges based on time difference
            time_t now = time(NULL);
            struct tm *tm_info = localtime(&now);
            char exit_time[20];
            strftime(exit_time, 20, "%Y-%m-%d %H:%M:%S", tm_info);
            
            // Parse entry time to calculate duration
            struct tm entry_tm = {0};
            sscanf(car.entry_time, "%d-%d-%d %d:%d:%d", 
                   &entry_tm.tm_year, &entry_tm.tm_mon, &entry_tm.tm_mday,
                   &entry_tm.tm_hour, &entry_tm.tm_min, &entry_tm.tm_sec);
            entry_tm.tm_year -= 1900;
            entry_tm.tm_mon -= 1;
            
            time_t entry_time_t = mktime(&entry_tm);
            double diff_seconds = difftime(now, entry_time_t);
            int hours = (int)(diff_seconds / 3600) + 1; // Round up to nearest hour
            float charges = hours * 20.0; // ₹20 per hour
            
            fprintf(t, "%d | %s | %d | %s | %s | %.2f | %d\n", 
                    car.ticket_id, car.car_number, car.slot_number, 
                    car.entry_time, exit_time, charges, 0); // Mark as exited
            
            printf("Car exited successfully!\n");
            printf("Parking Duration: %d hours\n", hours);
            printf("Charges: ₹%.2f\n", charges);
            
        } else {
            fprintf(t, "%s", line); // Write unchanged line
        }
    }
    
    fclose(f); fclose(t);
    remove("parking.txt"); 
    rename("temp.txt", "parking.txt");
    if(!found) printf("Ticket ID not found or car already exited!\n");
}

void parkingStats() {
    FILE *f = fopen("parking.txt", "r");
    if (!f) { printf("No parking data!\n"); return; }
    
    char line[200];
    int total_cars = 0, parked_cars = 0;
    float total_earnings = 0, today_earnings = 0;
    
    // Get today's date for daily earnings
    time_t now = time(NULL);
    struct tm *today_info = localtime(&now);
    char today_date[11];
    strftime(today_date, 11, "%Y-%m-%d", today_info);
    
    while(fgets(line, 200, f)) {
        struct Car car;
        sscanf(line, "%d | %14[^|] | %d | %19[^|] | %19[^|] | %f | %d", 
               &car.ticket_id, car.car_number, &car.slot_number, 
               car.entry_time, car.exit_time, &car.charges, &car.is_parked);
        
        total_cars++;
        total_earnings += car.charges;
        
        // Check if entry date is today for daily earnings
        char entry_date[11];
        strncpy(entry_date, car.entry_time, 10);
        entry_date[10] = '\0';
        
        if(strcmp(entry_date, today_date) == 0) {
            today_earnings += car.charges;
        }
        
        if(car.is_parked == 1) {
            parked_cars++;
        }
    }
    fclose(f);
    
    printf("\n=== PARKING STATISTICS ===\n");
    printf("Total Cars Today: %d\n", total_cars);
    printf("Currently Parked: %d\n", parked_cars);
    printf("Available Slots: %d\n", 50 - parked_cars);
    printf("Today's Earnings: Rs.%.2f\n", today_earnings);
    printf("Total Earnings: Rs.%.2f\n", total_earnings);
}

// Additional function to view all cars (parked and exited)
void viewAllCars() {
    char line[200];
    FILE *f = fopen("parking.txt", "r");
    if (!f) { printf("No parking records!\n"); return; }
    
    printf("\nAll Parking Records:\n");
    printf("Ticket ID | Car Number | Slot | Entry Time | Exit Time | Charges | Status\n");
    printf("------------------------------------------------------------------------\n");
    
    while(fgets(line, 200, f)) {
        struct Car car;
        sscanf(line, "%d | %14[^|] | %d | %19[^|] | %19[^|] | %f | %d", 
               &car.ticket_id, car.car_number, &car.slot_number, 
               car.entry_time, car.exit_time, &car.charges, &car.is_parked);
        
        printf("%d | %s | %d | %s | %s | ₹%.2f | %s\n", 
               car.ticket_id, car.car_number, car.slot_number, 
               car.entry_time, car.exit_time, car.charges,
               car.is_parked ? "PARKED" : "EXITED");
    }
    fclose(f);
}

int main() {
    int choice;
    srand(time(0)); // Seed for random ticket IDs
    
    while(1) {
        printf("\nCar Parking System\n");
        printf("1. Park Car\n");
        printf("2. View Parked Cars\n");
        printf("3. View All Cars\n");
        printf("4. Exit Car\n");
        printf("5. Parking Statistics\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: parkCar(); break;
            case 2: viewParkedCars(); break;
            case 3: viewAllCars(); break;
            case 4: exitCar(); break;
            case 5: parkingStats(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}