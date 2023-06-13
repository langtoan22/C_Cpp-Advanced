#include <iostream>
#include <string>

using namespace std;
class DoiTuong{
    public:
        string ten;
        int tuoi;
        int lop;
        void NhapThongTin(string ten, int tuoi, int lop);
        void HienThi();
};

    void DoiTuong :: NhapThongTin(string ten, int tuoi, int lop){
        DoiTuong :: ten = ten;
        DoiTuong ::lop = lop;
        DoiTuong :: tuoi = tuoi;
    }

    void  DoiTuong ::HienThi(){
        cout << "day la class DoiTuong:\n";
        cout <<"ten: " <<ten<<endl;
        cout <<"tuoi: " <<tuoi <<endl;
        cout <<"lop: " <<lop <<endl;
    }
// class SinhVien ke thua va ghi de class DoiTuong 
class SinhVien :public DoiTuong{
        public:
            int msv;
            void NhapThongTin(string ten, int tuoi, int lop, int msv); 
            void HienThi();
};

 void SinhVien :: NhapThongTin(string ten, int tuoi, int lop, int msv){
        SinhVien :: ten = ten;
        SinhVien ::lop = lop;
        SinhVien :: tuoi = tuoi;
        SinhVien :: msv = msv;
    }

    void  SinhVien ::HienThi(){
        cout << "day la class DoiTuong:\n";
        cout <<"ten: " <<ten<<endl;
        cout <<"tuoi: " <<tuoi <<endl;
        cout <<"lop: " <<lop <<endl;
        cout <<"msv: " <<msv <<endl;
    }

int main(int argc, char const *argv[])
{
    SinhVien sv1;

    sv1.NhapThongTin("Hoang", 17, 11, 202060456);
    sv1.HienThi();
    return 0;
}


