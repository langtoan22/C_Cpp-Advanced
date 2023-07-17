#include <iostream>

class sinhvien{
    public:
        virtual char* string(){
            return (char*)"hello world\n";
        }

        void HienThi(){
            printf("test: %s", string());
        }

        virtual void test (){
            printf("day la class sinhvien");
        }
};

class hocsinh : public sinhvien{
    public: 
        char* string(){
            return (char*)"hello\n";
        }

        void test (){
            printf("day la class hocsinh");
        }
};

int main(int argc, char const *argv[])
{
    sinhvien sv;
    hocsinh hs;

    sv.HienThi();

//vi day van dung phuong thuc cua class sinhvien nên van in ra hello word
    hs.HienThi();

//khi nay class hoc sinh da su dung phuong thu cua ghi de nen in ra hello
    printf("test: %s ", hs.string());
//khi dung virtual cho class sinh vien thi đó được coi là hàm ảo nên phần phương thức hienthi sẽ load lại vào class hocsinh khi đã đc định nghĩa và ghi đè
    hs.HienThi();


    sinhvien *ptr;
// vì class hocsinh đang kế thừa và ghi đè từ class sinhviên nên phân vùng địa chỉ của hs chính là của sv
    ptr = &hs;
// khi dùng virtual tại class sinhvien thì class hocsinh mới được load mới  
    ptr -> test();
    return 0;
}