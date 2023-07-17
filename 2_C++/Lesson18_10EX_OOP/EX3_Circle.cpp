#include <iostream>
#include <stdint.h>
using namespace std;

class circle {
    private:
        int radius;
    
    public:
        circle(int r);
        void setRadius(int r);
        int getRadius();
        float getPerimeter();
        float getArea();
        void Display();
};

circle :: circle(int r){
    radius = r;
}

void circle ::setRadius(int r){
    radius = r;
}

int circle :: getRadius(){
    return radius;
}

float circle :: getPerimeter(){
    return radius * 2 * 3.14;
}

float circle :: getArea(){
    return radius * radius * 3.14;
}
void circle :: Display(){
    cout << "Perimeter of circle: " << getPerimeter() << endl;
    cout << "Area of circle: " << getArea() << endl;
}
int main(int argc, char const *argv[])
{
    int r;
    cout << "Nhap ban kinh hinh tron: ";
    cin >> r;
    circle hinhtron(r);
    hinhtron.Display();


    return 0;
}
