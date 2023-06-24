#include <iostream>
#include <cmath>

using namespace std;

class hcn{
    private:
        int CHIEUDAI;
        int CHIEURONG;

    public:
        hcn(int chieudai , int chieurong);
        void setchieuDai(int chieudai);
        int getchieuDai();

        void setchieuRong(int chieurong);
        int getchieuRong();

        int TinhChuVi(int chieudai, int chieurong);
        int TinhDienTich(int chieudai, int chieurong);
        int TinhDuongCheo(int chieudai, int chieurong);
        void KiemTraHinhVuong(int chieudai, int chieurong);
        void HienThi(int chieudai, int chieurong);

};

    hcn :: hcn (int chieudai = 0, int chieurong = 0){
        CHIEUDAI = chieudai;
        CHIEURONG = chieurong;
    }

    void hcn :: setchieuDai (int chieudai){
        CHIEUDAI = chieudai;
    }

    int hcn ::getchieuDai(){
        return CHIEUDAI;
    }

    void hcn :: setchieuRong(int chieurong){
        CHIEURONG = chieurong;
    }

    int hcn :: getchieuRong(){
        return CHIEURONG;
    }

    int hcn :: TinhChuVi(int chieudai, int chieurong){
        return (chieudai + chieurong) *2; 
    }

    int hcn :: TinhDienTich(int chieudai, int chieurong){
        return chieudai * chieurong;
    }

    int hcn :: TinhDuongCheo(int chieudai, int chieurong){
        return sqrt(pow(chieudai, 2) + pow(chieurong,2));
    }

    void hcn :: KiemTraHinhVuong(int chieudai, int chieurong){
        if(chieudai == chieurong){
            cout << "la hinh vuong" << endl;
        }
        else{
            cout << "Khong phai la hinh vuong" << endl;
        }
    }

    void hcn :: HienThi (int chieudai, int chieurong){
    cout << "Nhap chieu dai hinh chu nhat: ";
    cin >> chieudai;
    cout << "\nNhap chieu rong hinh chu nhat: ";
    cin >> chieurong;
    
    cout << "\nChu vi hinh chu nhat la: ";
    TinhChuVi(chieudai, chieurong);

    cout << "\nDien tich hinh chu nhat la: ";
    TinhDienTich(chieudai, chieurong);

    cout << "\nDo dai duong cheo hinh chu nhat la: " << endl;
    TinhDuongCheo(chieudai, chieurong);


    KiemTraHinhVuong(chieudai, chieurong);
    }
int main(int argc, char const *argv[])
{
    int chieudai = 0, chieurong = 0;

    hcn hcn1(chieudai, chieurong);
    hcn1.HienThi(chieudai, chieurong);

    // chua xong

    return 0;
}
