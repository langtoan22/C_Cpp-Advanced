#include <iostream>
#include <string>

using namespace std;


class sinhvien{
    private:    
        float TOAN;
        float LY;
        float HOA;
        float DIEM_TRUNG_BINH;
        string TEN;
    public:
    //thong so nhap vao
        sinhvien(string ten, float toan, float ly, float hoa);
    
    //tao cac method de thay doi toan ly hoa 
    
        void setTen(string ten);
        string getTen();

        void setToan(float toan);
        float getToan();

        void setLy(float ly);
        float getLy();

        void setHoa(float hoa);
        float getHoa();

        float getDiemTrungBinh();

        void HienThi();
        
        void setDiem(float toan, float ly, float hoa);
};

// constructor
    sinhvien::sinhvien(string ten, float toan, float ly, float hoa){
        TEN = ten;
        TOAN = toan;
        LY = ly;
        HOA = hoa;
    }

    void sinhvien :: setTen(string ten){
        TEN = ten;
    }
    string sinhvien :: getTen (){
        return TEN;
    }
    
    void sinhvien ::setToan(float toan){
        TOAN = toan;
    }
    float sinhvien :: getToan(){
        return TOAN;
    }

    void sinhvien :: setLy(float ly){
        LY = ly;
    }
    float sinhvien :: getLy(){
        return LY;
    }

    void sinhvien :: setHoa(float hoa){
        HOA = hoa;
    }
    float sinhvien :: getHoa(){
        return HOA;
    }

    float sinhvien :: getDiemTrungBinh(){
        return  (TOAN + LY + HOA)/3;
    }

    void sinhvien :: HienThi(){
        cout << "Thong tin sinh vien:"<< endl;
        cout << "Ten: " << getTen() << endl;
        cout << "Diem Toan: " << getToan() << endl;
        cout << "Diem Ly: " << getLy() <<endl;
        cout <<"Diem Hoa: " << getHoa() << endl;
        cout << "Diem trung binh: " << getDiemTrungBinh() << endl;
    }

    void sinhvien :: setDiem(float toan, float ly, float hoa){
        TOAN = toan;
        LY = ly;
        HOA = hoa;
    }
int main(int argc, char const *argv[])
{
    float toan, ly, hoa;

// dat dieu kien diem
    do {
        cout << "Nhap diem Toan: ";
        cin >> toan;
        cout << "Nhap diem Ly: ";
        cin >> ly;
        cout << "Nhap diem Hoa: ";
        cin >> hoa;
        if (toan < 0 || toan > 10 || ly < 0 || ly > 10 || hoa < 0 || hoa > 10) {
            cout << "Diem khong hop le. Vui long nhap lai.\n";
        }
    } while (toan < 0 || toan > 10 || ly < 0 || ly > 10 || hoa < 0 || hoa > 10);

// tao doi tuong sinh vien vua nhap
    sinhvien sv1("nguyen van a", toan, ly, hoa);
    sv1.HienThi();

// thay doi thong tin va cap nhat lai
    sv1.setDiem(toan, ly, hoa);
    sv1.getDiemTrungBinh();
    sv1.HienThi();
    // chua xong

return 0;
}
