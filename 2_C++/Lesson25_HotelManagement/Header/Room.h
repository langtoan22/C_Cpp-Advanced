/*
* File: Room.h
* Author: Lang Van Toan
* Date: 23/07/2023
* Description: This file is a Room header file that for program hotel management 
*/

#ifndef __ROOM_H
#define __ROOM_H

#include <iostream>
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

#endif