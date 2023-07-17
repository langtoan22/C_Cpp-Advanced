#include <iostream>
#include <string>

using namespace std;

class Human {
    private:
        string NAME;
        int AGE;
        string ADDRESS;
    public:
        Human(string name, int age, string address);
        void setName(string name);
        string getName();
        void setAge(int age);
        int getAge();
        void setAddress(string address);
        string getAddress();

        void Name();
        void Age();
        void Address();
        int Caculate_Age();

        void Display();

};
    Human :: Human(string name, int age, string address){
        NAME = name;
        AGE = age;
        ADDRESS = address;
     }

    void Human :: setName(string name){
        NAME = name;
     }
    string Human :: getName(){
        return NAME;
    }
    void Human :: setAge(int age){
        AGE = age;
    }
    int Human :: getAge(){
        return AGE;
    }
    void Human :: setAddress(string address){
        ADDRESS =  address;
    }
    string Human :: getAddress(){
        return ADDRESS;
    }
    void Human :: Name (){
        cout << "the name: " << getName() << endl;
    }
    void Human :: Age(){
        cout <<"the age: " << getAge() << endl;
    }
    void Human :: Address(){
        cout << "the address: " << getAddress() << endl;
    }
    
    int Human :: Caculate_Age(){
        int currentYear = 2023;
        int birthYear = 2023 - AGE; 
        cout << "BirthYear: " << birthYear << endl;
        return birthYear;
    }
    
    void Human :: Display(){
        cout << "Information Human: " << endl;
        Name();
        Age ();
        Address();
        Caculate_Age();
    }
    int main(int argc, char const *argv[])
    {
        Human A("x", 22, "29A Pham Hung");
        A.Display();

        return 0;
    }
    