#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Room {
private:
    int roomNumber;
    bool booked;
    bool cleaning;
public:
    Room() {
        roomNumber = 0;
        booked = false;
        cleaning = false;
    }
    Room(int number) {
        roomNumber = number;
        booked = false;
        cleaning = false;
    } 
    int getRoomNumber() {
        return roomNumber;
    }
    bool available() {
        return !booked && !cleaning;
    }
    void bookRoom() {
        booked = true;
    }
    void checkIn() {
        booked = true;
        cleaning = false;
    }
    void checkOut() {
        booked = false;
        cleaning = true;
    }
};

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

Customer :: Customer(string cusName, string cusPhone, string cusAddress){
        name = cusName;
        phoneNumber = cusPhone;
        address = cusAddress;
}

void Customer :: setName(string cusName){
    name = cusName;
}
void Customer :: setPhoneNumber(string cusPhone){
    phoneNumber = cusPhone;
}
void Customer :: setAddress(string cusAddress){
    address = cusAddress;
}
string Customer :: getAddress(){
    return address;
}
string Customer :: getPhoneNumber(){
    return phoneNumber;
}
string Customer :: getName() {
    return name;
}

void Customer :: addBookHistory(bookHistory bookDetails) {
        History. push_back(bookDetails);
    }

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

void Customer :: getInformation(){
    cout << "Name customer: " << getName() << endl;
    cout << "Phone number customer: " << getPhoneNumber() << endl;
    cout << "Address customer: " << getAddress() << endl;
}
class CustomerManager {
private:
    vector<Customer> customerList;

public:

    void addCustomer();
    void updateCustomer();
    void removeCustomer();
    void displayCustomerInfor();
    void CustomerMenu();
};

// add new customer 

void CustomerManager::addCustomer() {
    string cusName;
    string cusPhone;
    string cusAddress;

    Customer customer1(cusName, cusPhone, cusAddress );
    customerList.push_back(customer1);
}


// edit infomation customer

void CustomerManager::updateCustomer() {
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

// delete customer

void CustomerManager::removeCustomer() {
    string name;
    auto it = customerList.begin();
    for(it = customerList.begin(); it != customerList.end(); ++it){
        if (it->getName() == name) {
            it = customerList.erase(it);
            return;
        }
    }
}

void CustomerManager :: displayCustomerInfor(){
    cout << "Information of customer list: " << endl;
    for(auto it : customerList){
        it.getInformation();
    }
}

void CustomerManager :: CustomerMenu(){
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

int main (){
    Room room;


    return 0;
}