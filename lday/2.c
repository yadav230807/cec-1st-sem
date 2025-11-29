#include<stdio.h>

#include<string.h>
struct employee
{
    int emp_id;
    char emp_name[50];
    char department[50];
    float emp_salary;
    float exp;
    char location [50];
    

};void main()
{
   struct employee e1, e2, emp[2];
   int id;
    char empname[50];
    // char empemail[50]; // Removed unused variable
    char dept[50];
    float exp;
    char emploc[50];

    for(int i=0; i<2; i++)
    {
        printf(" enter the details of employee %d:\n", i+1);
        printf("Enter Employee ID: ");
        scanf("%d", &emp[i].emp_id);
        getchar();
        printf("Enter Employee Name: ");
        fgets(emp[i].emp_name, sizeof(emp[i].emp_name), stdin);
        printf("Enter Employee Department: ");      
        fgets(emp[i].department, sizeof(emp[i].department), stdin);
        printf("Enter Employee Experience: ");                             
        scanf("%f", &emp[i].exp);
        getchar();
        printf("Enter Employee Location: ");    
        fgets(emp[i].location, sizeof(emp[i].location), stdin);            
        if(i==0)
        {
            e1.emp_id = emp[i].emp_id;
            strcpy(e1.emp_name, emp[i].emp_name);
            strcpy(e1.department, emp[i].department);
            e1.exp = emp[i].exp;
            strcpy(e1.location, emp[i].location);
        }
        else
        {
            e2.emp_id = emp[i].emp_id;
            strcpy(e2.emp_name, emp[i].emp_name);
            strcpy(e2.department, emp[i].department);
            e2.exp = emp[i].exp;
            strcpy(e2.location, emp[i].location); 
        }               

    }
    printf(" employee 1 details:\n");       


    printf(" Employee ID:%d\n",e1.emp_id);          
    printf(" Employee Name:%s\n",e1.emp_name);
    printf(" Employee Department:%s\n",e1.department);
    printf(" Employee Experience:%.2f\n",e1.exp);





    printf(" Employee Location:%s\n",e1.location);
    printf(" employee 2 details:\n");       

    printf(" Employee ID:%d\n",e2.emp_id);

    printf(" Employee Name:%s\n",e2.emp_name);
    printf(" Employee Department:%s\n",e2.department);
    printf(" Employee Experience:%.2f\n",e2.exp);
    printf(" Employee Location:%s\n",e2.location);
}


