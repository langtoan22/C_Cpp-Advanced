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
        uint16_t MSV;
        string TEN;
        int TUOI;
        typeGioiTinh GIOI_TINH;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;
        double DIEM_TRUNG_BINH;
        typeHocLuc HOC_LUC;
    public: 
        SinhVien();
        SinhVien( string ten, int tuoi, typeGioiTinh gioitinh, double diemtoan, double diemly, double diemhoa);
        uint16_t getMsv();
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
    SinhVien :: SinhVien(){

    }

    SinhVien :: SinhVien( string ten, int tuoi, typeGioiTinh gioitinh, double diemtoan, double diemly, double diemhoa){
        
        static uint16_t msv = 100;
        msv ++;
        MSV = msv;

        TEN = ten;
        TUOI = tuoi;
        GIOI_TINH = gioitinh;
        DIEM_TOAN = diemtoan;
        DIEM_LY = diemly;
        DIEM_HOA = diemhoa;
        
    }
    uint16_t SinhVien :: getMsv(){
       
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
        cout << "Thong tin cua sinh vien: \n";
        cout << "Ma sinh vien: "<< getMsv() << endl;;
        cout << "Ten: "<<getTen() << endl;
        cout << "Tuoi: "<< getTuoi() << endl;
        cout << "Gioi tinh: " << getGioiTinh() << endl;
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
        void CapNhatThongTin();
        void XoaSinhVien();
        void TimKiemSinhVien();
        void SapXepSinhVienDTB();
        void SapXepSinhVienTheoTen();
        void HienThiDanhSach();
};

// Them sinh vien vao danh sach
    void Menu :: ThemSinhVien(){
        string TEN;
        int TUOI;
        typeGioiTinh GIOI_TINH;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;

        cout << "Nhap thong tin cua sinh vien: \n";
        cout << "Nhap ten cua sinh vien: ";
        cin >> TEN;
        cout << "Nhap tuoi cua sinh vien: ";
        cin >> TUOI;

        //Nhap gioi tinh cua sinh vien
        cout << "Nhap gioi tinh sinh vien(NAM/NU): ";
        string gt;
        do {
        cin >> gt;
        if( gt =="NAM"){
            GIOI_TINH = NAM;
        }
        else if (gt == "NU"){
            GIOI_TINH = NU;
        }
        else{
            cout << "Gioi tinh khong hop le, vui long nhap lai(NAM/NU)" << endl;
        }
        }while(gt != "NAM" && gt != "NU");
        
        // Nhap diem cua sinh vien
        do
        {
            cout << "Nhap vao diem TOAN: ";
            cin >> DIEM_TOAN;
            cout << "Nhap vao diem LY: ";
            cin >> DIEM_LY;
            cout << "Nhap vao diem HOA: ";
            cin >> DIEM_HOA;
            if (DIEM_TOAN < 0 || DIEM_TOAN > 10 || DIEM_LY < 0 || DIEM_LY > 10 || DIEM_HOA < 0 || DIEM_HOA > 10){
                cout << " Diem nhap vao khong hop le, vui long nhap lai!\n";
            }
        } while (DIEM_TOAN < 0 || DIEM_TOAN > 10 || DIEM_LY < 0 || DIEM_LY > 10 || DIEM_HOA < 0 || DIEM_HOA > 10);

        
            SinhVien sv (TEN, TUOI, GIOI_TINH, DIEM_TOAN, DIEM_LY, DIEM_HOA);        

            Database.push_back(sv);
        }   

// Cap nhat lai thong tin cua sinh vien bang msv
    void Menu :: CapNhatThongTin(){

        uint16_t MSV;
        string TEN;
        int TUOI;
        typeGioiTinh GIOI_TINH;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;

        cout << "Nhap msv cua sinh vien can cap nhat lai thong tin: ";
        cin >> MSV;

        for (SinhVien item : Database){
            if(MSV == item.getMsv()){
                cout << "Thong tin sinh vien: " << endl;
                item.getThongTin();

                cout << "Nhap tong tin can cap nhat cua sinh vien: \n";

                cout << "Nhap ten moi cua sinh vien: " << endl;
                cin >> TEN;
                item.setTen(TEN);

                cout << "Nhap tuoi moi cua sinh vien: "<< endl;
                cin >> TUOI;
                item.setTuoi(TUOI);

                // Nhap gioi tinh can cap nhat
                string gt;
                cout << "Nhap gioi tinh sinh vien(NAM/NU): " << endl;
                do {
                cin >> gt;
                if( gt =="NAM"){
                    GIOI_TINH = NAM;
                }
                else if (gt == "NU"){
                    GIOI_TINH = NU;
                }
                else{
                cout << "Gioi tinh khong hop le, vui long nhap lai(NAM/NU)" << endl;
                }
                }while(gt != "NAM" && gt != "NU");

                // Nhap diem can cap nhat
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
           
            item.setTen(TEN);
            item.setTuoi(TUOI);
            item.setDiemToan(DIEM_TOAN);
            item.setDiemLy(DIEM_LY);
            item.setDiemHoa(DIEM_HOA);

            item.getThongTin();

            return;
            }  
        }
        cout << "Khong tim thay msv: " << MSV << endl;
    }

// Xoa sinh vien bang msv
    void Menu :: XoaSinhVien(){
        int MSV;
        cout << "Nhap msv cua sinh vien can xoa: \n";
        cin >> MSV;
        
        list <SinhVien> :: iterator item;
        for(item = Database.begin(); item != Database.end(); ++item){
            if(MSV == item->getMsv()){
                item = Database.erase(item);
                cout << " Da xoa sinh vien co msv vua nhap thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay msv "<<MSV << endl;
    }

// Tim kiem sinh vien theo ten
    void Menu :: TimKiemSinhVien(){
        string TEN;
        cout << "Nhap ten cua sinh vien can tim:\n ";
        cin >> TEN;
        for(SinhVien item : Database){
            if(TEN == item.getTen()){
                item.getThongTin();
                return;
            }
        }
        cout << "Khong tim thay ten:" << TEN <<endl; 
    }

// Sap xep sinh vien theo diemTB
    void Menu :: SapXepSinhVienDTB(){

        // khai bao iterator i va j luu dia chi cua cac sinh vien trong pham vi list sinh vien
        list <SinhVien> :: iterator i, j;
        SinhVien temp;

        for(i = Database.begin() ; i != Database.end(); ++i ){
            for(j = i; j != Database.end(); ++j){
                if(i->getDiemTB() < j->getDiemTB()){
                    // hoa doi vi tri sinh vien
                    temp = *i;
                    *i = *j;
                    *j = temp;
                }
            }
        }
        // Hien thi danh sach sinh vien sau khi sap xep
        cout << "Danh sach sinh vien sau khi sap xep DTB:\n " ;
        for(i = Database.begin(); i != Database.end(); ++i){
             i->getThongTin();
        }
    }

// Sap xep sinh vien theo ten
    void Menu :: SapXepSinhVienTheoTen(){
        
    }
// Hien thi danh sach sinh vien
    void Menu :: HienThiDanhSach(){
        cout << "Danh sach cac sinh vien: \n";
        for(SinhVien item : Database){
            item.getThongTin();
        }
    }
    
    int main(int argc, char const *argv[])
    {
        int SoLuongsv = 2;
        Menu Menu1;

        for(int i = 0; i < SoLuongsv; i++){
            Menu1.ThemSinhVien();
        }

        Menu1.HienThiDanhSach();
        //Menu1.CapNhatThongTin();
        //Menu1.XoaSinhVien();
        //Menu1.TimKiemSinhVien();
        Menu1.SapXepSinhVienDTB();
        Menu1.SapXepSinhVienTheoTen();
         
        return 0;
    }
    