#include <iostream>
#include <list>
#include <stdint.h>
using namespace std;

typedef enum{
    NAM,
    NU
}typeGioiTinh;

typedef enum{
    GIOI,
    KHA,
    TB,
    YEU
}typeHocLuc;

class SinhVien {
    private: 
        uint8_t MSV;
        string TEN;
        int TUOI;
        typeGioiTinh GIOI_TINH;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;
        double DIEM_TRUNG_BINH;
        typeHocLuc HOC_LUC;
    public: 
        SinhVien( string ten, int tuoi, typeGioiTinh gioitinh, double diemtoan, double diemly, double diemhoa);
        uint8_t getMsv();
        void setTen(string ten);
        string getTen();
        void setTuoi(int tuoi);
        int getTuoi();
        typeGioiTinh getGioiTinh();
        void setDiemToan(double diemtoan);
        double getDiemToan();
        void setDiemLy(double diemly);
        double getDiemLy();
        void setDiemHoa (double diemhoa);
        double getDiemHoa();
        double getDiemTB();
        typeHocLuc getHocLuc();
        void getThongTin();
};

    SinhVien :: SinhVien( string ten, int tuoi, typeGioiTinh gioitinh, double diemtoan, double diemly, double diemhoa){
        
        static uint8_t msv = 0;
        msv ++;
        MSV = msv;

        TEN = ten;
        TUOI = tuoi;
        GIOI_TINH = gioitinh;
        DIEM_TOAN = diemtoan;
        DIEM_LY = diemly;
        DIEM_HOA = diemhoa;
        
    }
    uint8_t SinhVien :: getMsv(){
       
        return  MSV;
    }
    void SinhVien :: setTen(string ten){
        TEN = ten;
    }
    string SinhVien :: getTen(){
        return TEN;
    }
    void SinhVien :: setTuoi(int tuoi){
        TUOI = tuoi;
    }
    int SinhVien :: getTuoi(){
        return TUOI ;
    }
    typeGioiTinh SinhVien :: getGioiTinh(){
        return GIOI_TINH;
    }
    void SinhVien :: setDiemToan(double diemtoan){
        DIEM_TOAN = diemtoan;
    }
    double SinhVien :: getDiemToan(){
        return DIEM_TOAN;
    }
    void SinhVien :: setDiemLy (double diemly){
        DIEM_LY = diemly;
    }
    double SinhVien :: getDiemLy(){
        return DIEM_LY;
    }
    void SinhVien :: setDiemHoa (double diemhoa){
        DIEM_HOA = diemhoa;
    }
    double SinhVien :: getDiemHoa(){
        return DIEM_HOA;
    }
    double SinhVien :: getDiemTB(){
        return DIEM_TRUNG_BINH = (DIEM_TOAN + DIEM_LY + DIEM_HOA)/3;
    }
    typeHocLuc SinhVien :: getHocLuc(){
        if(DIEM_TRUNG_BINH >= 8){
            cout << "Hoc luc Gioi" << endl;
            return GIOI;
        }
        else if (DIEM_TRUNG_BINH >= 6.5 && DIEM_TRUNG_BINH <= 8){
            cout << "Hoc luc Kha" << endl;
            return KHA;
        }
        else if (DIEM_TRUNG_BINH >= 5 && DIEM_TRUNG_BINH <= 6.5){
            cout << "Hoc luc TB";
            return TB;
        }
        else {
            cout << "Hoc luc Yeu" << endl;
            return YEU;
        }
    }

    void SinhVien :: getThongTin(){
        cout << "Ten: "<<getTen() << endl;
        cout << "Tuoi: "<< getTuoi() << endl;
        cout << " Gioi tinh: " << getGioiTinh() << endl;
        cout << "Diem toan: " << getDiemToan() << endl;
        cout << "Diem ly: " << getDiemLy() << endl;
        cout << "Diem hoa: " << getDiemHoa() << endl;
        cout << "Diem trung binh: " << getDiemTB() << endl;
        cout << "Hoc luc: " << getHocLuc()<< endl;
    }
class Menu{
    private: 
        list <SinhVien> Database;
    public:
        void ThemSinhVien();
        void CapNhat();
};


    void Menu :: ThemSinhVien(){
        string TEN;
        int TUOI;
        typeGioiTinh GIOI_TINH;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;

    cout << "Nhap ten cua sinh vien: " << endl;
    cin >> TEN;
    cout << "Nhap tuoi cua sinh vien: "<< endl;
    cin >> TUOI;
    cout << "Nhap gioi tinh sinh vien: " << endl;
    string gt;
    cin >> gt;
    if( gt =="NAM"){
        GIOI_TINH = NAM;
    }
    else if (gt == "NU"){
        GIOI_TINH = NU;
    }
    else {
        cout << " Gioi tinh khong hop le" << endl;
    }

    do
    {
        cout << "Nhap vao diem TOAN: "<< endl;
        cin >> DIEM_TOAN;
        cout << "Nhap vao diem LY: " << endl;
        cin >> DIEM_LY;
        cout << "Nhap vao diem HOA: " << endl;
        cin >> DIEM_HOA;
        if (DIEM_TOAN < 0 || DIEM_TOAN > 10 || DIEM_LY < 0 || DIEM_LY > 10 || DIEM_HOA < 0 || DIEM_HOA > 10){
            cout << " Diem nhap vao khong hop le, vui long nhap lai!\n";
        }
    } while (DIEM_TOAN < 0 || DIEM_TOAN > 10 || DIEM_LY < 0 || DIEM_LY > 10 || DIEM_HOA < 0 || DIEM_HOA > 10);

    
        SinhVien sv (TEN, TUOI, GIOI_TINH, DIEM_TOAN, DIEM_LY, DIEM_HOA);

        Database.insert(Database.begin(),sv);

        Database.push_back(sv);
    }   

    void Menu :: CapNhat(){

        uint8_t MSV;
        string TEN;
        int TUOI;
        typeGioiTinh GIOI_TINH;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;

        cout << "Nhap msv cua sinh vien" << endl;
        cin >> MSV;

        for (SinhVien item : Database){
            if(MSV == item.getMsv()){
                cout << "Thong tin sinh vien: " << endl;
                item.getThongTin();

                cout << "Nhap tong tin can cap nhat cho sinh vien: \n";

                cout << "Nhap ten moi cua sinh vien: " << endl;
                cin >> TEN;
                cout << "Nhap tuoi moi cua sinh vien: "<< endl;
                cin >> TUOI;
                cout << "Nhap gioi tinh moi sinh vien: " << endl;
                string gt;
                cin >> gt;
                if( gt =="NAM"){
                    GIOI_TINH = NAM;
                }
                else if (gt == "NU"){
                    GIOI_TINH = NU;
                }
                else {
                    cout << " Gioi tinh khong hop le" << endl;
                }

                do
                {
                    cout << "Nhap vao diem TOAN moi: "<< endl;
                    cin >> DIEM_TOAN;
                    cout << "Nhap vao diem LY moi: " << endl;
                    cin >> DIEM_LY;
                    cout << "Nhap vao diem HOA moi: " << endl;
                    cin >> DIEM_HOA;
                    if (DIEM_TOAN < 0 || DIEM_TOAN > 10 || DIEM_LY < 0 || DIEM_LY > 10 || DIEM_HOA < 0 || DIEM_HOA > 10){
                        cout << " Diem nhap vao khong hop le, vui long nhap lai!\n";
                    }
                } while (DIEM_TOAN < 0 || DIEM_TOAN > 10 || DIEM_LY < 0 || DIEM_LY > 10 || DIEM_HOA < 0 || DIEM_HOA > 10);


            return item.getThongTin();

                break;
            }/* A */  
        }
        cout << " Khong tim thay Msv!" << endl;
    }

    int main(int argc, char const *argv[])
    {
        
        Menu o;
        o.ThemSinhVien();
        o.CapNhat();
        SinhVien sv("x", 24, NAM, 5, 7, 4);
        return 0;
    }
    