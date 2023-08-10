/*
* File: HotelManagement.cpp
* Author: Lang Van Toan
* Date: 23/07/2023
* Description: This is a HotelManagement header file that contains all the prototypes to hotel management 
*/

#ifndef __HOTELMANAGEMENT_H
#define __HOTELMANAGEMENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
*Class: Room
*Description: This class represents the basic properties and methods of a Room object
*/
class Room {
private:
    int roomNumber;
    bool booked;
    bool cleaning;
public:
    Room(int number);
    int getRoomNumber();
    bool available();
    void bookRoom();
    void checkIn();
    void checkOut();
};

void roommanager();


typedef struct {
    int Day;
    int Month;
    int Year;
}Date;

typedef struct {
    int second;
    int minute;
    int hour;
}Time;

typedef enum{
    IN,
    OUT
}Status;

typedef struct {
    Date date;
    Time time;
    Status status;
}bookHistory;

/*
*Class: Customer
*Description: This class represents the basic properties and methods of a Customer object
*/
class Customer {
    private:
        int idRoom;
        string name;
        string phoneNumber;
        string address;
        vector<bookHistory>History;
    public:
        Customer(string cusName, string cusPhone, string cusAddress);
        void setName(string cusName);
        string getName();
        void setPhoneNumber(string cusPhone);
        string getPhoneNumber();
        void setAddress(string cusAddress);
        string getAddress();
        void addBookHistory(bookHistory bookDetails);
        void displayBoolHistory();
        void getInformation();
};

/*
*Class: CustomerManagement
*Description: This class represents the customer management
*/
class CustomerManagement {
private:
    vector<Customer> customerList;

public:

    void addCustomer();
    void updateCustomer();
    void removeCustomer();
    void displayCustomerInfor();
    void CustomerMenu();
};


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
