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

class OXY {
    private: 
        ToaDo2D pointA;
        ToaDo2D pointB;
        ToaDo2D pointC;
         
        typedef enum {
            KHOANG_CACH,
            DIEN_TICH_TAM_GIAC
        }typePhepToan;
        typePhepToan pheptoan;

    public:
        OXY (ToaDo2D A, ToaDo2D B);
        OXY (ToaDo2D A, ToaDo2D B, ToaDo2D C);
        float getKhoangCach();
        float getDienTichTamGiac();
};

    OXY :: OXY (ToaDo2D A, ToaDo2D B){
        pheptoan = KHOANG_CACH; 
        pointA = A;
        pointB = B;
    }

    OXY :: OXY (ToaDo2D A, ToaDo2D B, ToaDo2D C){
        pheptoan = DIEN_TICH_TAM_GIAC;
        pointA = A;
        pointB = B;
        pointC = C;
    }

    float OXY :: getKhoangCach(){
        if (pheptoan == KHOANG_CACH){
            double x1 = pointA.getX();
            double y1 = pointA.getY();
            double x2 = pointB.getX();
            double y2 = pointB.getY();
            return sqrt(pow(x2-x1, 2) + pow(y2 - y1, 2));
        }
        else {
            cout << "khong tinh duoc khoang cach!" << endl;
        }
    }

    float OXY :: getDienTichTamGiac(){
        if( pheptoan == DIEN_TICH_TAM_GIAC){
            double x1 = pointA.getX();
            double y1 = pointA.getY();
            double x2 = pointB.getX();
            double y2 = pointB.getY();
            double x3 = pointC.getX();
            double y3 = pointC.getY();

            return ((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1)) / 2;
        }
        else {
            cout << "khong tinh duoc dien tich tam giac!" << endl;
        }
    }
int main(int argc, char const *argv[])
{
    int x, y;

    cout << "Nhap toa do diem A: ";
    cin >> x >> y;
    ToaDo2D A(x,y);

    cout << "Nhap toa do diem B: ";
    cin >> x >> y;
    ToaDo2D B(x,y);

    cout << "Nhap toa do diem C: ";
    cin >> x >> y;
    ToaDo2D C(x,y);

    OXY khoangCach(A, B);
    OXY tamgiac(A, B, C);

    cout << "Khoang cach cua diem A va B la: " <<  khoangCach.getKhoangCach() << endl;
    cout << "Dien tich tam giac ABC la: " << tamgiac.getDienTichTamGiac() << endl;

  
    return 0;
}
