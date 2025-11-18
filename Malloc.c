#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n = 5;
    struct Employee *emp;
    float sum = 0.0 ;

    // Allocate memory for 5 employees
    emp = (struct Employee *)malloc(n * sizeof(struct Employee));
    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input employee details
    for (int i = 0; i < n; i++) {
        printf("Enter details of employee %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);

        sum += emp[i].salary;
    }

    // Calculate average salary
    
    printf("\n Total Salary of %d employees = %.2f\n",n, sum);

    // Free allocated memory
    free(emp);

    return 0;
}
