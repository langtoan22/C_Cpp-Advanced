#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int hour;
    int minute;
} Time;

class Employee {
private:
    string name;
    string phoneNumber;
    string jobPosition;
    vector<pair<Date, Time>> workSchedule;

public:
    Employee(string name, string phoneNumber, string jobPosition);
    void setName(string name);
    string getName();
    void setPhoneNumber(string phoneNumber);
    string getPhoneNumber();
    void setJobPosition(string jobPosition);
    string getJobPosition();
    void addWorkSchedule(Date date, Time time);
    void displayWorkSchedule();
};

Employee::Employee(string name, string phoneNumber, string jobPosition) {
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->jobPosition = jobPosition;
}

void Employee::setName(string name) {
    this->name = name;
}

string Employee::getName() {
    return this->name;
}

void Employee::setPhoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

string Employee::getPhoneNumber() {
    return this->phoneNumber;
}

void Employee::setJobPosition(string jobPosition) {
    this->jobPosition = jobPosition;
}

string Employee::getJobPosition() {
    return this->jobPosition;
}

void Employee::addWorkSchedule(Date date, Time time) {
    this->workSchedule.push_back(make_pair(date, time));
}

void Employee::displayWorkSchedule() {
    cout << "Work schedule for employee " << this->name << ":" << endl;
    for (auto schedule : this->workSchedule) {
        cout << "Date: " << schedule.first.day << "/" << schedule.first.month << "/" << schedule.first.year
             << ", Time: " << schedule.second.hour << ":" << schedule.second.minute << endl;
    }
}

class EmployeeManager {
private:
    vector<Employee> employeeList;

public:
    void addEmployee(Employee employee);
    void updateEmployee(string name, string phoneNumber, string jobPosition);
    void removeEmployee(string name);
};

void EmployeeManager::addEmployee(Employee employee) {
    this->employeeList.push_back(employee);
}

void EmployeeManager::updateEmployee(string name, string phoneNumber, string jobPosition) {
    for (auto& employee : this->employeeList) {
        if (employee.getName() == name) {
            employee.setPhoneNumber(phoneNumber);
            employee.setJobPosition(jobPosition);
            return;
        }
    }
}

void EmployeeManager::removeEmployee(string name) {
    auto it = this->employeeList.begin();
    while (it != this->employeeList.end()) {
        if (it->getName() == name) {
            it = this->employeeList.erase(it);
        } else {
            ++it;
        }
    }
}

int main() {
    EmployeeManager employeeManager;

    Employee employee1("John Smith", "1234567890", "Receptionist");
    employee1.addWorkSchedule({1, 8, 2023}, {9, 0});
    employee1.addWorkSchedule({2, 8, 2023}, {10, 0});
    employeeManager.addEmployee(employee1);

    Employee employee2("Jane Doe", "0987654321", "Housekeeper");
    employee2.addWorkSchedule({3, 8, 2023}, {8, 0});
    employee2.addWorkSchedule({4, 8, 2023}, {12, 0});
    employeeManager.addEmployee(employee2);

    employeeManager.updateEmployee("John Smith", "0987654321", "Manager");

    employeeManager.removeEmployee("Jane Doe");

    return 0;
}