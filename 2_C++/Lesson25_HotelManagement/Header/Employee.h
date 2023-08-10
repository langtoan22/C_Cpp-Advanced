/*
* File: Employee.h
* Author: Lang Van Toan
* Date: 23/07/2023
* Description: This file is a employee header file that for program hotel management 
*/

#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <iostream>
#include <vector>
using namespace std;

typedef enum{
    RECEPTIONIST,
    LAUDRY_STAFF,
    LAUGGAGE_STAFF
}jobPosition;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int hour;
    int second;
    int minute;
} Time;

typedef enum{
    IN,
    OUT
}Status;

typedef struct{
    Date date;
    Time time;
    Status status;
}Schedule;

/*
*Class: Employee
*Description: This class represents the basic properties and methods of a Employee object
*/
class Employee {
private:
    string Name;
    string phoneNumber;
    jobPosition Position;
    vector <Schedule> WorkSchedule;

public:
    Employee(string EmployeeName, string EmplyeePhoneNumber, jobPosition EmployeePosition);
    void setName(string EmployeeName);
    string getName();
    void setPhoneNumber(string EmplyeePhoneNumber);
    string getPhoneNumber();
    void setJobPosition(jobPosition EmployeePosition);
    string getJobPosition();
    void addWorkSchedule(Date date, Time time, Status status);
    void displayWorkSchedule();
};

/*
*Class: EmployeeManagement
*Description: This class represents the employee management
*/
class EmployeeManagement {
private:
    vector<Employee> EmployeeList;

public:
    void addEmployee(Employee employee);
    void updateEmployee(string EmployeeName, string EmplyeePhoneNumber, jobPosition EmployeePosition);
    void removeEmployee(string name);
};

#endif