#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class hcn{
    private:
        int CHIEU_DAI;
        int CHIEU_RONG;

    public:
        hcn(int chieudai , int chieurong);
        void setchieuDai(int chieudai);
        int getchieuDai();

        void setchieuRong(int chieurong);
        int getchieuRong();

        int getChuVi();
        int getDienTich();
        float getDuongCheo();

        void HienThi();
        void KiemTraHinhVuong();

};

    hcn :: hcn (int chieudai = 0, int chieurong = 0){
        CHIEU_DAI = chieudai;
        CHIEU_RONG = chieurong;
    }

    void hcn :: setchieuDai (int chieudai){
        CHIEU_DAI = chieudai;
    }

    int hcn ::getchieuDai(){
        return CHIEU_DAI;
    }

    void hcn :: setchieuRong(int chieurong){
        CHIEU_RONG = chieurong;
    }

    int hcn :: getchieuRong(){
        return CHIEU_RONG;
    }

    int hcn :: getChuVi(){
        return (CHIEU_DAI + CHIEU_RONG)*2;
    }

    int hcn :: getDienTich(){
        return (CHIEU_DAI * CHIEU_RONG);
    }

    float hcn :: getDuongCheo(){
        return sqrt(pow(CHIEU_DAI, 2) + pow(CHIEU_RONG, 2));
    }

    void hcn :: KiemTraHinhVuong(){
        if(CHIEU_DAI == CHIEU_RONG){
            cout << "la hinh vuong" << endl;
        }
        else{
            cout << "Khong phai la hinh vuong" << endl;
        }
    }

    void hcn :: HienThi (){
   
    cout << "\nChu vi hinh chu nhat la: " << getChuVi() << endl;

    cout << "Dien tich hinh chu nhat la: " << getDienTich() << endl;

    cout << "Do dai duong cheo hinh chu nhat la: " <<setprecision(2) << fixed << getDuongCheo() << endl;
    
    KiemTraHinhVuong();
    }

int main(int argc, char const *argv[])
{
    int chieudai, chieurong;

    cout << "Nhap chieu dai hinh chu nhat: ";
    cin >> chieudai;
    cout << "Nhap chieu rong hinh chu nhat: ";
    cin >> chieurong;

    hcn hcn1(chieudai, chieurong);
    hcn1.HienThi();

    return 0;
}
