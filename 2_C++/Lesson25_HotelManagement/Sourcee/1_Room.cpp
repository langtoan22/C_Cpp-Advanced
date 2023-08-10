/*
* File: Room.cpp
* Author: Lang Van Toan
* Date: 23/07/2023
* Description: This file contains all the functions/methods to room management  
*/

#include "Room.h"
#include <vector>

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
