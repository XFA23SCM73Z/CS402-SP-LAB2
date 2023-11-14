# Employee Database Project

## Overview
This project is a C program for managing an employee database. It allows the user to perform various operations such as adding new employees, searching for employees by ID or last name, and printing the entire database.

## Features
- Load employee data from a file.
- Print out the entire employee database.
- Lookup employee details using their ID.
- Lookup employee details using their last name.
- Add a new employee.
- Update employee.
- Remove employee.
- Print the M of employee with highest salary.
- Find all employees with matching salary.
- Interactive user interface via command-line.

## Prerequisites
- GCC compiler or any standard C compiler.
- Make sure all the project files are in the same directory.


To test the file, 
	1.Open the Terminal in CLion or use an external Terminal application.
	2.Change directory to the project's directory:
	3.Then change directory to the build directory: cd cmake-build-debug
	4.run the executable with the input file like : ./CS402_SP_LAB2 ./input.txt
The program will show the menu choice , then can enter the choice digits to start test.

Sample terminal output:

Successfully opened file './input.txt'

Employee Database Main Menu
1. Print the Database
2. Lookup employee by ID
3. Lookup employee by last name
4. Add an Employee
5. Quit
6. Remove an employee
7. Update an employee's information
8. Print the M employees with the highest salaries
9. Find all employees with matching last name
Enter choice: 1

ID         First Name           Last Name            Salary    
------------------------------------------------------------
165417     Cathryn              Danner               72000     
273225     Matt                 Meeden               69000     
471163     Robert               Dufour               91000     
485913     Dylan                Steinberg            84000     
499959     Mike                 Griffin              72000     
547935     Daniel               McNamee              71000     
553997     Peter                Olsen                82000     
633976     Martine              Marshall             99000     
702234     Jean                 Jones                94000     
784372     Dana                 Parrish              87000     
786785     Ann                  Coddington           82000     
849387     Melissa              Dufour               114000    
935460     Heather              James                98000     
970016     Russ                 Vorobiev             109000    
------------------------------------------------------------

Total number of employees: 14

Employee Database Main Menu
1. Print the Database
2. Lookup employee by ID
3. Lookup employee by last name
4. Add an Employee
5. Quit
6. Remove an employee
7. Update an employee's information
8. Print the M employees with the highest salaries
9. Find all employees with matching last name
Enter choice: 9
Enter the last name to search: James

Employee ID: 935460
First Name: Heather
Last Name: James
Salary: 98000

Employee Database Main Menu
1. Print the Database
2. Lookup employee by ID
3. Lookup employee by last name
4. Add an Employee
5. Quit
6. Remove an employee
7. Update an employee's information
8. Print the M employees with the highest salaries
9. Find all employees with matching last name
Enter choice: 4
Enter new employee ID (6 digits): 123456
Enter new employee's first name: 123
Enter new employee's last name: 123
Enter new employee's salary (30000 - 150000): 30000
New employee added successfully. Total employees: 15

Employee Database Main Menu
1. Print the Database
2. Lookup employee by ID
3. Lookup employee by last name
4. Add an Employee
5. Quit
6. Remove an employee
7. Update an employee's information
8. Print the M employees with the highest salaries
9. Find all employees with matching last name
Enter choice: 7
Enter the ID of the employee to update (or 'back' to return to menu): 123456

Employee ID: 123456
First Name: 123
Last Name: 123
Salary: 30000
Enter updated first name (leave blank to keep unchanged): 321
Enter updated last name (leave blank to keep unchanged): 321
Enter updated salary (leave 0 to keep unchanged): 30001
Employee updated successfully.

Employee Database Main Menu
1. Print the Database
2. Lookup employee by ID
3. Lookup employee by last name
4. Add an Employee
5. Quit
6. Remove an employee
7. Update an employee's information
8. Print the M employees with the highest salaries
9. Find all employees with matching last name
Enter choice: 1

ID         First Name           Last Name            Salary    
------------------------------------------------------------
165417     Cathryn              Danner               72000     
273225     Matt                 Meeden               69000     
471163     Robert               Dufour               91000     
485913     Dylan                Steinberg            84000     
499959     Mike                 Griffin              72000     
547935     Daniel               McNamee              71000     
553997     Peter                Olsen                82000     
633976     Martine              Marshall             99000     
702234     Jean                 Jones                94000     
784372     Dana                 Parrish              87000     
786785     Ann                  Coddington           82000     
849387     Melissa              Dufour               114000    
935460     Heather              James                98000     
970016     Russ                 Vorobiev             109000    
123456     321                  321                  30001     
------------------------------------------------------------

Total number of employees: 15

Employee Database Main Menu
1. Print the Database
2. Lookup employee by ID
3. Lookup employee by last name
4. Add an Employee
5. Quit
6. Remove an employee
7. Update an employee's information
8. Print the M employees with the highest salaries
9. Find all employees with matching last name
Enter choice: 5
Exiting the program.