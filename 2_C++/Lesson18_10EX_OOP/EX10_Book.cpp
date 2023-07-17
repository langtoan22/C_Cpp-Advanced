#include <iostream>
using namespace std;

class Sach {
private:
    string TEN;
    string TAC_GIA;
    int NAM_SAN_XUAT;
    int SO_LUONG;

public:
    Sach(string ten, string tac_gia, int nam_san_xuat, int so_luong);
    void setTen(string ten);
    string getTen();
    void setTacgia(string tac_gia);
    string getTacgia();
    void setNamSX(int nam_san_xuat);
    int getNamSX();
    void setsoluong(int so_luong);
    int getSoluong();
    void getThongTin();
    bool muonSach();
    bool traSach();
};


Sach::Sach(string ten, string tac_gia, int nam_san_xuat, int so_luong) {
    TEN = ten;
    TAC_GIA = tac_gia;
    NAM_SAN_XUAT = nam_san_xuat;
    SO_LUONG = so_luong;
}

void Sach::setTen(string ten) {
       TEN = ten;
}

string Sach::getTen() {
    return TEN;
}

void Sach::setTacgia(string tac_gia) {
    TAC_GIA = tac_gia;
}

string Sach::getTacgia() {
    return TAC_GIA;
}

void Sach::setNamSX(int nam_san_xuat) {
     NAM_SAN_XUAT = nam_san_xuat;
}

int Sach::getNamSX(){
    return NAM_SAN_XUAT;
}

void Sach::setsoluong(int so_luong) {
    SO_LUONG = so_luong;
}

int Sach::getSoluong(){
    return SO_LUONG;
}

void Sach::getThongTin() {
    cout << "Ten sach: " << getTen() << endl;
    cout << "Tac gia: " << getTacgia() << endl;
    cout << "Nam san xuat: " << getNamSX() << endl;
    cout << "So luong: " << getSoluong() << endl;
}

bool Sach::muonSach(){

    if (getSoluong() > 0) {
        SO_LUONG --;
        return true;
    }
    else {
        return false;
    }
}

bool Sach::traSach() {
    SO_LUONG ++;
    return true;
}

int main() {
    Sach myBook("Cay_Cam_Ngot_Cua_Toi", "Jose Mauro de Vasconcelos", 1968, 3);
    myBook.getThongTin();
    myBook.muonSach();
    myBook.getThongTin();
    myBook.traSach();
    myBook.getThongTin();
    return 0;
}