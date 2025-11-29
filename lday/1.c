#include<stdio.h>
struct student {
    int id;
    char name[50];
    char branch[50];
    int sem;
   char section;
}s1 ,s2;
int main() 
{
    // Assigning values to the first student structure
    s1.id = 101;
    snprintf(s1.name, sizeof(s1.name), "Samarth");
    snprintf(s1.branch, sizeof(s1.branch), "Computer Science");
    s1.sem = 1;
    s1.section = 'C';
    // Assigning values to the second student structure
    s2.id = 102;
    snprintf(s2.name, sizeof(s2.name), "Nikhil");
    snprintf(s2.branch, sizeof(s2.branch), "Mechanical Engineering");
    s2.sem = 2;
    s2.section = 'F';
    // Printing details of the first student
    printf("Student 1 Details:\n");
    printf("ID: %d\n", s1.id);
    printf("Name: %s\n", s1.name);
    printf("Branch: %s\n", s1.branch);
    printf("Semester: %d\n", s1.sem);
    printf("Section: %c\n\n", s1.section);
    // Printing details of the second student
    printf("Student 2 Details:\n");
    printf("ID: %d\n", s2.id);
    printf("Name: %s\n", s2.name);
    printf("Branch: %s\n", s2.branch);
    printf("Semester: %d\n", s2.sem);
    printf("Section: %c\n", s2.section);
    return 0;
}