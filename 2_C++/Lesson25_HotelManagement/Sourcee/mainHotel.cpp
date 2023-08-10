/*
* File: mainHotelManagement.cpp
* Author: Lang Van Toan
* Date: 23/07/2023
* Description: This is file to manage hotel
*/

#include "HotelManagement.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Room room();
    roommanager();

    Customer customer("John Smith", "1234567890", "123 Main St");
    bookHistory history1 = {{ 26, 7, 2023 }, { 10, 0, 0 }, IN};
    customer.addBookHistory(history1);
    bookHistory history2 = {{ 26, 7, 2023 }, { 16, 0, 0 }, OUT};
    customer.addBookHistory(history2);
    customer.displayBoolHistory();

    
    // Tạo danh sách quản lý nhân viên
    EmployeeManagement employeeManagent;

    // Tạo nhân viên a và thêm lịch làm việc
    Employee employeeA("a", "1234567890", RECEPTIONIST);
    employeeA.addWorkSchedule({1, 8, 2023}, {9, 0}, IN);
    employeeA.addWorkSchedule({2, 8, 2023}, {10, 0}, IN);
    employeeA.addWorkSchedule({3, 8, 2023}, {11, 0}, OUT);

    cout <<"\n";
    // Thêm nhân viên a vào danh sách quản lý nhân viên
    employeeManagent.addEmployee(employeeA);

    // Tạo nhân viên b và thêm lịch làm việc
    Employee employeeB("b", "0987654321", LAUDRY_STAFF);
    employeeB.addWorkSchedule({1, 8, 2023}, {8, 0}, IN);
    employeeB.addWorkSchedule({2, 8, 2023}, {9, 0}, IN);
    employeeB.addWorkSchedule({3, 8, 2023}, {10, 0}, OUT);
    cout <<"\n";
    // Thêm nhân viên b vào danh sách quản lý nhân viên
    employeeManagent.addEmployee(employeeB);

    cout <<"\n";
    // Hiển thị lịch làm việc của nhân viên a
    employeeA.displayWorkSchedule();

    cout <<"\n";
    // Hiển thị lịch làm việc của nhân viên b
    employeeB.displayWorkSchedule();

    // Xóa nhân viên a khỏi danh sách quản lý nhân viên
    employeeManagent.removeEmployee("a");

    return 0;
}
