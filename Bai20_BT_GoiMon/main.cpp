#include <iostream>
#include <list>
using namespace std;

class Mon {
    private:
        uint8_t ID;
        string TEN;
        double GIA;
    public:
        Mon(string ten, double gia);
        uint8_t getID();
        void setTen(string ten);
        string getTen();
        void setGia(double gia);
        double getGia();
        void getThongTin();
};

    Mon :: Mon(string ten, double gia){
        static uint8_t id = 100;
        id ++;
        ID = id;
        TEN = ten;
        GIA = gia;
    }

    uint8_t Mon :: getID(){
        return ID;
    }

    void Mon :: setTen(string ten){
        TEN = ten;
    }
   
    string Mon :: getTen(){
        return TEN;
    }

    void Mon :: setGia(double gia){
        GIA = gia;
    }
    double Mon :: getGia(){
        return GIA;
    }
    
    void Mon :: getThongTin(){
        cout << "Ten mon:" << getTen() << "Gia mon:" << getGia() << endl;
    }
class QuanLy {
    private:
        list <Mon> DATABASE;
        uint8_t SO_BAN;
        void ThemMon();
        void SuaMon();
        void XoaMon();
        void DanhSachMon();
        void ThietLapSoBan(uint8_t so_ban);
    public:
        QuanLy();
        uint8_t getSoBan();
        list <Mon> getDatabase();
};

    QuanLy:: QuanLy(){

    }

    uint8_t QuanLy :: getSoBan(){
        return SO_BAN;
    }

    list <Mon> QuanLy :: getDatabase(){
        return DATABASE;
    }

    void QuanLy :: ThemMon(){
        string TEN;
        double GIA;
        uint8_t ID;

        cout << "Nhap thong tin mon: \n";
        cout << "Nhap ten mon: ";
        cin >> TEN;
        cout << "Nhap gia mon: ";
        cin >> GIA;
        Mon mon(TEN, GIA);
        DATABASE.push_back(mon);
    }

    void QuanLy :: SuaMon(){
        uint8_t ID;
        string TEN;
        double GIA;

        cout << "Nhap ID mon can sua: \n";
        cin >> ID;
        for(Mon item : DATABASE){
            if(ID == item.getID()){
                item.getThongTin();
                cout << "Nhap ten mon can sua: ";
                cin >> TEN;
                cout << "Nhap gia mon can sua: ";
                cin >> GIA;

                item.setTen(TEN);
                item.setGia(GIA);
                break;
            }
        }
        cout << "Khong tim thay mon co id: " << ID << endl;
        
    }

    void QuanLy :: XoaMon(){
        uint8_t ID;
        cout << "Nhap ID mon can xoa: \n";
        cin >> ID;
        list <Mon> :: iterator item;
        for(item = DATABASE.begin(); item != DATABASE.end(); ++item){
            if(ID == item->getID()){
                item = DATABASE.erase(item);
                cout << "Da xoa sinh vien thanh cong: \n";
                break;
            }
        }
        cout << "khong tim thay mon co ID: " << ID << endl;
    }

    void QuanLy :: DanhSachMon(){
        cout << "Danh sach cac mon: \n";
        for(Mon item : DATABASE){
            item.getThongTin();
        }
    }

class NhanVien{

};