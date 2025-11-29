#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    float grade;
} Student;

void addStudent();
void viewStudents();
void clearInputBuffer();

int main() {
    int choice;
    
    while(1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addStudent() {
    Student s;
    FILE *fp = fopen("students.txt", "a");
    
    printf("\nEnter Student Details:\n");
    
    printf("ID: ");
    scanf("%d", &s.id);
    clearInputBuffer();
    
    printf("Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove newline
    
    printf("Age: ");
    scanf("%d", &s.age);
    clearInputBuffer();
    
    printf("Grade: ");
    scanf("%f", &s.grade);
    clearInputBuffer();
    
    // Write to text file
    fprintf(fp, "%d,%s,%d,%.2f\n", s.id, s.name, s.age, s.grade);
    fclose(fp);
    
    printf("Student added successfully!\n");
}

void viewStudents() {
    Student s;
    FILE *fp = fopen("students.txt", "r");
    
    if (fp == NULL) {
        printf("No student records found!\n");
        return;
    }
    
    printf("\nStudent List:\n");
    printf("ID\tName\t\tAge\tGrade\n");
    printf("---------------------------------------\n");
    
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        // Parse the CSV line
        sscanf(line, "%d,%49[^,],%d,%f", &s.id, s.name, &s.age, &s.grade);
        printf("%d\t%s\t%d\t%.2f\n", s.id, s.name, s.age, s.grade);
    }
    
    fclose(fp);
}