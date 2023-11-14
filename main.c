#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "readfile.h"
#include <string.h>
#define MAX_EMPLOYEES 1024

void printDatabase(Employee employees[], int count) {
    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "First Name", "Last Name", "Salary");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < count; ++i) {
        printf("%-10d %-20s %-20s %-10d\n",
               employees[i].id,
               employees[i].first_name,
               employees[i].last_name,
               employees[i].salary);
    }
    printf("------------------------------------------------------------\n");
    printf("\nTotal number of employees: %d\n", count);

}
int lookupByID(Employee employees[], int count, int id) {
    for (int i = 0; i < count; ++i) {
        if (employees[i].id == id) {
            printEmployee(&employees[i]);
            return i;
        }
    }
    return -1; // Not found
}
int lookupByLastName(Employee employees[], int count, char *lastName) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(employees[i].last_name, lastName) == 0) {
            printEmployee(&employees[i]);
            return i;
        }
    }
    return -1; // Not found
}
void addEmployee(Employee employees[], int *count) {
    // Check if the database is full
    if (*count >= MAX_EMPLOYEES) {
        printf("Error: Database is full.\n");
        return;
    }
    char buffer[50];
    Employee newEmployee;

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    // Prompt for ID
    printf("Enter new employee ID (6 digits): ");
    fgets(buffer, 50, stdin);
    if (sscanf(buffer, "%d", &newEmployee.id) != 1 || newEmployee.id < 100000 || newEmployee.id > 999999) {
        printf("Error: Invalid ID. Must be a six-digit number.\n");
        return;
    }

    if (newEmployee.id < 100000 || newEmployee.id > 999999) {
        printf("Error: Invalid ID. Must be a six-digit number.\n");
        return;
    }

    // Prompt for first name
    printf("Enter new employee's first name: ");
    scanf("%63s", newEmployee.first_name);
    while (getchar() != '\n');  // Clear the input buffer

    // Prompt for last name
    printf("Enter new employee's last name: ");
    scanf("%63s", newEmployee.last_name);
    while (getchar() != '\n');  // Clear the input buffer

    // Prompt for salary
    printf("Enter new employee's salary (30000 - 150000): ");
    scanf("%d", &newEmployee.salary);
    while (getchar() != '\n');  // Clear the input buffer

    if (newEmployee.salary < 30000 || newEmployee.salary > 150000) {
        printf("Error: Invalid salary. Must be between $30,000 and $150,000.\n");
        return;
    }

    // Once all fields are entered and validated:
    employees[*count] = newEmployee;  // Add the new employee to the array
    (*count)++;                       // Increment the employee count

    printf("New employee added successfully. Total employees: %d\n", *count);
}

void removeEmployee(Employee employees[], int *count) {
    int id, index;
    char buffer[50];
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("Enter the ID of the employee to remove: ");
    scanf("%d", &id);

    index = lookupByID(employees, *count, id);
    if (index == -1) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }

    // Confirmation before deletion
    char confirm;
    printf("Are you sure you want to remove this employee? (y/n): ");
    scanf(" %c", &confirm); // Notice the space before %c to consume any leftover newline characters
    if (confirm != 'y' && confirm != 'Y') {
        printf("Employee removal cancelled.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        employees[i] = employees[i + 1];
    }

    (*count)--; // Decrement the employee count
    printf("Employee removed successfully. Total employees: %d\n", *count);
}

//void updateEmployee(Employee employees[], int count) {
//    char input[50];
//    int id, index;
//
//    // Clear the stdin buffer
//    int c;
//    while ((c = getchar()) != '\n' && c != EOF) { }
//
//    printf("Enter the ID of the employee to update (or 'back' to return to menu): ");
//    fgets(input, 50, stdin); // Read the input as a string
//
//    // Check for 'back' command
//    if (strncmp(input, "back\n", 5) == 0) {
//        return; // Return to the main menu
//    }
//
//    // Check if the input is a valid integer
//    if (sscanf(input, "%d", &id) != 1) {
//        printf("Invalid input. Please enter a valid ID.\n");
//        return;
//    }
//
//    index = lookupByID(employees, count, id);
//    if (index == -1) {
//        printf("Employee with ID %d not found.\n", id);
//        return;
//    }
//
//    printf("Enter updated first name (leave blank to keep unchanged): ");
//    char firstName[MAX_NAME];
//    fgets(firstName, MAX_NAME, stdin);
//    if (strlen(firstName) > 1) { // Check if input is not just a newline
//        strncpy(employees[index].first_name, firstName, MAX_NAME - 1);
//        employees[index].first_name[strcspn(employees[index].first_name, "\n")] = 0; // Remove newline
//    }
//
//    printf("Enter updated last name (leave blank to keep unchanged): ");
//    char lastName[MAX_NAME];
//    fgets(lastName, MAX_NAME, stdin);
//    if (strlen(lastName) > 1) {
//        strncpy(employees[index].last_name, lastName, MAX_NAME - 1);
//        employees[index].last_name[strcspn(employees[index].last_name, "\n")] = 0; // Remove newline
//    }
//
//    printf("Enter updated salary (leave 0 to keep unchanged): ");
//    int salary;
//    scanf("%d", &salary);
//    if (salary > 0) {
//        employees[index].salary = salary;
//    }
//    printf("Employee updated successfully.\n");
//}

void updateEmployee(Employee employees[], int count) {
    char input[50];
    int id, index;
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    printf("Enter the ID of the employee to update (or 'back' to return to menu): ");
    fgets(input, 50, stdin); // Read the input as a string

    if (strncmp(input, "back\n", 5) == 0) {
        return; // Return to the main menu
    }

    // Check if the input is a valid integer
    if (sscanf(input, "%d", &id) != 1) {
        printf("Invalid input. Please enter a valid ID.\n");
        return;
    }

    index = lookupByID(employees, count, id);
    if (index == -1) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }

    // Updating first name
    printf("Enter updated first name (leave blank to keep unchanged): ");
    fgets(input, MAX_NAME, stdin);
    if (strlen(input) > 1) { // Check if input is not just a newline
        input[strcspn(input, "\n")] = 0; // Remove newline
        strncpy(employees[index].first_name, input, MAX_NAME);
    }

    // Updating last name
    printf("Enter updated last name (leave blank to keep unchanged): ");
    fgets(input, MAX_NAME, stdin);
    if (strlen(input) > 1) {
        input[strcspn(input, "\n")] = 0; // Remove newline
        strncpy(employees[index].last_name, input, MAX_NAME);
    }

    // Updating salary
    printf("Enter updated salary (leave 0 to keep unchanged): ");
    int salary;
    fgets(input, 50, stdin);
    if (sscanf(input, "%d", &salary) == 1 && salary > 0) {
        employees[index].salary = salary;
    }

    printf("Employee updated successfully.\n");
}

int compareSalaries(const void *a, const void *b) {
    Employee *employeeA = (Employee *)a;
    Employee *employeeB = (Employee *)b;
    return employeeB->salary - employeeA->salary; // For descending order
}

void printTopSalaries(Employee employees[], int count) {
    Employee sortedEmployees[MAX_EMPLOYEES];
    memcpy(sortedEmployees, employees, count * sizeof(Employee));

    qsort(sortedEmployees, count, sizeof(Employee), compareSalaries);

    int m;
    printf("Enter the number of top salaries to print: ");
    scanf("%d", &m);
    if (m > count) {
        m = count;
    }

    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "First Name", "Last Name", "Salary");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < m; ++i) {
        printf("%-10d %-20s %-20s %-10d\n",
               sortedEmployees[i].id,
               sortedEmployees[i].first_name,
               sortedEmployees[i].last_name,
               sortedEmployees[i].salary);
    }
    printf("------------------------------------------------------------\n");
}

void findAllWithLastName(Employee employees[], int count) {
    char lastName[MAX_NAME];
    printf("Enter the last name to search: ");
    scanf("%63s", lastName); // Assuming last names are less than 64 characters

    int found = 0;
    for (int i = 0; i < count; ++i) {
        if (strcasecmp(employees[i].last_name, lastName) == 0) { // Case-insensitive comparison
            printEmployee(&employees[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No employees found with last name %s.\n", lastName);
    }
}


int compareIDs(const void *a, const void *b) {
    Employee *employeeA = (Employee *)a;
    Employee *employeeB = (Employee *)b;
    return employeeA->id - employeeB->id;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int menuChoice;
    int id;
    char lastName[MAX_NAME];

    // Initialize the file reading library
    if (open_file(argv[1]) != 0) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        return EXIT_FAILURE;
    } else {
        printf("Successfully opened file '%s'\n", argv[1]);

    }

    while (employeeCount < MAX_EMPLOYEES) {
        int readID, readSalary;
        char readFirstName[MAX_NAME], readLastName[MAX_NAME];

        if (read_int(&readID) == 0) {
            fprintf(stderr, "The total employee count is %d\n", employeeCount);
            break;
        }

        if (read_string(readFirstName, MAX_NAME) != 0) {
            //fprintf(stderr, "Error reading first name for employee %d\n", employeeCount + 1);
            break;
        }
        if (read_string(readLastName, MAX_NAME) != 0) {
            //fprintf(stderr, "Error reading last name for employee %d\n", employeeCount + 1);
            break;
        }
        if (read_int(&readSalary) == 0) {
            // fprintf(stderr, "Error reading salary for employee %d\n", employeeCount + 1);
            break;
        }

        employees[employeeCount].id = readID;
        strncpy(employees[employeeCount].first_name, readFirstName, MAX_NAME - 1);
        employees[employeeCount].first_name[MAX_NAME - 1] = '\0'; // Ensure null-termination
        strncpy(employees[employeeCount].last_name, readLastName, MAX_NAME - 1);
        employees[employeeCount].last_name[MAX_NAME - 1] = '\0'; // Ensure null-termination
        employees[employeeCount].salary = readSalary;
        employeeCount++;
    }

    // Close the file as it is no longer needed
    close_file();
    qsort(employees, employeeCount, sizeof(Employee), compareIDs);
    // Main menu loop
    do {
        printf("\nEmployee Database Main Menu\n");
        printf("1. Print the Database\n");
        printf("2. Lookup employee by ID\n");
        printf("3. Lookup employee by last name\n");
        printf("4. Add an Employee\n");
        printf("5. Quit\n");
        printf("6. Remove an employee\n");
        printf("7. Update an employee's information\n");
        printf("8. Print the M employees with the highest salaries\n");
        printf("9. Find all employees with matching last name\n");
        printf("Enter choice: ");
        scanf("%d", &menuChoice);
        if (menuChoice < 1 || menuChoice > 9) {
            printf("Hey, %d is not between 1 and 9, try again...\n", menuChoice);
        } else {
            switch (menuChoice) {
                case 1:
                    printDatabase(employees, employeeCount);
                    break;
                case 2:
                    printf("Enter employee ID: ");
                    scanf("%d", &id);
                    if (lookupByID(employees, employeeCount, id) == -1) {
                        printf("Employee with ID %d not found.\n", id);
                    }
                    break;
                case 3:
                    printf("Enter employee last name: ");
                    scanf("%63s", lastName); // Assuming last names are less than 64 characters
                    if (lookupByLastName(employees, employeeCount, lastName) == -1) {
                        printf("Employee with last name %s not found.\n", lastName);
                    }
                    break;
                case 4:
                    // prompt for each field, validate it, and if validation passes,
                    // add the employee to the array and increment `employeeCount`.
                    addEmployee(employees, &employeeCount);
                    break;
                case 5:
                    printf("Exiting the program.\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
                case 6:
                    removeEmployee(employees, &employeeCount);
                    break;
                case 7:
                    updateEmployee(employees, employeeCount);
                    break;
                case 8:
                    printTopSalaries(employees, employeeCount);
                    break;
                case 9:
                    findAllWithLastName(employees, employeeCount);
                    break;
            }
        }
    } while (menuChoice != 5);

    return EXIT_SUCCESS;
}


