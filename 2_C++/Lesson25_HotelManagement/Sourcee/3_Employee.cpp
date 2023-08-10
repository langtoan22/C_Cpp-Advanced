/*
* File: 3_Employee.cpp
* Author: Lang Van Toan
* Date: 23/07/2023
* Description: This file contains all the functions/methods to employee management  
*/

#include "Employee.h"


/*
* Class: Employee
*Contructor: Employee
*Discription: This Function initializes a new instance of the Employee class
*Input:
*    EmployeeName: Name of Employee
*    EmplyeePhoneNumber: phone Number of Employee
*    EmployeePosition: position of Employee
*/
Employee::Employee(string EmployeeName, string EmplyeePhoneNumber, jobPosition EmployeePosition) {
    Name = EmployeeName;
    phoneNumber = EmplyeePhoneNumber;
    Position = EmployeePosition;
    
}

/*
* Class: Employee
*Function: setName
*Discription: This Function for set name of employee
*Input:
*EmployeeName : name of employee
* Output:
*   return: None
*/
void Employee::setName(string EmployeeName) {
    Name = EmployeeName;
}

/*
* Class: Employee
*Function: getName
*Discription: This Function get name of employee
*Input: None
* Output:
*   return: name of employee
*/
string Employee::getName() {
    return  Name;
}

/*
* Class: Employee
*Function: setPhoneNumber
*Discription: This Function set phone number of employee
*Input:
* EmplyeePhoneNumber : phone number of employee
* Output:
*   return: None
*/
void Employee::setPhoneNumber(string EmplyeePhoneNumber) {
    phoneNumber = EmplyeePhoneNumber;
}

/*
* Class: Employee
*Function: getPhoneNumber
*Discription: This Function get phone number of employee
*Input: None
* Output:
*   return: phoneNumber
*/
string Employee::getPhoneNumber() {
    return phoneNumber;
}

/*
* Class: Employee
*Function: setJobPosition
*Discription: This Function set job positsion of employee
*Input: 
* EmployeePosition : position of employee
* Output:
*   return: None
*/
void Employee::setJobPosition(jobPosition EmployeePosition) {
    Position = EmployeePosition;
}

/*
* Class: Employee
*Function: getJobPosition
*Discription: This Function get job positsion of employee
*Input: 
* None
* Output:
*   return: job positsion of employee
*/
string Employee::getJobPosition() {
    switch (Position) {
        case RECEPTIONIST:
            return "Receptionist";
        case LAUDRY_STAFF:
            return "Laundry Staff";
        case LAUGGAGE_STAFF:
            return "Luggage Staff";
        default:
            return "Unknown";
    }
}

/*
* Class: Employee
*Function: addWorkSchedule
*Discription: This Function add work schedule of employee
*Input: 
* date: date work schedule of employee
* time: time work schedule of employee
* status: status work schedule of employee
* Output:
*   return: None
*/
void Employee::addWorkSchedule(Date date, Time time, Status status) {
    
    Schedule schedule = {date, time, status};
    WorkSchedule.push_back(schedule);
}

/*
* Class: Employee
*Function: displayWorkSchedule
*Discription: This Function display work schedule of employee
*Input: 
* None
* Output:
*   return: display work schedule
*/
void Employee::displayWorkSchedule() {
    cout << "Work schedule for employee " <<Name << ":" << endl;
    for (auto schedule : WorkSchedule) {
        cout << "Date: " << schedule.date.day << "/" << schedule.date.month << "/" << schedule.date.year
             << ", Time: " << schedule.time.hour << ":" << schedule.time.minute << schedule.time.second << endl;
        if (schedule.status == IN) {
            cout << ", Status: IN" << endl;
        } else if (schedule.status == OUT) {
            cout << ", Status: OUT" << endl;
        } else {
            cout << ", Status: Unknown" << endl;
        }
    }
}

/*
* Class: EmployeeManagement
*Function: addEmployee
*Discription: This Function add a new employee
*Input: 
* employee : employee
* Output:
*   return: None
*/
void EmployeeManagement::addEmployee(Employee employee) {
    EmployeeList.push_back(employee);
}


/*
* Class: EmployeeManagement
*Function: updateEmployee
*Discription: This Function update information off employee
*Input: 
* EmployeeName
* EmplyeePhoneNumber
* EmployeePosition
* Output:
*   return: None
*/
void EmployeeManagement::updateEmployee(string EmployeeName, string EmplyeePhoneNumber, jobPosition EmployeePosition) {
    for (auto& employee : EmployeeList) {
        if (employee.getName() == EmployeeName) {
            employee.setPhoneNumber(EmplyeePhoneNumber);
            employee.setJobPosition(EmployeePosition);
            return;
        }
    }
}

/*
* Class: EmployeeManagement
*Function: removeEmployee
*Discription: This Function remove a employee
*Input: 
* None
* Output:
*   return: None
*/
void EmployeeManagement::removeEmployee(string EmployeeName) {
   
    for(auto it = EmployeeList.begin(); it != EmployeeList .end(); ++it){
        if(it->getName() == EmployeeName){
            it = EmployeeList.erase(it);
        }
    }
}