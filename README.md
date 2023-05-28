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

Sử dụng thư viện stdint.h để dùng các kiểu dữ liêu uint _t(kích thước của biến)

uint8_t = 1 byte
uint16_t = 2 byte

/Biến static(4_1.main):

- Biến cục bộ bình thường: sau khi gọi thì biến khởi tạo giá trị biến và sẽ thu hồi địa chỉ trên bộ nhớ Ram khi chương trình kết thúc khỏi biến đó, lần thứ hai gọi biến thì chương trình sẽ khởi tạo lại giá trị biến từ đầu và có thể giống hoặc không địa chỉ trên bộ nhớ so với lần gọi đầu.

    vidu: uint8_t temp = 0;
            printf("temp: %d\n", temp);
            temp++;

- Biến cục bộ dùng static: khi gọi thì biến khởi tạo giá trị chỉ một lần và cố định địa chỉ giá trị đó tồn tại hết vòng đời của chương trình(sau khi kết thúc thì mới thu hồi lại địa chỉ trên bộ nhớ Ram), và lần gọi thứ hai của biến thì giá trị sẽ được tiếp tục.

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
            
            nằm trong hàm main nhưng khai báo với viến static

              int main(){
                static int = 100;
              }

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
            Được khai báo bên trong một block code '{'và'}' (vidu ham main(){this code})
        * Sẽ được giải phóng khi ra khỏi block code/hàm;


    + Heap(Dynamic Memory allocation_cấp phát bộ nhớ động):(5.5_Heap):       

        * Có quyền Read và write(đọc và sửa); 
        * Được sử dụng để cấp phát bộ nhớ động như: Malloc, calloc...; 
        * Sẽ giải phóng khi gọi hàm free...; 

        Phân vùng heap không có cơ chế thu hồi bộ nhớ mà phải dùng đến hàm free (5.7.c)



#BAI6_STRUCT_UNION

/STRUCT(6_1_struct.c)

- Là kiểu dữ liệu do người dùng tự định nghĩa giống như int, double
- Sử dụng typedef để định nghĩa ngắn gọn lại

vidu: 
            typedef struct
            {
                int ngay;
                int thang;
                int nam;
            }typeDate;

/Sizeof_Struct(6_2_SizeofStruct.c):

- căn cứ vào member có kích thước lớn nhất để lấy kích thước lớn nhất cho từng member sau mỗi lần quét các member đó.

    Ta có kích thước byte lớn nhất của các lần quét là là Z byte

    + Quét "lần 1" có X byte: gồm có A byte sử dụng và B byte bộ nhớ đệm trong Z byte.
    
    + Quét "lần 2" có Y byte, nhưng so sánh kích thước của B byte bộ nhớ đệm lần quét 1 và kích thước lần quét 2.

        * Nếu kích thước lần quét 2 nhỏ hơn kích thước Zbyte bộ nhớ đệm lần quét 1 thì ta đưa "lần 2" vào sử dụng bộ nhớ đệm của lần quét 1.
        * Nếu kích thước lần quét 2 lớn hơn kích thước Zbyte bộ nhớ đệm lần quét 1 thì phải sử dụng kích thước lần quét 2 là Z byte.
    + Các lần quét tiếp theo tương tự

    vidu:

Căn cứ vào member có kích thước lớn nhất là "thang"=4 byte nên mỗi lần quét các member khác cũng có kích thước lớn nhất là 4byte

    uint8_t ngay;//1 byte = 1 byte + 3byte bộ nhớ đệm = 4 byte (sử dụng 1byte + 3 byte không sử dụng đến)

    So sánh thì lần quét 2 bằng 4 lớn hơn 3byte bộ nhớ đệm lần quét 1 ==> sử dung kích thước lần quét 2

    uint32_t thang;//4 byte = 4 byte (sử dụng hết 4 byte)

    Vì kích thước lần quét 2 đã sử dụng hết nên quét 3 ta sử dụng kích thước của lần quét 3.

    uint16_t nam;//2 byte = 2 byte + 2byte bộ nhớ đệm = 4 byte(sử dụng 2 byte + 2 byte không sử dụng đến)

==>sizeof ngay,thang và nam là:(1byte + 3byte bộ nhớ đệm) +  4byte + (2byte + 2byte bộnhớ đệm) = 12byte


vidu 2:

    uint8_t ngay;//1 byte = 1 byte + 7 byte bộ nhớ đệm= 8 byte
    uint64_t tuan;// 8 byte = 8 byte
    uint16_t nam;// 2 byte = 2 byte + 6 byte bộ nhớ đệm = 2 byte + 4 byte + 2 byte bộ nhớ đệm = 8 byte 
    uint32_t thang;// 4 byte = 0 

Kích thước mỗi lần quét lớn nhất là 8 byte.

    uint8_t ngay;// 1 byte = 1 byte + 7 byte đệm
        So sánh thấy 7 byte đệm của "ngay" không chứa đủ 8 byte của "tuan" nên kích thước của "tuan" là 8byte sau lần quét thứ 2.
    uint64_t tuan;// 8byte = 8 byte
        Kích thước của "tuan" được sử dụng hết nên kích thước "thang" được sử dụng trong 8 byte sau lần quét thứ 3.
    uint16_t thang;// 2 byte = 2 byte + 6 byte đệm
        Ta có 6 byte bộ đệm của "thang" chứa đủ 4 byte của "nam" nên 4 byte của "nam" được sử dụng ở trong 6 byte bộ đệm của "thang".
        ==>2 byte + 4 byte + 2 byte bộ nhớ đệm.
    uint32_t nam;// 4 byte = 0

==> sizeof = 24byte


vidu 3:

        uint8_t ngay[3];//1 byte = 3 byte + 1 byte đệm =  4 byte
        uint16_t nam[4];// 2byte = 8 byte 
        uint32_t thang[5];// 4 byte = 20 byte

kích thước mỗi lần quét là 4byte;

        uint8_t ngay;// 1byte
        uint8_t ngay;// 1byte
        uint8_t ngay;// 1byte
        ==> 3 byte + 1byte đệm = 4 byte

        uint16_t nam;//2byte
        uint16_t nam;//2byte
        uint16_t nam;//2byte
        uint16_t nam;//2byte
        ==> 4 byte + 4 byte = 8 byte

        uint32_t thang;//4byte
        uint32_t thang;//4byte
        uint32_t thang;//4byte
        uint32_t thang;//4byte
        uint32_t thang;//4byte
        ==> 20 byte

==> sizeof = 32 byte

vidu 4: 

kích thước mỗi lần quét là 4 byte.

        uint8_t ngay[3];//1 byte = 3byte + 1 byte đệm = 4 byte
        uint32_t thang[4];//4 byte = 16 byte
        uint16_t nam[5];// 2 byte = 8 byte + (2 byte + 2 byte bộ đệm) = 12 byte

==> sizeof = 32 byte

vidu 5: 

        kích thước mỗi lần quét là 8 byte: 
        uint8_t ngay[3];//1 byte = 3 byte + 5 byte đệm = 8 byte
        uint32_t thang[4];// 4 byte 
        = 4 byte lần đầu sử dụng trong 5 byte bộ đệm của "ngay" (3 byte + 4 byte + 1 byte đệm)
        2*4 =8 byte + (4 byte + 4 byte đệm) = 16 byte

        unit64_t tuan[3];//8 byte = 3 * 8 =  24 byte
        uint16_t nam[5];// 2byte = 2*4 =  8 byte + (2 byte + 6 byte đệm) = 16 byte

==> sizeof = 64 byte

/UNION(6_3_union.c)

- Giống như Struct, Union cũng là kiểu dữ liệu do ngườ dùng tự định nghĩa. 
- Giá trị của các biến trong Union đều giống nhau và bằng giá trị của biến được khởi tạo cuối cùng vì các biến trong Union đều cùng một địa chỉ nên khi khởi tạo thì giá trị sau sẽ ghi đè lên giá trị trước.

- Kích thước của Union là kích thước của member lớn nhất.

    vidu:

                #include <stdio.h>
                #include <stdint.h>
                #include <string.h>

                typedef union 
                {

                uint8_t var1[5]; // char
                uint16_t var2[2]; // long

                }typeData;

                int main(int argc, char const *argv[])
                {
                    typeData data ;

                    for(int i = 0; i < 5; i++){
                        data.var1[i] = i; // 0 1 2 3 4
                    }

                    for(int i = 0; i < 2; i++){
                        data.var2[i] = 2*i ;  // 0 2
                    }

                    for(int i = 0; i < 5 ; i++){
                        printf("test1: %d\n", data.var1[i]);
                    }
                
                    return 0;
                }


kết quả là: 0 0 2 0 4
- var1 có kết quả là: 0 1 2 3 4 (var1 có giá trị 1 byte nên mỗi ô là một giá trị i)
- var2 có kết quả là: 0 0 2 0 (vì var 2 có giá trị là 2 byte nên ô lưu trữ đầu tiên là giá trị i và ô lưu trữ thứ 2 là giá trị 0)
- do cùng một địa chỉ nên var2 sẽ ghi đè lên var1 sau đó var2 = var1 
- do đó kết quả cuối cùng là: 0 0 2 0 4


/TỔNG KẾT.

        - Struct:
            + là kiểu dữ liệu do người dùng tự định nghĩa;
            + Kích thước là tổng các member cộng lại (byte sử dụng và byte bộ nhớ đệm);
            + Mỗi member của struct đều có địa chỉ riêng nên khi thay đổi giá trị của một member thì không ảnh hưởng đến member khác.

        - Union:
            + là kiểu dữ liệu do người dùng tự định nghĩa;
            + Kích thước của union sẽ là kích thước của member lớn nhất;
            + Các member trong Union đều dùng chung một địa chỉ nên khi thay đổi một giá trị member thì sẽ ảnh hưởng đến giá trị các member khác

#BAI7_GOTO

/GOTO(7_1_GOTO.c)

- Cung cấp 1 bước nhảy từ 'goto' đến một câu lệnh có label
- label có thể là một văn bản thuần túy trừ từ khóa C, label có thể được đặt ở bất kì đâu trong chương trình có thể ở trên hoặc dưới câu lệnh 'goto'.

            vidu:

            label:
            statement(
            goto labe:
            )
/EXIT(7_2_EXIT.c)

- Sử dụng thư viện stdlib.h để dùng Exit
- Exit: dừng lại chương trình chứ không thoát khỏi


/SETJUM(7_3_SETJUM.C)

- Sử dụng thư viện setjmp.h để dùng setjum
- sử dụng setjmp với TRY CATCH THROW để khi chương trình có lỗi thì mọi sẽ dừng lại đê ưu tiên xử lý lỗi trước và trỏ con trỏ đến vùng lỗi để xử lý (rất phức tạp khi không dùng setjmp ở các vòng lặp)