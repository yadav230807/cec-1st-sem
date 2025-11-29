#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char department[30];
    float salary;
    int age;
};

void addEmployee() {
    struct Employee emp;
    FILE *f = fopen("employees.txt", "a");
    printf("Employee ID: "); scanf("%d", &emp.id); getchar();
    printf("Name: "); fgets(emp.name, 50, stdin); emp.name[strcspn(emp.name, "\n")] = 0;
    printf("Department: "); fgets(emp.department, 30, stdin); emp.department[strcspn(emp.department, "\n")] = 0;
    printf("Salary: "); scanf("%f", &emp.salary);
    printf("Age: "); scanf("%d", &emp.age);
    fprintf(f, "%d | %s | %s | %.2f | %d\n", emp.id, emp.name, emp.department, emp.salary, emp.age);
    fclose(f);
    printf("Employee added!\n");
}

void viewEmployees() {
    char line[200];
    FILE *f = fopen("employees.txt", "r");
    if (!f) { printf("No employees!\n"); return; }
    printf("\nID | Name | Department | Salary | Age\n");
    while(fgets(line, 200, f)) printf("%s", line);
    fclose(f);
}

void employeeStats() {
    FILE *f = fopen("employees.txt", "r");
    if (!f) { printf("No employees!\n"); return; }
    
    char line[200];
    int count = 0, total_age = 0;
    float total_salary = 0, max_salary = 0, min_salary = 1e9;
    int dept_count[5] = {0}; // IT, HR, Sales, Finance, Other
    int age_groups[4] = {0}; // <25, 25-35, 36-50, >50
    
    while(fgets(line, 200, f)) {
        struct Employee emp;
        sscanf(line, "%d | %49[^|] | %29[^|] | %f | %d", 
               &emp.id, emp.name, emp.department, &emp.salary, &emp.age);
        
        count++;
        total_salary += emp.salary;
        total_age += emp.age;
        
        if(emp.salary > max_salary) max_salary = emp.salary;
        if(emp.salary < min_salary) min_salary = emp.salary;
        
        // Department count
        if(strstr(emp.department, "IT")) dept_count[0]++;
        else if(strstr(emp.department, "HR")) dept_count[1]++;
        else if(strstr(emp.department, "Sales")) dept_count[2]++;
        else if(strstr(emp.department, "Finance")) dept_count[3]++;
        else dept_count[4]++;
        
        // Age groups
        if(emp.age < 25) age_groups[0]++;
        else if(emp.age <= 35) age_groups[1]++;
        else if(emp.age <= 50) age_groups[2]++;
        else age_groups[3]++;
    }
    fclose(f);
    
    printf("\n=== EMPLOYEE STATISTICS ===\n");
    printf("Total Employees: %d\n", count);
    printf("Average Salary: $%.2f\n", total_salary/count);
    printf("Average Age: %.1f years\n", (float)total_age/count);
    printf("Highest Salary: $%.2f\n", max_salary);
    printf("Lowest Salary: $%.2f\n", min_salary);
    
    printf("\nDepartment Distribution:\n");
    printf("IT: %d employees\n", dept_count[0]);
    printf("HR: %d employees\n", dept_count[1]);
    printf("Sales: %d employees\n", dept_count[2]);
    printf("Finance: %d employees\n", dept_count[3]);
    printf("Other: %d employees\n", dept_count[4]);
    
    printf("\nAge Group Distribution:\n");
    printf("Under 25: %d employees\n", age_groups[0]);
    printf("25-35: %d employees\n", age_groups[1]);
    printf("36-50: %d employees\n", age_groups[2]);
    printf("Over 50: %d employees\n", age_groups[3]);
}

int main() {
    int choice;
    while(1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Employee Statistics\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: employeeStats(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}