#include <iostream>
#include <cmath>

using namespace std;

class ToaDo2D {
    public:
        double KhoangCach2Diem(double x1, double y1, double x2, double y2);
        double DienTichTamGiac();

    private:
        double x,y;
};

double ToaDo2D :: KhoangCach2Diem(double x1, double y1, double x2, double y2){
    double x = x2 - x1;
    double y = y2 - y1;
    return sqrt(x*x + y*y);
}