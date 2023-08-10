/*
* File: HotelManagement.cpp
* Author: Lang Van Toan
* Date: 23/07/2023
* Description: This file contains all the functions/methods to hotel management 
*/

#include "HotelManagement.h"

/*
* Class: Room
*Contructor: Room
*Discription: This constructor initializes a new instance of the Room class
*Input:
*    roomNumber: number of room
*    booked: book room
*    cleaning: cleaning room
*/ 
Room :: Room(int number) {
    roomNumber = number;
    booked = false;
    cleaning = false;
} 

/*
* Class: Room
* Function: getRoomNumber
* Description: This function use for get room number of hotel
* Input:
*   Room:
* Output:
*   return: room number
*/
int Room :: getRoomNumber() {
    return roomNumber;
}

/*
* Class: Room
* Function:available
* Description: This function use for get available of hotel
* Input: None 
* Output:
*   return: status of room
*/
 bool Room :: available(){
    return !booked && !cleaning;
 }

 /*
* Class: Room
* Function: bookRoom
* Description: This function use for get status book room of hotel
* Input: None
* Output:
*   return: status booked room
*/
void Room :: bookRoom() {
        booked = true;
    }

 /*
* Class: Room
* Function: checkIn
* Description: This function use for get checkIn of hotel
* Input: None
* Output:
*   return: status check in
*/
void Room :: checkIn() {
    booked = true;
    cleaning = false;
}

 /*
* Class: Room
* Function: checkOut
* Description: This function use for get checkOut of hotel
* Input: None
* Output:
*   return: status check out
*/
void Room :: checkOut() {
    booked = false;
    cleaning = true;
}

 /*
* Function: roommanager
* Description: This function use for room manager of hotel
* Input: Room
* Output:
*   return: information of room 
*/
void roommanager(){
    vector <Room> rooms;
    rooms.push_back(Room(101));
    rooms.push_back(Room(102));
    rooms.push_back(Room(103));
    rooms.push_back(Room(201));
    rooms.push_back(Room(202));
    rooms.push_back(Room(203));

    cout << "List of rooms in the hotel: " << endl;
    for (Room room : rooms) {
        cout << "Room " << room.getRoomNumber() << endl;
    }

    // Yêu cầu người dùng nhập số phòng để xem trạng thái
    int roomNumber;
    cout << "Enter room number to check status: ";
    cin >> roomNumber;

    // Tìm phòng theo số phòng nhập vào
    for (Room room : rooms) {
        if (room.getRoomNumber() == roomNumber) {
            if (room.available()) {
                cout << "Room " << roomNumber << " is available." << endl;
            } else {
                cout << "Room " << roomNumber << " is not available." << endl;
            }
            break;
        }
    }
}

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
void CustomerManagement::addCustomer() {
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