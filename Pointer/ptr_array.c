
#include <stdio.h>
struct employee
{
    char name[50];
    int employeeID;
    float experience;
};
int main()
{
    struct employee emp;
    struct employee *ptr = &emp; // Pointer to the struct employee
    printf("Enter the Name of the employee: ");
    scanf("%s", ptr->name);
    printf("Enter the Employee ID: ");
    scanf("%d", &ptr->employeeID);
    printf("Enter the Experience (in years): ");
    scanf("%f", &ptr->experience);
    printf("\n* * * * * The details of Employee * * * * *\n");
    printf("\nThe Name of employee is: %s", ptr->name);
    printf("\nThe Employee ID is: %d", ptr->employeeID);
    printf("\nThe Experience of employee is: %.1f years", ptr->experience);
    return 0;
}
