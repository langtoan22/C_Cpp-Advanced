/*
* File: 2_Customer.cpp
* Author: Lang Van Toan
* Date: 23/07/2023
* Description: This file contains all the functions/methods to customer management   
*/

#include "Customer.h"

/*
* Class: Customer
*Contructor: Customer
*Discription: This Function initializes a new instance of the customer class
*Input:
*    name: Name of customer
*    phoneNumber: Number of customer
*    address: address of customer
*/
Customer :: Customer(string cusName, string cusPhone, string cusAddress){
        name = cusName;
        phoneNumber = cusPhone;
        address = cusAddress;
}

/*
* Class: Customer
*Function: setName
*Discription: This Function for set name of customer
*Input: cusName
* Output:
*   return: None
*/
void Customer :: setName(string cusName){
    name = cusName;
}

/*
* Class: Customer
*Function: setPhoneNumber
*Discription: This Function for set phone number of customer
*Input: cusPhone
* Output:
*   return: None
*/
void Customer :: setPhoneNumber(string cusPhone){
    phoneNumber = cusPhone;
}

/*
* Class: Customer
*Function: setAddress
*Discription: This Function for set address of customer
*Input: cusAddress
* Output:
*   return: None
*/
void Customer :: setAddress(string cusAddress){
    address = cusAddress;
}

/*
* Class: Customer
*Function: getAddress
*Discription: This Function for get address of customer
*Input: None
* Output:
*   return: adress of customer
*/
string Customer :: getAddress(){
    return address;
}

/*
* Class: Customer
*Function: getPhoneNumber
*Discription: This Function for get phone number of customer
*Input: None
* Output:
*   return: phone number of customer
*/
string Customer :: getPhoneNumber(){
    return phoneNumber;
}

/*
* Class: Customer
*Function: getName
*Discription: This Function for get name of customer
*Input: None
* Output:
*   return: name of customer
*/
string Customer :: getName() {
    return name;
}

/*
* Class: Customer
*Function: addBookHistory
*Discription: This Function for add book history of customer
*Input: bookDetails
* Output:
*   return: None
*/
void Customer :: addBookHistory(bookHistory bookDetails) {
    History. push_back(bookDetails);
}

/*
* Class: Customer
*Function: displayBoolHistory
*Discription: This Function for display book history of customer
*Input: None
* Output:
*   return: book history
*/
void Customer ::  displayBoolHistory(){
    cout << "Booking history for customer " << name << ":" << endl;
    for (int i = 0; i < History.size(); i++) {
        cout << "Date: " << History[i].date.Day << "/" << History[i].date.Month << "/" << History[i].date.Year
            << ", Time: " << History[i].time.hour << ":" << History[i].time.minute << ":" << History[i].time.second
            << ", Status: ";
        if (History[i].status == IN) {
            cout << "IN";
        } else if (History[i].status == OUT) {
            cout << "OUT";
        }
        cout << endl;
    }
}

/*
* Class: Customer
*Function: getInformation
*Discription: This Function for display information of customer
*Input: None
* Output:
*   return: information of customer
*/
void Customer :: getInformation(){
    cout << "Name customer: " << getName() << endl;
    cout << "Phone number customer: " << getPhoneNumber() << endl;
    cout << "Address customer: " << getAddress() << endl;
}

/*
* Class: CustomerManagement
*Function: addCustomer
*Discription: This Function for add a new customer
*Input: 
*  customer
* Output:
*   return: None
*/
void CustomerManagement :: addCustomer() {
    string cusName;
    string cusPhone;
    string cusAddress;

    Customer customer1(cusName, cusPhone, cusAddress );
    customerList.push_back(customer1);
}

/*
* Class: CustomerManagement
*Function: updateCustomer
*Discription: This Function for update information off customer
*Input: None
* Output:
*   return: None
*/
void CustomerManagement::updateCustomer() {
    string cusName, cusPhone, cusAddress;
    cout << "Enter name you need to update: ";
    cin >> cusName;
    for (Customer& customer : customerList) {
        if (customer.getName() == cusName) {
            customer.setPhoneNumber(cusPhone);
            customer.setAddress(cusAddress);
            return;
        }
    }
}

/*
* Class: CustomerManagement
*Function: removeCustomer
*Discription: This Function for remove a customer
*Input: None
* Output:
*   return: None
*/
void CustomerManagement::removeCustomer() {
    string name;
    auto it = customerList.begin();
    for(it = customerList.begin(); it != customerList.end(); ++it){
        if (it->getName() == name) {
            it = customerList.erase(it);
            return;
        }
    }
}

/*
* Class: CustomerManagement
*Function: displayCustomerInfor
*Discription: This Function for display list customer
*Input: None
* Output:
*   return: list customer
*/
void CustomerManagement :: displayCustomerInfor(){
    cout << "Information of customer list: " << endl;
    for(auto it : customerList){
        it.getInformation();
    }
}

/*
* Class: CustomerManagement
*Function: CustomerMenu
*Discription: This Function for display list menu to management customer
*Input: None
* Output:
*   return: list customer
*/
void CustomerManagement :: CustomerMenu(){
    int choice;
    do{
    cout << "Enter your choice\n";
    cout << "1. add new customer\n";
    cout << "2. update customer\n";
    cout << "3. delete customer\n";
    cout << "4. diplay customer information\n";
    cout << "0. return option\n";

    do{
        cin>> choice;
        if(choice < 0 || choice >  4){
            cout << "Invalid choice please re -enter\n";
        }
    }while(choice < 0 || choice >  4);
        switch (choice)
        {
        case 1: addCustomer();
            break;
        case 2: updateCustomer();
            break;
        case 3: removeCustomer();
            break;
        case 4: displayCustomerInfor();
            break;
        case 0: 
            return;
        default:
            break;
        }
    }while(true);

}