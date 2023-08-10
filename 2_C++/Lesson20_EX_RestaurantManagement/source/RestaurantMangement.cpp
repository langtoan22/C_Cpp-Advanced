/*
*File: RestaurantManagement.cpp
*Author: Lang Van Toan
* Description: This is a header file that contains all the prototypes to restaurant management
*/

#include "RestaurantManagement.h"

/*
*Contructor: Dish
*Discription: This constructor initializes a new instance of the Dish class
*Input:
*   name: name of dish
*   price: price of dish
*/  
    Dish :: Dish(){

    }
    Dish :: Dish(string name, int price){
        static int id = 100;
        id ++;
        ID = id;
        NAME = name;
        PRICE = price;
    }
/*
*Method: getId
*Description: This method returns id of current dish
*Output: id of current Dish
*/
    int Dish :: getId(){
        return ID;
    }

/*
*Method: setName
*Description: This method set name of current dish
*input: name : name of dish
*Output: none
*/
    void Dish :: setName(string name){
        NAME = name;
    }

/*
*Method: getName
*Description: This method returns name of current dish
*Output: name of current dish
*/  
    string Dish :: getName(){
        return NAME;
    }

/*
*Method: setPrice
*Description: This method set price of current dish
*Input:
    price : price of dish
*Output: none
*/
    void Dish :: setPrice(int price){
        PRICE = price;
    }

/*
*Method: getPrice
*Description: This function returns price of current dish
*Output: price of current dish
*/
    int Dish :: getPrice(){
        return PRICE;
    }

/*
*Method: getInformation(){
*Description: This method returns information of current Dish
*Output: information of current dish
*/
    void Dish :: getInformation(){
        cout <<"Id: " << getId() << " || Name: " << getName() << " || Price: " << getPrice() << endl;
    }

/*
*Contructor: Manage
*Discription: This constructor initializes a new instance of the Manage class.
*Input:
*   listDish: address of  list dish
*   NUMBER_OF_TABLE: addess of variable saving number of table
*Output: none
*/
Manager :: Manager(){

}

/*
*Method: getNumberOfTable(){
*Description: This method returns quantity of table
*Output: quantity of table
*/
int Manager :: getNumberOfTable(){
    return NUMBER_OF_TABLE;
}

/*
*Method: getDatabaseDish(){
*Description: This method returns list dish of manager
*Output: list dish
*/
list <Dish> Manager :: getDatabaseDish(){
    return DATABASE_DISH;
}

/*
*Mehtod: menuManager
*Description: This method displat option and choose option, made by manager
*Input:none
*Output: none
*/
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


/*
*Method: addDish
*Description: This function add new dish to menu
*Input:none
*Output: none
*/
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

/*
*Method: updateDish
*Description: This method update information of dish to menu
*Input:none
*Output: none
*/
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



/*
*Method: deleteDish
*Description: This method delete dish from  menu
*Input:none
*Output: none
*/
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

/*
*Method: listDish
*Description: This method display list dish from menu
*Input:
bool fromMenu: return true or false when the list in thế menu or the other method
*Output: none
*/
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


/*
*Method: setNumberOfTable
*Description: This method set number of table 
*Input:
number_of_table: number of table
*Output: none
*/
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

/*
*Contructor: InformationOfTable
*Discription: This constructor initializes a new instance of InformationOfTable class
*Input:
*   table_code: id of the table
*   status: status of the table true or false
*Output: none
*/
InformationOfTable :: InformationOfTable(){

}
InformationOfTable :: InformationOfTable(int table_code, bool status){
    TABLE_CODE = table_code;
    STATUS = status;
}

/*
*Method: getNumberOfTable
*Description: This method return id of the table 
*Output: id of the table
*/
int InformationOfTable :: getNumberOfTable(){
    return TABLE_CODE;
}

/*
*Method: getDishInTable
*Description: This method return list dish on the table
*Output: list dish on the table
*/
list <InformationOfTable :: typeDish> InformationOfTable :: getDishInTable(){
    return DISH_IN_TABLE;
}

/*
*Method: setStatus
*Description: This method set status of table
*input: 
status: status of the table
*Output: none
*/
void InformationOfTable :: setStatus(bool status){
    STATUS = status;
}

/*
*Method: getStatus
*Description: This method return status of table
*input: none
*Output: status of the table
*/
bool InformationOfTable :: getStatus(){
    return STATUS;
}

/*
*Method: addDish
*Description: This method add new dish to menu on the table
*Input:
dish: list dish 
quantity: quantity of dish
*Output: none
*/
void InformationOfTable :: addDish(){
    Dish dish;
    int quantity;
    int choice;

    again:
        for(typeDish item : DISH_IN_TABLE){
            if(dish.getId() == item.DISH.getId()){
                item.QUANTITY += quantity;
            }
            else{
                typeDish NewDish{dish, quantity};
                NewDish.DISH = dish;
                NewDish.QUANTITY = quantity = 1;
                DISH_IN_TABLE.push_back(NewDish);
                do{
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    cout<<"1. Continue Add Another Dish"<<endl;
                    cout<<"0. Return option"<<endl;
                    cout << "Enter your choice\n";
                    cin >> choice;
                }while(choice < 0 || choice >1);

                switch (choice)
                {
                case 0:
                    break;
                case 1: goto again;
                default:
                    break;
                }
            }
        }
}


/*
*Method: updateDish
*Description: This method update dish information has been added to the table
*Input: 
quantity: quantity of dish
*Output: none
*/
void InformationOfTable :: updateDish(){
   int id, quantity, choice;

   listDish(false);

    again:
    cout << "Enter dish id to update\n";
    cin >> id;
    for(typeDish item : DISH_IN_TABLE){
        if(id == item.DISH.getId()){
            cout << "Enter the dish quantity to update\n";
            cin >> quantity;
            item.QUANTITY = quantity;
            cout << "sucessfuly update";
            do{
                cout<<"--------------------------------------------------------------------------------"<<endl;
                    cout<<"1. Continue update"<<endl;
                    cout<<"0. Return option"<<endl;
                    cout<<"Enter Your choice: ";
                    cin>>choice;
            }while(choice < 0 || choice > 1);

            switch (choice)
                {
                case 0:
                    break;
                case 1:
                    goto again;
                default:
                    break;
                }
        }
    }
    cout << "Khong tim thay mon co id: " << id << endl;
}

/*
*Method: deleteDish
*Description: This method delete dish information has been added to the table
*Input: none
*Output: none
*/
void InformationOfTable :: deleteDish(){

    list<typeDish> :: iterator item;
    int id, choice;
    cin >> id;
    listDish(false);

    again:
    cout <<"Enter dish id to erase\n";

    for(item = DISH_IN_TABLE.begin(); item != DISH_IN_TABLE.end(); ++item){
        if(id == item->DISH.getId()){
            DISH_IN_TABLE.erase(item);
            cout << "sucessfuly erase \n";

             do{
                cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"1. Continue erase"<<endl;
                cout<<"0. Return option"<<endl;
                cout<<" Enter Your choice: ";
                cin>>choice;
            }while(choice <0 || choice>1);

            switch (choice)
            {
            case 0:
                break;
            case 1:
                goto again;
            default:
                break;
            }
        }
    }
    cout << "Khong tim thay mon co id: " << id << endl;
}


/*
*Method: listDish
*Description: This method display list dish information has been added to the table
*Input: none
*Output: none
*/
void InformationOfTable :: listDish(bool fromMenu){
    int choice, i = 1;
    cout << "lish dish in the table \n";
    for (typeDish item : DISH_IN_TABLE)
    {   
        cout << i << ". ";
        item.DISH.getInformation();
        i++;
    }

    if(fromMenu){
        do{
            cout << "Enter 0 to return option\n";
            cin >> choice;
            if (choice != 0 ){
                cout << "\n";
            }
        }while(choice != 0);
    }
}


/*
*Methode: billPayment(){

*Description: This method Pay the money for the dish that has been added to the table
*Input:none
*Output: none
*/
void InformationOfTable :: billPayment(){
    int choice, total = 0;

    listDish(false);

   for(typeDish item : DISH_IN_TABLE)
    {
        total += item.DISH.getPrice() * item.QUANTITY;
    }
    cout << "Total: " << total << endl;
    DISH_IN_TABLE.clear();
    STATUS = false;

    do{
        cout << "Enter 0 to return option\n";
        cin >> choice;
        if (choice != 0 ){
            cout << "Enter the dish quantity to update\n";
        }
    }while(choice != 0);
}

/*
*Contructor: Staff
*Discription: This constructor initializes a new instance of the Staff class.
*Input:
 database_dish: List dish that manager added to the menu
 number_of_table: number of the table that manager set
*Output: none
*/
Staff :: Staff(int number_of_table , list<Dish>database_dish){
    number_of_table = manager.getNumberOfTable();
    database_dish = manager.getDatabaseDish();

        if(number_of_table == 0 && database_dish.size() == 0){
            cout << "Staff do not have information, please transfer data to management! \n";
        }

        // add table
        else{
            for(int i=1; i<=number_of_table; i++){
            InformationOfTable table(i, false);
            DATABASE_TABLE.push_back(table);
        }

        // coppy list dish from class Manager
        DATABASE_DISH.assign(database_dish.begin(), database_dish.end());
        }
    }

/*
*Method: menuStaff
*Description: This method display options and chose option of the staff
*Input:none
*Output: none
*/
void Staff :: menuStaff(){
    int id_table;
    cout << "Enter id table to access\n";
    cin >> id_table;
    if(id_table < 1 || id_table > manager.getNumberOfTable()){
        cout <<" There is no table with ID: " << id_table << endl;
    }
    else{
        for(InformationOfTable table : DATABASE_TABLE){
            if(id_table == table.getNumberOfTable()){
                for(auto item : table.getDishInTable()){
                    item.DISH.getInformation(); cout << " Quantity: " << item.QUANTITY << endl;
                    
                }
                do{
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    cout << "You chose the table with ID: " << id_table << endl;
                    cout << "1. Add Dish" << endl;
                    cout << "2. Update Dish" << endl;
                    cout << "3. Delete Dish" << endl;
                    cout << "4. List Dish" << endl;
                    cout << "5. Bill Payment" << endl;
                    cout << "0. Return Option" << endl;
                    cout << "Enter your choice ";
                    int choice;

                    do{
                        cin >> choice;
                        if(choice < 0 || choice > 5){
                            cout << "Invalid choice please re -enter\n";
                        }

                        switch (choice){
                            case 1: table.addDish();
                                    
                            case 2: table.updateDish();
                                    break;
                            case 3: table.deleteDish();
                                    break;
                            case 4: table.listDish(true);
                                    break;
                            case 5: table.billPayment();
                                    break;
                            case 0: 
                                    break;
                            default:
                                    break;
                                    
                        }
                    }while(choice < 0 || choice > 5);
                }while(true);
            }
        }
    }
}

/*
*Contructor: mainMenuRestaurant
*Discription: This constructor initializes a new instance of the mainMenuRestaurant class.
*Input: none
*Output: none
*/
mainMenuRestaurant :: mainMenuRestaurant(){
    manager = Manager();
    staff = Staff();
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
        MANAGER = 1,
        STAFF = 2
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

            case 2: 
            cout << "You chose Staff!\n";
            staff.menuStaff();
                break;

            default:
                break;
        }
    }while(true);
}