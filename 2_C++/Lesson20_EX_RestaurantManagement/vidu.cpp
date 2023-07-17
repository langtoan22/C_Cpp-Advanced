/*
*File: RestaurantManagement.cpp
*Description: program for restaurant management
*/
#include <iostream>
#include <list>
#include <string>
using namespace std;

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
 
    Dish :: Dish(){

    }
    Dish :: Dish(string name, int price){
        static int id = 100;
        id ++;
        ID = id;
        NAME = name;
        PRICE = price;
    }
    int Dish :: getId(){
        return ID;
    }
    void Dish :: setName(string name){
        NAME = name;
    }

    string Dish :: getName(){
        return NAME;
    }

    void Dish :: setPrice(int price){
        PRICE = price;
    }
    int Dish :: getPrice(){
        return PRICE;
    }

    void Dish :: getInformation(){
        cout <<"Id: " << getId() << " || Name: " << getName() << " || Price: " << getPrice() << endl;
    }
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
Manager :: Manager(){

}
int Manager :: getNumberOfTable(){
    return NUMBER_OF_TABLE;
}
list <Dish> Manager :: getDatabaseDish(){
    return DATABASE_DISH;
}
void Manager ::menuManager(){

    int choice;
    do{
    cout << "Enter your choice\n";
    cout << "1. addDish\n";
    cout << "2. updateDish\n";
    cout << "3. deleteDish\n";
    cout << "4. listDish\n";
    cout << "5. setNumberOfTable\n";
    cout << "0. return option\n";

    do{
        cin>> choice;
        if(choice < 0 || choice >  5){
            cout << "Invalid choice please re -enter\n";
        }
    }while(choice < 0 || choice >  5);
        switch (choice)
        {
        case 1: addDish();
            break;
        case 2: updateDish();
            break;
        case 3: deleteDish();
            break;
        case 4: listDish(true);
            break;
        case 5: setNumberOfTable();
            break;
        case 0: 
            return;
        default:
            break;
        }
    }while(true);

}
void Manager :: addDish(){
    again:
    string name;
    int price;
    int choice;

    cout << "===================================" << endl;
    cout << "Enter dish information \n";
    cout << "Enter dish name\n ";
    cin >> name;
    cout << "Enter dish price\n";
    cin >> price;
    Dish dish(name, price);
    DATABASE_DISH.push_back(dish);
    listDish(false);

    do{
        cout << "===================================" << endl;
        cout << "1. Continue add dish\n";
        cout << "0. return option\n";
        cout << "Enter your choice\n";
        cin >> choice;

    }while(choice != 0 && choice != 1);

    switch(choice){
        case 1: goto again;
        case 0: 
            break;
        defaut: 
            break;
    }
}
void Manager :: updateDish(){
    int id;
    string name;
    int price;
    int choice;

    //display the dish list
    listDish(false);
    again:
        cout << "Enter dish ID to update\n";
        cin >> id;

        for(Dish &item : DATABASE_DISH){
            if(id == item.getId()){

                cout <<"Enter dish information to update\n";
                cout << "Enter dish name\n";
                cin >> name;
                cout << "Enter dish price\n";
                cin >> price;

                item.setName(name);
                item.setPrice(price);

                // display the dish list
                listDish(false);

                // Do you want to keep it?
                cout << "1. Coutinue to update\n";
                cout << "0. return option\n";

                do{
                    cout << "Enter your choice\n";
                    cin >> choice;

                switch (choice)
                {
                case 1: goto again;
                    break;
                case 0: 
                    break;
                default:
                    break;
                }
                }while(choice < 0 || choice > 1);

            return ;
            }
        }  
        cout << "Dish not found id: "<< id << endl;
}
void Manager :: deleteDish(){

    int id;
    int choice;

    // display dish list
    listDish(false);

    //enter id to erase dish

    again:
    cout << "Enter the dish id to erase\n";
    cin >> id;
    list <Dish> :: iterator item;

    for(item = DATABASE_DISH.begin(); item != DATABASE_DISH.end(); ++item){
        if(id == item->getId()){
            item = DATABASE_DISH.erase(item);
            cout << "Successfully erased: \n";
            listDish(false);
            do{
                cout << "1. Continue erase\n";
                cout << "0. return option\n";
                cout << "Enter your choice\n";
                cin >> choice;
                switch (choice)
                {
                case 1: goto again;
                    break;
                case 0: 
                    break;
                default:
                    break;
                }
            }while(choice < 0 || choice > 1);
            return ;
        }
    }
        cout << "Dish not found id: "<< id << endl;
}
void Manager :: listDish(bool fromMenu){
    int choice;
    int i = 1;
    cout << "display dish list\n";
    for(Dish item : DATABASE_DISH){
        cout << i << ". ";
        item.getInformation();
        i++;
    }

    if(fromMenu){
        do{
            cout << "Enter 0 to return option\n";
            cin >> choice;
            if(choice != 0){
                cout << "Invalid choice please re -enter\n";
            }
        }while(choice !=0);
    }
}
void Manager :: setNumberOfTable(){
    int choice;
    int number_of_table;

    NUMBER_OF_TABLE = number_of_table;

    cout <<"set number of table for restaurant\n";
    cin >> number_of_table;
    cout << "Successfully enter\n";

    do{
        cout << "Enter 0 to return option\n";
        cin >> choice;
        if(choice != 0){
            cout << "Invalid choice please re -enter\n";
        }
    }while(choice != 0);
}
class mainMenuRestaurant {
    private:
        Manager manager;
    public: 

        mainMenuRestaurant();
        void menuChoice();
        void mainMenuManager();
};

/*
*Contructor: mainMenuRestaurant
*Discription: This constructor initializes a new instance of the mainMenuRestaurant class.
*Input: none
*Output: none
*/
mainMenuRestaurant :: mainMenuRestaurant(){
    manager = Manager();
}
/*
*method: MenuChoice
*Description: This method display main menu restaurant and chose menu reataurant
*Input:
manager: menu of manager
staff: menu of staff
*Output: none
*/
void mainMenuRestaurant :: menuChoice (){
        typedef enum{
        QUAN_LY = 1,
        NHAN_VIEN = 2
        } menu;

        int choice = 0;
        do{
            cout << "===================================" << endl;
            cout << " MAIN MENU RESTAURANT" << endl;
            cout << "1. Manager" << endl;
            cout << "2. Staff" << endl;
            cout << "#. exit" << endl;
            cout << "Enter your choice \n";
        do
        {
            cin >> choice;
            if (choice != 1 && choice != 2)
            {
                cout << "Invalid choice please re -enter!\n";
            }

        } while (choice != 1 && choice != 2);

        switch ((menu)choice)
        {
            case 1:
            cout << "You chose Manager!\n";
            manager.menuManager();
                break;
            default:
                break;
        }
    }while(true);
}


int main(int argc, char const *argv[])
{
    mainMenuRestaurant mainmenu;
    mainmenu.menuChoice();
    return 0;
}
