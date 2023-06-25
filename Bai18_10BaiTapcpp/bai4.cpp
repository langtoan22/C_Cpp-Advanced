#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Animals {
    private:
        string NAME;
        int AGE;
        double WEIGHT;
    public:
        Animals(string name, int age, double weight);
        void setName(string name);
        string getName();
        void setAge(int age);
        int getAge();
        void setWeight(double weight);
        double getWeight();

        double Caculate_BMI ();

        void compareAge (int other_animal_age);
        void compareWeight (double other_animal_weight);
        void Display();
};

    Animals :: Animals(string name, int age, double weight){
        NAME = name;
        AGE = age;
        WEIGHT = weight;
    }
    void Animals :: setName(string name){
        NAME = name;
    }
    string Animals :: getName(){
        return NAME;
    }
    void Animals :: setAge(int age){
        AGE = age;
    }
    int Animals :: getAge(){
        return AGE;
    }
    void Animals :: setWeight(double weight){
        WEIGHT = weight;
    }
    double Animals :: getWeight(){
        return WEIGHT;
    }

//caculate BMI
    double Animals :: Caculate_BMI(){
        float height = 1.0;
        return WEIGHT/(pow(height,2));
    }

//compare age with other animal
    void Animals :: compareAge(int other_animal_age){
        Animals other_animal("cat", 1, 3.5);

        if (AGE > other_animal_age){
            cout << getName() << " is older than " << other_animal.getName()  << endl;
        }
        else if(AGE < other_animal_age){
            cout << getName() << " is younger than "<< other_animal.getName() << endl;
        }
        else {
            cout << getName() << " is the same age with " << other_animal.getName() << endl;
        }
    }

//compare weight with other animal
    void Animals :: compareWeight(double other_animal_weight){
        Animals other_animal("cat", 1, 3.5);
        if (WEIGHT > other_animal_weight){
            cout << getName() << " is heavier than " << other_animal.getName() << endl;
        }
        else if (WEIGHT < other_animal_weight){
            cout << getName() << " is lighter than " << other_animal.getName() << endl;
        }
        else {
            cout << getName() << " is the same weight with " << other_animal.getName() << endl;
        }
    }

// display 
    void Animals :: Display(){
        Animals other_animal("cat", 1, 3.5);
        cout << "Information of animal: "<< endl;
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Weight: " << getWeight() << endl;
        cout << "BMI: " << Caculate_BMI() << endl;

        cout << "\nInformation of other animal" << endl;
        cout << "Name: "<< other_animal.getName() << endl;
        cout << "Age: " << other_animal.getAge() << endl;
        cout << "Weight: " << other_animal.getWeight()<< endl;
        
        cout << "\ncompare age and weight with other animal: "<< endl;

    // compare other animal
        compareAge(other_animal.getAge());
        compareWeight(other_animal.getWeight()); 
    }
    
    int main(int argc, char const *argv[])
    {
        Animals animal1("dog", 2, 21.5);
        Animals other_animal("cat", 1, 3.5);
        animal1.Display();

        return 0;
    }
    