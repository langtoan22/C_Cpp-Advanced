# C_Cpp-Advanced

#BAI1

- Ngôn ngữ bậc cao --Compiler--> Ngôn ngữ bậc thấp
  (c/c++, java...)             (nhị phân, ngôn ngữ mtinh)

- Quá trình tiền xử lý: 


        .C/.H(source file) --preprocessor--> .I(preprocessed,source) --assembler--> .S(assemply code)

                 .exe(executable) <--linker--  .O(object file, libraries) <--compiler--    



- Preprocessor: gcc -E file1.c -o file1.i

- Compiler:     gcc file.i -S -o file1.s

- Assembler:    gcc -c file1.s -o file1.o
                gcc file1.c -o file1.o

- Linker:       gcc file1.o -o file

- Cấu trúc của một chương trình:

    #include<stdio.h> (thư viện, có thể là một file khác với include"file1")

    #define Max 10 (macro)

    //this is function
        void test(){
            prinf("this is function");
        }
    int main(){
        {
            test();
            return 0;
        }
    }




#BAI2_MACRO

#ifndef value 

    value(leybel): được khởi tạo với một giá trị

    ifdef(if not define): kiểm tra value được định nghĩa hay chưa

#endif  (đóng)


#ifdef value

    ifdef: ngược lại ifndef, viết tiếp với value đã được định nghĩa

#endif

vidu:

    #define value int_int##name;
                  char_char##name;
                  double_double##name;
    int main(){
        value(biến);
    }

=> thay vì tạo 3 biến trong macro ta có thể làm như trên.




#BAI3_INPUT

- sử dụng thư viện include_stdarg

#include_stdio.h
#include_stdarg

void ten (int SoLuong_input,...){

        //(...): thể hiện các giá trị đằng sau

        //va_list sometext (lưu trữ các biến đối số(...)được truyền vào hàm "ten")

        //va_start (sometext, SoLuong_input): Dùng để bắt đầu truy cập vào danh sách các biến đối số và cập nhật con trỏ đến vị trí đầu tiên trong danh sách.
        
        
for(int i = 0; i < SoLuong_input; i++)
{
    printf("hjksdf: %d\n", va_arg(va, int));

        //va_arg: dùng để lấy giá trị từng biến và cập nhật vị trí con trỏ trong danh sách

}

}

int main()
{
    ten(5(SoLuong_input), 2, 4, 3, 6, 1);
    return 0;
}




#BAI4_VARIABLE

Sử dụng thư viện stdint.h để dùng các kiểu dữ liêu uint _t

/Biến static(4_1.main):

- Biến cục bộ bình thường: sau khi gọi thì biến khởi tạo giá trị biến và sẽ thu hồi địa chỉ trên bộ nhớ Ram khi chương trình kết thúc khỏi biến đó, lần thứ hai gọi biến thì chương trình sẽ khởi tạo lại giá trị biến từ đầu và có thể giống hoặc không địa chỉ trên bộ nhớ so với lần gọi đầu.

    vidu: uint8_t temp = 0;
            printf("temp: %d\n", temp);
            temp++;

- Biến cục bố dùng static: khi gọi thì biến khởi tạo giá trị chỉ một lần và cố định địa chỉ giá trị đó tồn tại hết vòng đời của chương trình(sau khi kết thúc thì mới thu hồi lại địa chỉ trên bộ nhớ Ram), và lần gọi thứ hai của biến thì giá trị sẽ được tiếp tục.

    vidu:   static uint8_t temp = 0;
            printf("temp: %d\n", temp);
            temp++;

- Biến toàn cục static chỉ có giá trị trong phạm vi file chứa nó, không extern sang file khác được còn biến cục bộ thì được.

/Extern(4_2_test.c, 4_3_extern.c):

- ta có file1 có biến int a và file2. khi ta muốn sử dụng int a của file1 vào file2 thì dùng extern (extern int a)

- không được khởi tạo, giá trị biến tại file extern chỉ được gọi, chỉ được ở file (test)

- vì runcode chỉ build được một file duy nhất nên ta dùng:

    (gcc file1.c file2.c -o file1) file1 là file dùng extern.

    gcc 4_3_extern.c 4_2_test.c -o 4_3_extern 

    ./4_3_extern (./file1)

/Register

- ALU(bộ xử lý tính toán), Register(thanh ghi), RAM  (cấu trúc vi xử lý gồm RAM và Register)
    vidu: int a = 5;
          a++;
          
          RAM(a=5) -> Register(a=5 và phép toán) -> ALU(thực hiện a++ =6)
                                                    
          RAM(nhận kết quả từ Register) <- Register(nhận kết quả từ ALU) <-

- vì Register có bộ nhớ giới hạn nên chỉ ưu tiên dùng Register cho những biến cần tốc độ xử lý cao, còn lại tất cả được lưu trên RAM.

/Volatile
- Thông báo cho compiler không tối ưu hàm đã được khởi tạo sẵn( sử dụng giá trị đã được khởi tạo từ trước)




#BAI5_PHANVUNGNHO(MCU)(trenRAM)

vidu: 
        int a; (.bss)
        int b = 42; (.data)

    void main(void)  (.text)
    {
        int c;
        a=10;
        cong(a,b);
    }

==> sections

- Phân vùng nhớ gồm hai vùng nhớ là Flash và RAM:

    + Flash: khi mất nguồn điện thì vẫn lưu các chương trình
    + RAM : Độ truy xuất nhanh nhưng khi mất nguồn điện thì sẽ mất hết các chương trình đang chạy

- Trong bộ nhớ RAM sẽ có 5 phân vùng nhớ: text, data, bss, heap, stack

    + Text(text segment)(5.1_const):  

        * Chỉ có quyền Read và không có quyền sửa;
        * Chứa lệnh thực thi chương trình;
        * Hằng số sẽ được lưu ở phân vùng text (.rodata);

     void main(void)  (.text)
      {
        int c;
        a=10;
        cong(a,b);
      }


    + Data (Initialized Data segment)(5.2_Data):   

        * Có quyền Read và write(đọc và sửa);
        * Chứa biến toàn cục hoặc biến static được khởi tạo
        với giá trị khác 0 (global and static variables);
        * Được giải phóng khi kết thúc chương trình ;

        vidu: int global = 100;
              static int = 100;

        Chú ý: căn cứ giá trị gán ở lần đầu tiên để phân vùng

            vidu: static uint8_t test = 21; sau có thay đổi giá trị 21 = 0 thì vẫn được lưu ở Data

    + bss (uninitialized Data segment): 

        * Có quyền Read và write(đọc và sửa);
        * Chứa biến toàn cục hoặc biến static được khởi ;tạo với giá trị = 0 hoặc không khởi tạo(ngược lại với Data);
        * Được giải phóng khi kết thúc chương trình; 

        vidu: int global;
              static int = 0;


        Chú ý: căn cứ giá trị gán ở lần đầu tiên để phân vùng
            vidu: static uint8_t test = 0; sau có thay đổi giá trị 0 = 21 thì vẫn được lưu ở bss


    + Stack(Automatic Variable Storage_cấp phát bộ nhớ tự động)(5.3_Stack):     

        * Có quyền Read và write(đọc và sửa); 
        * Được sử dụng cấp phát cho biến local(cục bộ):
            input parameter
            Được khai báo bên trong một block code '{'và'}'
        * Sẽ được giải phóng khi ra khỏi block code/hàm;


    + Heap(Dynamic Memory allocation_cấp phát bộ nhớ động):(5.5_Heap):       

        * Có quyền Read và write(đọc và sửa); 
        * Được sử dụng để cấp phát bộ nhớ động như: Malloc, calloc...; 
        * Sẽ giải phóng khi gọi hàm free...; 

        Phân vùng heap không có cơ chế thu hồi bộ nhớ mà phải dùng đến hàm free (5.7.c)