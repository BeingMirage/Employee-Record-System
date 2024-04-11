/*Employee record system
A project by :
Amey Ghatol 2314110016
Vansh Desai 2314110009
Simar Ahluwalia 231411004
Samriddhi Gupta 231400018

Under the guidance of :
Dr. Nisha Auti
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//limits of record storage
#define MAX_NAME_LENGTH 50
#define MAX_DEPARTMENT_LENGTH 50
#define MAX_DESIGNATION_LENGTH 50

// Define the employee structure
struct employee {
    int id;
    char name[MAX_NAME_LENGTH];
    char department[MAX_DEPARTMENT_LENGTH];
    char designation[MAX_DESIGNATION_LENGTH];
    float salary;
};


struct node {
    struct employee emp;
    struct node *next;
};


struct node *head = NULL;


struct node *createNode(struct employee emp);
void insertNode(struct employee emp);
void removeEmployee();
void modifyEmployee(int id);
void search(int id);
void displayAll();
void displayMenu();


int main() {
    int choice;
    struct employee newEmployee;
    int searchId;
    int removeId;
    int modifyId;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                // Add an employee
                printf("Enter employee ID: ");
                scanf("%d", &newEmployee.id);
                printf("Enter employee name (50 chars): ");
                scanf("%[^\n]s”", newEmployee.name);
                printf("Enter employee department (50 char): ");
                scanf("%s", newEmployee.department);
                printf("Enter employee designation (50 char): ");
                scanf("%s", newEmployee.designation);
                printf("Enter employee salary: ");
                scanf("%f", &newEmployee.salary);
                insertNode(newEmployee);
                break;
            case 2:
                // Search for an employee
                printf("Enter the employee ID to search: ");
                scanf("%d", &searchId);
                search(searchId);
                break;
            case 3:
                // Remove recently added employee
                removeEmployee(removeId);
                break;
            case 4:
                // Modify a record
                printf("Enter the employee ID to modify: ");
                scanf("%d", &modifyId);
                modifyEmployee(modifyId);
                break;
            case 5:
                // View all records
                displayAll();
                break;
            case 6:
                // Exit the program
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (1);


    return 0;
}


// Function to create a new node
struct node *createNode(struct employee emp) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->emp = emp;
    new_node->next = NULL;
    return new_node;
}


// Function to insert a new node into the linked list
void insertNode(struct employee emp) {
    struct node *new_node = createNode(emp);
    if (head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
}


// Function to search for an employee by ID
void search(int id) {
    struct node *ptr = head;
    while (ptr != NULL) {
        if (ptr->emp.id == id) {
            printf("Employee found:\n");
            printf("ID: %d\n", ptr->emp.id);
            printf("Name: %s\n", ptr->emp.name);
            printf("Department: %s\n", ptr->emp.department);
            printf("Designation: %s\n", ptr->emp.designation);
            printf("Salary: %.2f\n", ptr->emp.salary);
            return;
        }
        ptr = ptr->next;
    }
    printf("Employee with ID %d not found.\n", id);
}


// Function to remove an employee by ID
/*Implementing STACK by deleting the most recently added data to the list 
taking head as top pointer*/
void removeEmployee() {
    struct node *current = head;
    struct node *previous = NULL;
     head=head->next;
     free(current);
}


// Function to modify an employee record by ID
void modifyEmployee(int id) {
    struct node *ptr = head;
    while (ptr != NULL) {
        if (ptr->emp.id == id) {
            printf("Enter new employee name: ");
            scanf("%s", ptr->emp.name);
            printf("Enter new employee department: ");
            scanf("%s", ptr->emp.department);
            printf("Enter new employee designation: ");
            scanf("%s", ptr->emp.designation);
            printf("Enter new employee salary: ");
            scanf("%f", &ptr->emp.salary);
            printf("Employee record with ID %d modified successfully.\n", id);
            return;
        }
        ptr = ptr->next;
    }
    printf("Employee with ID %d not found.\n", id);
}


// Function to display all employee records
void displayAll() {
    struct node *ptr = head;
    if (ptr == NULL) {
        printf("No employee records found.\n");
        return;
    }
    printf("Employee Records:\n");
    while (ptr != NULL) {
        printf("ID: %d\n", ptr->emp.id);
        printf("Name: %s\n", ptr->emp.name);
        printf("Department: %s\n", ptr->emp.department);
        printf("Designation: %s\n", ptr->emp.designation);
        printf("Salary: %.2f\n\n", ptr->emp.salary);
        ptr = ptr->next;
    }
}


// Function to display the menu options
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add an employee\n");
    printf("2. Search for an employee\n");
    printf("3. Remove the recently added employee\n");
    printf("4. Modify a record\n");
    printf("5. View all records\n");
    printf("6. Exit\n");
}
