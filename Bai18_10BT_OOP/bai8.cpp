#include <iostream>
#include <string>
using namespace std;

class TaiKhoanNganHang{
    private:
        string TENTAIKHOAN;
        string SOTAIKHOAN;
        double SODU;
    public:
        TaiKhoanNganHang(string TenTaiKhoan, string SoTaiKhoan, double SoDu);
        void setSoDu(double SoDu);
        double getSoDu();
        void setTenTaiKhoan(string TenTaiKhoan);
        string getTenTaiKhoan();
        void setSoTaiKhoan(string SoTaiKhoan);
        string getSoTaiKhoan();

        void RutTien(double SoTien);
        void NapTien(double SoTien);
        double KiemTraSoDu();
        void HienThi();
};

    TaiKhoanNganHang :: TaiKhoanNganHang(string TenTaiKhoan, string SoTaiKhoan, double SoDu){
        SODU = SoDu;
        TENTAIKHOAN = TenTaiKhoan;
        SOTAIKHOAN = SoTaiKhoan;
    }
    void TaiKhoanNganHang :: setSoDu(double SoDu){
        SODU = SoDu;
    }
    double TaiKhoanNganHang :: getSoDu(){
        return SODU;
    }
    void TaiKhoanNganHang :: setTenTaiKhoan(string TenTaiKhoan){
        TENTAIKHOAN = TenTaiKhoan;
    }
    string TaiKhoanNganHang :: getTenTaiKhoan(){
        return TENTAIKHOAN;
    }
    void TaiKhoanNganHang :: setSoTaiKhoan(string SoTaiKhoan){
        SOTAIKHOAN = SoTaiKhoan;
    }
    string TaiKhoanNganHang :: getSoTaiKhoan(){
        return SOTAIKHOAN;
    }
    void TaiKhoanNganHang :: RutTien(double SoTien){
        if(SODU < SoTien){
            cout << "So tai khoan khong du" << endl;
        }
        else{
            SODU -= SoTien;
            printf("Rut tien thanh cong, so du hien tai cua ban la: %.2f\n", SODU);
        } 
    }
    void TaiKhoanNganHang :: NapTien(double SoTien){
            SODU +=SoTien;
            printf("Rut tien thanh cong, so du hien tai cua ban la: %.2f\n", SODU);;
        }
    double TaiKhoanNganHang :: KiemTraSoDu(){
            return SODU;
        }
    void TaiKhoanNganHang :: HienThi(){
        cout << "Thong tin tai khoan ngan hang: " << endl;
        cout << "Ten tai khoan: " << getTenTaiKhoan() << endl;
        cout << "So tai khoan: " << getSoTaiKhoan() << endl;
        printf("So du: %.2f\n", getSoDu());  
    }
    int main(int argc, char const *argv[])
    {
        
        TaiKhoanNganHang A("xx", "101344", 2000000);
        A.HienThi();
        A.RutTien(400000);
        A.NapTien(100000);
        A.RutTien(24500);
        printf("Kiem tra so du: %.2f\n", A.KiemTraSoDu());


        return 0;
    }
    