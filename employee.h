//
// Created by sue on 11/14/23.
//

#ifndef CS402_SP_LAB2_EMPLOYEE_H
#define CS402_SP_LAB2_EMPLOYEE_H
#define MAX_NAME 64

typedef struct {
    int id;
    char first_name[MAX_NAME];
    char last_name[MAX_NAME];
    int salary;
} Employee;

void printEmployee(const Employee *emp);

#endif //CS402_SP_LAB2_EMPLOYEE_H
