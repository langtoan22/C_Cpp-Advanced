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

int main (){
    Room room;


    return 0;
}