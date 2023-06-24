#include <iostream>

#include <cmath>

using namespace std;

class ToaDo2D {
    public:
        ToaDo2D (int x = 0, int y = 0);
        
        void setX(int x);
        int getX();
        void setY(int y);
        int getY();

        double KhoangCach2Diem(double x1, double y1, double x2, double y2);
        double DienTichTamGiac();

    private:
        double ToaDoX , ToaDoY;
};
    ToaDo2D :: ToaDo2D(int x, int y){
        ToaDoX = x;
        ToaDoY = y;
    }

    void ToaDo2D ::setX(int x){
        ToaDoX = x;
    }
    int ToaDo2D :: getX(){
        return ToaDoX;
    }

    void ToaDo2D :: setY(int y){
        ToaDoY = y;
    }
    int ToaDo2D :: getY(){
        return ToaDoY;
    }


    double ToaDo2D :: KhoangCach2Diem(double x1, double y1, double x2, double y2){
    double x = x2 - x1;
    double y = y2 - y1;
    return sqrt(x*x + y*y);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
