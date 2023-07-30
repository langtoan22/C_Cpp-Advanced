#include <iostream>
#include <string>
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

Employee::Employee(string EmployeeName, string EmplyeePhoneNumber, jobPosition EmployeePosition) {
    Name = EmployeeName;
    phoneNumber = EmplyeePhoneNumber;
    Position = EmployeePosition;
    
}

void Employee::setName(string EmployeeName) {
    Name = EmployeeName;
}

string Employee::getName() {
    return  Name;
}

void Employee::setPhoneNumber(string EmplyeePhoneNumber) {
    phoneNumber = EmplyeePhoneNumber;
}

string Employee::getPhoneNumber() {
    return phoneNumber;
}

void Employee::setJobPosition(jobPosition EmployeePosition) {
    Position = EmployeePosition;
}

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

void Employee::addWorkSchedule(Date date, Time time, Status status) {
    
    Schedule schedule = {date, time, status};
    WorkSchedule.push_back(schedule);
}

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

class EmployeeManager {
private:
    vector<Employee> EmployeeList;

public:
    void addEmployee(Employee employee);
    void updateEmployee(string EmployeeName, string EmplyeePhoneNumber, jobPosition EmployeePosition);
    void removeEmployee(string name);
};

void EmployeeManager::addEmployee(Employee employee) {
    EmployeeList.push_back(employee);
}

void EmployeeManager::updateEmployee(string EmployeeName, string EmplyeePhoneNumber, jobPosition EmployeePosition) {
    for (auto& employee : EmployeeList) {
        if (employee.getName() == EmployeeName) {
            employee.setPhoneNumber(EmplyeePhoneNumber);
            employee.setJobPosition(EmployeePosition);
            return;
        }
    }
}


void EmployeeManager::removeEmployee(string EmployeeName) {
   
    for(auto it = EmployeeList.begin(); it != EmployeeList .end(); ++it){
        if(it->getName() == EmployeeName){
            it = EmployeeList.erase(it);
        }
    }
}

int main() {

    // Tạo danh sách quản lý nhân viên
    EmployeeManager employeeManager;

    // Tạo nhân viên a và thêm lịch làm việc
    Employee employeeA("a", "1234567890", RECEPTIONIST);
    employeeA.addWorkSchedule({1, 8, 2023}, {9, 0}, IN);
    employeeA.addWorkSchedule({2, 8, 2023}, {10, 0}, IN);
    employeeA.addWorkSchedule({3, 8, 2023}, {11, 0}, OUT);

    // Thêm nhân viên a vào danh sách quản lý nhân viên
    employeeManager.addEmployee(employeeA);

    // Tạo nhân viên b và thêm lịch làm việc
    Employee employeeB("b", "0987654321", LAUDRY_STAFF);
    employeeB.addWorkSchedule({1, 8, 2023}, {8, 0}, IN);
    employeeB.addWorkSchedule({2, 8, 2023}, {9, 0}, IN);
    employeeB.addWorkSchedule({3, 8, 2023}, {10, 0}, OUT);

    // Thêm nhân viên b vào danh sách quản lý nhân viên
    employeeManager.addEmployee(employeeB);

    // Hiển thị lịch làm việc của nhân viên a
    employeeA.displayWorkSchedule();

    // Hiển thị lịch làm việc của nhân viên b
    employeeB.displayWorkSchedule();

    // Thêm nhân viên b vào danh sách quản lý nhân viên
    employeeManager.addEmployee(employeeB);

    // Hiển thị lịch làm việc của nhân viên a
    employeeA.displayWorkSchedule();

    // Hiển thị lịch làm việc của nhân viên b
    employeeB.displayWorkSchedule();

    // Xóa nhân viên a khỏi danh sách quản lý nhân viên
    employeeManager.removeEmployee("a");

    // Hiển thị danh sách quản lý nhân viên sau khi xóa
    // Chỉ còn nhân viên b trong danh sách
    for (auto& employee : employeeManager.EmployeeList) {
        cout << "Name: " << employee.getName() << endl;
    }
    
    return 0;
}