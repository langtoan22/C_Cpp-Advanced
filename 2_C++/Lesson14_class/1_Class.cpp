#include <iostream>
#include <string>
using namespace std ;

class sinhvien{
    public://pham vi truy cap
        void setthongtin();
        void hienthi(); //method

    private: 
        int tuoi;// property
        int lop;
        string ten;
};

void sinhvien::setthongtin(){
        cout << "nhap vao tuoi:\n";
        cin >> tuoi;
        cout << "nhap vao lop:\n";
        cin >> lop;
        cout << "nhap vao ten:\n";
        cin >> ten;

    }

    void sinhvien::hienthi(){
        cout <<"ten:" << ten <<"\n";
        cout <<"tuoi" << tuoi <<endl;
        cout << "lop:" << lop << endl;
    }
int main(int argc, char const *argv[])
{
    sinhvien sv1; //Oject thuoc class sinh vien

    sv1.setthongtin();
    sv1.hienthi();

    return 0;
}
