#include <stdio.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 5

int main(int argc, char *argv[])
{
	Employee employees[MAX_EMPLOYEES];
	for(int i = 0; i < MAX_EMPLOYEES; i++) {
		printf("Name: ");
		scanf("%s", employees[i].name);
		printf("Salary: ");
		scanf("%d", &employees[i].salary);
		printf("\n");
	}
	heapSort(employees, MAX_EMPLOYEES);
	printList(employees, MAX_EMPLOYEES);
	return 0;
}
