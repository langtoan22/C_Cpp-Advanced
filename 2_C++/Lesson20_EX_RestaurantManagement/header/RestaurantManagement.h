/*
*File: RestaurantManagement.cpp
*Author: Lang Van Toan
* Description: This is a header file that contains all the prototypes to restaurant management
*/
#include <iostream>
#include <list>
#include <string>
using namespace std;

/*
*Class: Dish
*Description: This class represents the basic properties and methods of a Dish object
*/
class Dish {
    private:
        int ID;
        string NAME;
        double PRICE;
    public:
        Dish();
        Dish(string name, int price);
        int getId();
        void setName(string name);
        string getName();
        void setPrice(int price);
        int getPrice();
        void getInformation();
};

/*
*Class: Manage
*Description: This class represents a basic implementation of a Manage object.
*/   
class Manager {
    private:
        list <Dish> DATABASE_DISH;
        int NUMBER_OF_TABLE;
    
    public:
        Manager();
        void addDish();
        void updateDish();
        void deleteDish();
        void listDish(bool fromMenu);
        void setNumberOfTable();

        int getNumberOfTable();
        list <Dish> getDatabaseDish();
        void menuManager();
};

/*
*Class: InformationOfTable
*Description: This class represents information of table include list dish and quantity dish on the table 
*/  
class InformationOfTable{

    private:
        int TABLE_CODE;
        bool STATUS;
        typedef struct 
        {
            Dish DISH;
            int QUANTITY;
        }typeDish;
        list <typeDish> DISH_IN_TABLE; 

    public:
        InformationOfTable();
        InformationOfTable(int number_of_table, bool status);
        int getNumberOfTable();
        list <typeDish> getDishInTable();
        void setStatus(bool status);
        bool getStatus();
        void addDish();
        void updateDish();
        void deleteDish();
        void listDish(bool fromMenu);
        void billPayment();
};

/*
*Class: Staff
*Description: This class represents a basic implementation of a Staff object.
*/  
class Staff{
    private:
        list<InformationOfTable> DATABASE_TABLE;
        list<Dish>DATABASE_DISH;
        Manager manager;
    public:
        Staff();
        Staff(int number_of_table , list<Dish>database_dish);
        void menuStaff();
};

/*
*Class: mainMenuRestaurant
*Description: This class represents a basic implementation of a mainMenuRestaurant object.
*/
class mainMenuRestaurant {
    private:
        Manager manager;
        Staff staff;
    public: 

        mainMenuRestaurant();
        void menuChoice();
};