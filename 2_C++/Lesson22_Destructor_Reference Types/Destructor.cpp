#include <iostream>
#include <string>
 using namespace std;
 

class SinhVien {
    private:
        int ID;
        int *ptr;
        string name;
    public:
        SinhVien(){
            static int id = 100;
            ptr = &id;

            name ="SinhVien";
            name.push_back(id- '0');

            ID = id;
            id ++;
        }
        
        ~SinhVien(){
            *ptr = 100;
            cout << name << endl;
        }

        void display(){
            cout << "ID = " << ID << endl;
        }
};

class HocSinh{
    private:
        int ID;
        int *ptr;
        string name;
    public:
        HocSinh(){
            static int id = 1000;
            ptr = &id;
            name = "HocSinh";
             name.push_back(id- '0');

            ID = id;
            id ++;
        }

        ~HocSinh(){
            *ptr = 1000;
            cout << name << endl;
        }

        void display(){
                cout << "ID = " << ID <<endl;
            }
};

void test1(){
    SinhVien sv1, sv2, sv3, sv4;
    sv1.display();
    sv2.display();
    sv3.display();
    sv4.display();

    HocSinh hs1;
    hs1.display();

    /*
    constructor được khởi tạo
    ID = 100 
    ID = 101 
    ID = 102 
    ID = 103 
    ID = 1000

    destructor được gọi
    HocSinh  
    SinhVien7
    SinhVien6
    SinhVien5
    SinhVien4
    */

   // Mỗi một object sẽ được gọi destructor một lần, và destructor sẽ huỷ theo thứ tự ngược lại với  constructor khởi tạo
}

void test2(){
    SinhVien sv;
    sv.display();

    HocSinh hs1, hs2;
    hs1.display();
    hs2.display();

    /*
    constructor được khởi tạo
    ID = 100 
    ID = 1000
    ID = 1001

    destructor được gọi
    HocSinh  
    HocSinh  
    SinhVien4
    */

   //   // Mỗi một object sẽ được gọi destructor một lần, và destructor sẽ huỷ theo thứ tự ngược lại với  constructor khởi tạo
}

int main(int argc, char const *argv[])
{
    test1();
    test2();

    return 0;
}
