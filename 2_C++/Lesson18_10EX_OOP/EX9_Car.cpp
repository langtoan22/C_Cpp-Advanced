#include <iostream>
using namespace std;

class Car {
private:
    string COLOR;
    string ENGINE_TYPE;
    double ODO;

public:
    Car(string color, string engineType, double kmDriven);
    void setColor(string color);
    string getColor();
    void setEngineType(string engine_type);
    string getEngineType();
    void setKmDriven(double odo);
    double getKmDriven();
    double calculateMaintenanceCost();
    void checkKmDriven();
    void CarInfo();
};

// Constructor
Car::Car(string color, string engine_type, double odo) {
    COLOR = color;
    ENGINE_TYPE = engine_type;
    ODO = odo;
}
// Setter for color
void Car::setColor(string color) {
    COLOR = color;
}

// Getter for color
string Car::getColor() {
    return COLOR;
}

// Setter for engine type
void Car::setEngineType(string engine_type) {
    ENGINE_TYPE = engine_type;
}

// Getter for engine type
string Car::getEngineType() {
    return ENGINE_TYPE;
}

// Setter for km driven
void Car::setKmDriven(double odo) {
    ODO = odo;
}

// Getter for km driven
double Car::getKmDriven() {
    return ODO;
}

// Method to calculate maintenance cost
double Car::calculateMaintenanceCost() {
    double cost = 0;
    if (getKmDriven() < 10000) {
        cost = 500;
    } else if (getKmDriven() >= 10000 && getKmDriven() < 50000) {
        cost = 1000;
    } else if (getKmDriven() >= 50000 && getKmDriven() < 100000) {
        cost = 2000;
    } else if (getKmDriven() >= 100000) {
        cost = 5000;
    }
    return cost;
}

// Method to check km driven
void Car::checkKmDriven() {
    if (getKmDriven() < 10000) {
        cout << "The car is still new." << endl;
    } else if (getKmDriven() >= 10000 && getKmDriven() < 50000) {
        cout << "The car has been driven for a while." << endl;
    } else if (getKmDriven() >= 50000 && getKmDriven() < 100000) {
        cout << "The car has been driven for quite a long time." << endl;
    } else if (getKmDriven() >= 100000) {
        cout << "The car is quite old." << endl;
    }
}

// Method to print car info
void Car::CarInfo() {
    cout << "Color: " << getColor() << endl;
    cout << "Engine type: " << getEngineType() << endl;
    cout << "Kilometers driven: " << getKmDriven() << endl;
    cout << "Maintenance cost: " << calculateMaintenanceCost() << " USD" << endl;
}

int main() {
    Car myCar("red", "petrol", 75000);
    myCar.CarInfo();
    myCar.checkKmDriven();
    return 0;
}