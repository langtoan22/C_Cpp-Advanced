/*
* File: Customer.h
* Author: Lang Van Toan
* Date: 23/07/2023
* Description: This file is a Customer header file that for program hotel management 
*/

#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include <iostream>
#include <vector>

using namespace std;

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
#endif