# C_Cpp-Advanced

# BÀI 1:

- Ngôn ngữ bậc cao (c/c++, java...) --Compiler--> Ngôn ngữ bậc thấp (nhị phân, ngôn ngữ mtinh)
               

- Quá trình tiền xử lý: 

  ![quá trình tiền xử lý](https://github.com/langtoan22/image_C_Cpp_Advanced/blob/main/bai1_QuaTrinhTienXuLy.png?raw=true)

        - Preprocessor: gcc -E file1.c -o file1.i

        - Compiler:     gcc file.i -S -o file1.s

        - Assembler:    gcc -c file1.s -o file1.o hoặc gcc file1.c -o file1.o

        - Linker:       gcc file1.o -o file

- Cấu trúc của một chương trình:

'''

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
'''




# BAI2_MACRO

    #ifndef value 

        value(leybel): được khởi tạo với một giá trị

        ifndef(if not define): kiểm tra value được định nghĩa hay chưa

    #endif  (đóng)

    VÀ

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
# BAI3_INPUT

- sử dụng thư viện include_stdarg

'''

    #include_stdio.h
    #include_stdarg

    void ten (int SoLuong_input,...)
    {

    for(int i = 0; i < SoLuong_input; i++)
    {
        printf("hjksdf: %d\n", va_arg(va, int));

    }

    }
    int main()
    {
        ten(5(SoLuong_input), 2, 4, 3, 6, 1);
        return 0;
    }
'''

- (...): thể hiện các giá trị đằng sau

- va_list sometext (lưu trữ các biến đối số(...)được truyền vào hàm "ten")

- va_start (sometext, SoLuong_input): Dùng để bắt đầu truy cập vào danh sách các biến đối số và cập nhật con trỏ đến vị trí đầu tiên trong danh sách.
-  va_arg: dùng để lấy giá trị từng biến và cập nhật vị trí con trỏ trong danh sách

# BAI4_VARIABLE

Sử dụng thư viện **stdint.h** để dùng các kiểu dữ liêu uint_t (kích thước của biến)

        uint8_t = 1 byte
        uint16_t = 2 byte

## 1. Biến static(4_1.main):

- Biến cục bộ bình thường: sau khi gọi thì biến khởi tạo giá trị biến và sẽ thu hồi địa chỉ trên bộ nhớ Ram khi chương trình kết thúc khỏi biến đó, lần thứ hai gọi biến thì chương trình sẽ khởi tạo lại giá trị biến từ đầu và có thể giống hoặc không địa chỉ trên bộ nhớ so với lần gọi đầu.

**vidu:**      

            uint8_t temp = 0;
            printf("temp: %d\n", temp);
            temp++;

- Biến cục bộ dùng static: khi gọi thì biến khởi tạo giá trị chỉ một lần và cố định địa chỉ giá trị đó tồn tại hết vòng đời của chương trình(sau khi kết thúc thì mới thu hồi lại địa chỉ trên bộ nhớ Ram), và lần gọi thứ hai của biến thì giá trị sẽ được tiếp tục.

**vidu:**   

            static uint8_t temp = 0;
            printf("temp: %d\n", temp);
            temp++;

- Biến toàn cục static chỉ có giá trị trong phạm vi file chứa nó, không extern sang file khác được còn biến cục bộ thì được.

## 2. Extern(4_2_test.c, 4_3_extern.c):

- ta có file1 có biến int a và file2. khi ta muốn sử dụng int a của file1 vào file2 thì dùng extern (extern int a)

- không được khởi tạo, giá trị biến tại file extern chỉ được gọi, chỉ được ở file (test)

- vì runcode chỉ build được một file duy nhất nên ta dùng:

            (gcc file1.c file2.c -o file1) file1 là file dùng extern.

            gcc 4_3_extern.c 4_2_test.c -o 4_3_extern 

            ./4_3_extern (./file1)

## 3.Register

- ALU(bộ xử lý tính toán), Register (thanh ghi), RAM (cấu trúc vi xử lý gồm RAM và Register)


![minh họa register](https://github.com/langtoan22/image_C_Cpp_Advanced/blob/main/bai4_Register.png?raw=true)


**vidu**: int a = 5; a++;

![](https://github.com/langtoan22/image_C_Cpp_Advanced/blob/main/bai4_Register1.png?raw=true)
      

- vì Register có bộ nhớ giới hạn nên chỉ ưu tiên dùng Register cho những biến cần tốc độ xử lý cao, còn lại tất cả được lưu trên RAM.

## 4. Volatile
- Thông báo cho compiler không tối ưu hàm đã được khởi tạo sẵn( sử dụng giá trị đã được khởi tạo từ trước)




# BAI5_PHANVUNGNHO(MCU)(trenRAM)

![](https://github.com/langtoan22/image_C_Cpp_Advanced/blob/main/bai5_PhanVungNho.png?raw=true)



**vidu**: 
'''

    int a; (.bss)
    int b = 42; (.data)

    void main(void)  (.text)
    {
        int c;
        a=10;
        cong(a,b);
    }
'''
==> sections

Phân vùng nhớ gồm hai vùng nhớ là Flash và RAM:

    Flash: khi mất nguồn điện thì vẫn lưu các chương trình
    RAM : Độ truy xuất nhanh nhưng khi mất nguồn điện thì sẽ mất hết các chương trình đang chạy

Trong bộ nhớ RAM sẽ có 5 phân vùng nhớ: text, data, bss, heap, stack

## 1. Text(text segment)(5.1_const):  

- Chỉ có quyền Read và không có quyền sửa;
- Chứa lệnh thực thi chương trình;
- Hằng số sẽ được lưu ở phân vùng text (.rodata);
    **vidu**
        void main(void)  (.text)
        {
            int c;
            a=10;
            cong(a,b);
        }



## 2. Data (Initialized Data segment)(5.2_Data):   

- Có quyền Read và write(đọc và sửa);
- Chứa biến toàn cục hoặc biến static được khởi tạo
- với giá trị khác 0 (global and static variables);
- Được giải phóng khi kết thúc chương trình ;

    **vidu**: 

            int global = 100;
            static int = 100;
            
        nằm trong hàm main nhưng khai báo với biến static

            int main(){
            static int = 100;
            }

    **Chú ý**: căn cứ giá trị gán ở lần đầu tiên để phân vùng

        vidu: static uint8_t test = 21; sau có thay đổi giá trị 21 = 0 thì vẫn được lưu ở Data

## 3. bss (uninitialized Data segment): 

- Có quyền Read và write(đọc và sửa);
- Chứa biến toàn cục hoặc biến static được khởi ;tạo với giá trị = 0 hoặc không khởi tạo(ngược lại với Data);
- Được giải phóng khi kết thúc chương trình; 

    **vidu:** 

            int global;
            static int = 0;


    **Chú ý:** căn cứ giá trị gán ở lần đầu tiên để phân vùng

        vidu: static uint8_t test = 0; sau có thay đổi giá trị 0 = 21 thì vẫn được lưu ở bss


## 4. Stack(Automatic Variable Storage_cấp phát bộ nhớ tự động)(5.3_Stack):     

- Có quyền Read và write(đọc và sửa); 
- Được sử dụng cấp phát cho biến local(cục bộ):
    + input parameter
    + Được khai báo bên trong một block code '{'và'}' (vidu ham main(){this code})
- Sẽ được giải phóng khi ra khỏi block code/hàm;

## 5. Heap(Dynamic Memory allocation_cấp phát bộ nhớ động):(5.5_Heap):       

- Có quyền Read và write(đọc và sửa); 
- Được sử dụng để cấp phát bộ nhớ động như: Malloc, calloc...; 
- Sẽ giải phóng khi gọi hàm free...; 

- Phân vùng heap không có cơ chế thu hồi bộ nhớ mà phải dùng đến hàm free (5.7.c)



# BAI6_STRUCT_UNION
## 1. STRUCT(6_1_struct.c)

- Là kiểu dữ liệu do người dùng tự định nghĩa giống như int, double
- Sử dụng typedef để định nghĩa ngắn gọn lại

**vidu:** 


            typedef struct
            {
                int ngay;
                int thang;
                int nam;
            }typeDate;

## 2. Sizeof_Struct(6_2_SizeofStruct.c):

- căn cứ vào member có kích thước lớn nhất để lấy kích thước lớn nhất cho từng member sau mỗi lần quét các member đó.

    Ta có kích thước byte lớn nhất của các lần quét là là Z byte

    + Quét "lần 1" có X byte: gồm có A byte sử dụng và B byte bộ nhớ đệm trong Z byte.
    
    + Quét "lần 2" có Y byte, nhưng so sánh kích thước của B byte bộ nhớ đệm lần quét 1 và kích thước lần quét 2.

        * Nếu kích thước lần quét 2 nhỏ hơn kích thước Zbyte bộ nhớ đệm lần quét 1 thì ta đưa "lần 2" vào sử dụng bộ nhớ đệm của lần quét 1.
        * Nếu kích thước lần quét 2 lớn hơn kích thước Zbyte bộ nhớ đệm lần quét 1 thì phải sử dụng kích thước lần quét 2 là Z byte.
    + Các lần quét tiếp theo tương tự

    **vidu:**

Căn cứ vào member có kích thước lớn nhất là "thang"=4 byte nên mỗi lần quét các member khác cũng có kích thước lớn nhất là 4byte

    uint8_t ngay;//1 byte = 1 byte + 3byte bộ nhớ đệm = 4 byte (sử dụng 1byte + 3 byte không sử dụng đến)

    So sánh thì lần quét 2 bằng 4 lớn hơn 3byte bộ nhớ đệm lần quét 1 ==> sử dung kích thước lần quét 2

    uint32_t thang;//4 byte = 4 byte (sử dụng hết 4 byte)

    Vì kích thước lần quét 2 đã sử dụng hết nên quét 3 ta sử dụng kích thước của lần quét 3.

    uint16_t nam;//2 byte = 2 byte + 2byte bộ nhớ đệm = 4 byte(sử dụng 2 byte + 2 byte không sử dụng đến)

==>sizeof ngay,thang và nam là:(1byte + 3byte bộ nhớ đệm) +  4byte + (2byte + 2byte bộnhớ đệm) = 12byte


**vidu 2:**

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


**vidu 3:**

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

**vidu 4:** 

kích thước mỗi lần quét là 4 byte.

        uint8_t ngay[3];//1 byte = 3byte + 1 byte đệm = 4 byte
        uint32_t thang[4];//4 byte = 16 byte
        uint16_t nam[5];// 2 byte = 8 byte + (2 byte + 2 byte bộ đệm) = 12 byte

==> sizeof = 32 byte

**vidu 5:** 

        kích thước mỗi lần quét là 8 byte: 
        uint8_t ngay[3];//1 byte = 3 byte + 5 byte đệm = 8 byte
        uint32_t thang[4];// 4 byte 
        = 4 byte lần đầu sử dụng trong 5 byte bộ đệm của "ngay" (3 byte + 4 byte + 1 byte đệm)
        2*4 =8 byte + (4 byte + 4 byte đệm) = 16 byte

        unit64_t tuan[3];//8 byte = 3 * 8 =  24 byte
        uint16_t nam[5];// 2byte = 2*4 =  8 byte + (2 byte + 6 byte đệm) = 16 byte

==> sizeof = 64 byte

## 3. UNION(6_3_union.c)

- Giống như Struct, Union cũng là kiểu dữ liệu do ngườ dùng tự định nghĩa. 
- Giá trị của các biến trong Union đều giống nhau và bằng giá trị của biến được khởi tạo cuối cùng vì các biến trong Union đều cùng một địa chỉ nên khi khởi tạo thì giá trị sau sẽ ghi đè lên giá trị trước.

- Kích thước của Union là kích thước của member lớn nhất.

    **vidu:**

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


## 4. TỔNG KẾT.

Struct:
- là kiểu dữ liệu do người dùng tự định nghĩa;
- Kích thước là tổng các member cộng lại (byte sử dụng và byte bộ nhớ đệm);
Mỗi member của struct đều có địa chỉ riêng nên khi thay đổi giá trị của một member thì không ảnh hưởng đến member khác.

Union:
- là kiểu dữ liệu do người dùng tự định nghĩa;
- Kích thước của union sẽ là kích thước của member lớn nhất;
Các member trong Union đều dùng chung một địa chỉ nên khi thay đổi một giá trị member thì sẽ ảnh hưởng đến giá trị các member khác

# BAI7_GOTO

## 1. GOTO(7_1_GOTO.c)

- Cung cấp 1 bước nhảy từ 'goto' đến một câu lệnh có label
- label có thể là một văn bản thuần túy trừ từ khóa C, label có thể được đặt ở bất kì đâu trong chương trình có thể ở trên hoặc dưới câu lệnh 'goto'.

    **vidu:**

            label:
            statement(
            goto labe:
            )
## 2.EXIT(7_2_EXIT.c)

- Sử dụng thư viện stdlib.h để dùng Exit
- Exit: dừng lại chương trình chứ không thoát khỏi


## 3.SETJUM(7_3_SETJUM.C)

- Sử dụng thư viện setjmp.h để dùng setjum
- sử dụng setjmp với TRY CATCH THROW để khi chương trình có lỗi thì mọi sẽ dừng lại đê ưu tiên xử lý lỗi trước và trỏ con trỏ đến vùng lỗi để xử lý (rất phức tạp khi không dùng setjmp ở các vòng lặp)

# BÀI 8: POINTER

## 1. con trỏ
- con trỏ là một biến, nhưng biến ở đây là một địa chỉ nào đó bất kì trong bộ nhớ RAM(//0xc1).

- Khai báo biến bình thường: 
    >int a = 10; //chứa giá trị của biến a
- khai báo con trỏ (**decreling pointer**):
    >int *ptr;
- khởi tạo và gán giá trị cho con trỏ (**initializing and Assigning value to pointer**):
    >ptr = &a; //gán địa chỉ của a cho con trỏ

    địa chỉ của biến a là giá trị của con trỏ:

        printf("địa chỉ của biến a là: %d", &a);
        nó tương tự 
        printf(" giá trị của con trỏ là ptr: %d", ptr);
    giá trị của biến a giá trị mà con trỏ ptr đang quản lý hoặc trỏ đến hoặc toán tử giải tham chiếu (**the indirection * operator/dereferencing operator**)

        printf("giá trị của biến a: %d," a);
        tương tự
        printf("giá trị mà con trỏ ptr đang quản lý: %d", *ptr);

    **Chú ý:** 

    - "*ptr" ở khai báo là **con trỏ**
    - "*ptr" sử dụng ở những câu lệnh bên dưới sau khi khai báo xong là **toán tự giải tham chiếu**. truy cập vào giá trị mà con trỏ đang trỏ tới (địa chỉ cảu biến) để thay đổi giá trị của biến.

- Thông qua con trỏ có thể thay đối giá trị của biến a = 10.

    >*ptr = 100 // tương ứng với a = 100

    vì khi con trỏ (int *ptr) tham chiếu tới biến a thì toán tử giải tham chiếu (*ptr) chính là giá trị của biến a, khi thay đổi hay tăng giảm sẽ trực tiếp ảnh hưởng đến giá trị ô nhớ.

**Vidu:**

        #include <stdio.h>

        int a = 5;

        void tong(){
            printf("hello\n");
        }

        int main(int argc, char const *argv[])
        {
            int *ptr = &a;
            *ptr = 27;

            printf("dia chi cua a: %p\n", ptr);
            printf("gia tri a: %d\n", *ptr);
            printf("gia tri a: %d\n", a);

            printf("dia chi cua tong: %p\n", ptr);
            return 0;
        }


- con trỏ có địa chỉ là 0x00 và giá trị là 0 được gọi là con trỏ NULL.
- khi mà không còn nhu cầu sử dụng con trỏ đã khai báo thì gán con trỏ đó bằng NULL:
    > int *ptr = NULL;
## 2. con trỏ hàm

- Khai báo con trỏ hàm: 
    >type (*ptr) ( para_type_1, 
    para_type_2,...);
- Gán địa chỉ của hàm cho con trỏ hàm:
    >ptr = &function();

**Vidu**:

    #include <stdio.h>

    void tong (int a, int b){
        printf("tong %d va %d = %d \n", a, b, a+b);

    }

    float tich (float a, float b){
    return a*b;

    }

    int main(int argc, char const *argv[])
    {
        void(*ptr)(int, int);
        ptr = &tong;
        ptr(9,8);

        float(*ptr_tich)(float, float);
        ptr_tich = &tich;
        printf("tich: %f",ptr_tich(5.3, 5.6));
        return 0;
    }

- con trỏ đặc biệt: là con trỏ có thể lưu các giá trị địa chỉ khác kiểu dữ liệu.
    >void *ptr = &a

## 3 Mối quan hệ của mảng và con trỏ

- Tên của mảng là một hằng con trỏ (địa chỉ không thay đổi được) 
- Giá trị của hằng con trỏ là địa chỉ của phần tử đầu tiên của mảng

**Vidu:**

        #include <stdio.h>
        int main(int argc, char const *argv[])
        {
            int a[5] = {1, 2, 3 , 4, 5 };

            printf("giá trị của a: %d\n", a); // a là hằng con trỏ
            printf("địa chỉ của phần tử a[0]: %d\n", &a[0]); // giá trị của hằng trỏ là địa chỉ của a[0]
            return 0;
        }
        
- Gán mảng cho một con trỏ thì có thể sử dụng con trỏ để thực hiện các thao tác giá trị, chỉ số của một mảng với điều kiện là trỏ một con trỏ tới địa chỉ đầu tiên của mảng a và sau đó có thể sử dụng như một cái mảng mặc dù nó là con trỏ

**Vidu:**

        #include <stdio.h>
        int main(int argc, char const *argv[])
        {
        int a[5] = {1, 2, 3 , 4, 5 };
        int *ptr = a;
        for(int i = 0; i < 5; i++){

        printf("gia tri cua mang: \n");
        printf("%d", ptr[i]);
            }
            return 0;

        }
- có thể sử dụng các toán tử ++ --... cho con trỏ khi đã gán mảng cho con trỏ.
> ++ptr;
## 4. con trỏ tới con trỏ (pointer to pointer)
- là con trỏ cấp 2 có giá trị là lưu địa của con trỏ cấp 1.

![](https://github.com/langtoan22/image_C_Cpp_Advanced/blob/main/bai8_PointerToPointer.png?raw=true)

**vidu**: int **ptr;

        #include <stdio.h>

        int main(int argc, char const *argv[])
    {
        int a = 10;
        int *ptr = &a;
        int **ptr1 = &ptr;


        printf("gia tri cua bien a: %d\n", a); //10
        printf("dia chi cua bien a: %d\n", &a);//0xc1

        printf("gia tri cua bien trong ptr: %d\n", *ptr);//10
        printf("dia chi cua bien trong ptr: %d\n", ptr);//0xc1

        printf("gia tri cua bien trong ptr1: %d\n", **ptr1);//10
        printf("dia chi cua bien trong ptr1: %d\n", ptr1);//0xc2

        return 0;
    }

# BAI10_LINK LIST
## 1. TỔNG QUÁT VỀ LINKLIST(10_1_LinkList.c)
Tạo mảng nhân tạo có đặc trưng giống mảng truyền thống nhưng nó có thể chèn hoặc bớt ngẫu nhiên các phần tử vào mảng.

Nhược điểm: thời gian truy cập tuyến tính vì không phải là các ô nhớ liền kề nhau nên không thể truy cập ngẫu nhiên các ô nhớ bằng chỉ số mà phải duyệt từng giá trị một theo thứ tự.

- Phần tử cuối cùng trong DSLK trỏ vào NULL;
- Không lãng phí bộ nhớ nhưng cần thêm bộ nhớ để lưu phần con trỏ
- Các phần tử trong DSLK gọi là Node và được cấp phát động và được lưu ở bộ nhớ stack;
- Đây là CTDL cấp phát động nên khi còn bộ nhớ thì sẽ còn thêm được phần tử vào DSLK;

Gồm 2 phần: dữ liệu bài toán và một tham chiếu (hay liên kết) lưu địa chỉ tới các phần tử đứng sau kế tiếp

![](https://github.com/langtoan22/image_C_Cpp_Advanced/blob/main/bai10_linkList.png?raw=true)

### 1.1. DSLK đơn
#### a. Cấu trúc tự trỏ
            struct Node {
                uint8_t value; 
                struct Node *next;// link
            };
            typedef struct Node node;

- value: dữ liệu của node;
- node *next: con trỏ thuộc kiểu node tên next và lưu địa chỉ của phần tử đứng sau mang kiểu node.

Next của phần tử cuối cùng bao giờ cũng trỏ vào NULL.
#### b. Tạo một node mới: 

        node *createNode(uint8_t value){
            node *node2 = (node*) malloc(sizeof(node));
            node2->value = value;
        node2->next = NULL; // nốt mới tạo chưa liên kết với các node khác nên con trỏ trỏ tới NULL
            return node2;
        }

#### c. Thêm node vào đầu DSLK

##### hàm duyệt:

            void duyet (node *head){ 
                while(p->next != NULL){
                printf("%d", node -> value)
                    head = head->next;
                }
            }
            

- p = p -> next (p->next : địa chỉ của node kế tiếp): di chuyển từng node trong DSLK
- lấy địa chỉ của phần tử tiếp theo gán cho p khi đó p nhảy sang phần tử tiếp theo đến cuối khi p =  NULL thì vòng while dừng.

##### Thêm node vào đầu DSLK:

 
-  do hàm này làm thay đổi DSLK nên phải sử dụng truyền tham chiếu hoặc truyền con trỏ.

        void pushFront (**head, uint8_t value){
            node *newnode;
            newnode = createNode(value);
        //bước1: cho next của newnode trỏ vào node head hiện tại 
            newnode -> next = *head;  //*head là địa chỉ của node head
        //bước2: cập nhật node head bằng newnode
            *head = newnod;
        }

#### d.Thêm từng node vào DSLK

        void push_back(node **array, uint8_t value){ 
        node *temp, *p;
        temp = createNode(value);

        //kiểm tra giá trị của array bằng NULL thì tạo một node mới.
        if(*array = NULL){ 
            *array = temp;
        }
        else{ 

                //trong trường hợp ngược lại kiểm tra *array != NuLl thì gán địa chỉ con trỏ array cho p
            p = *array;
            
                // p trỏ đến next kiểm tra khác NULL, vì là chưa có node đầu tiền nên next sẽ == NUll nên không chạy vào vòng while

            while(p->next != NULL){
                p = p->next;
            }

                //khi con trỏ next == NUll thì sẽ tạo node mới khi đó node đầu tiên sẽ lưu địa chỉ node thứ 2 rôi chạy lại vào vòng while kiểm tra .
                
            p->next = temp;

        }
        }
##  2.CẤP PHÁT ĐỘNG (10_2_CapPhatDong.c)
### 2.1.malloc

Dùng thư viện **stdlib.h** để dùng malloc.

Trong khi array là một mảng tĩnh không thể thay đổi kích thước được thì malloc là mảng động có thể thay đổi kích thước được.

Con trỏ lưu địa chỉ đầu tiên thì mảng lưu các địa chỉ liền kề

    >void malloc(sizeof(kiểu dữ liệu )* kích thước cần cấp phát); 

- malloc sẽ trả về hàm void nên cần phải ép kiểu;

    >vidu: (uint8_t*)malloc(sizeof(uint8_t)*5); //lấy 5 bộ nhớ 1byte liền kề nhau kiểu uint8_t


### 2.2.realloc 

Dùng để mở rộng thêm bộ nhớ cấp phát động của mảng động (malloc)
    >ptr = void realloc(ptr, sizeof(kiểu dữ liệu) * kích thước tổng cấp phát)

vidu:  ptr = (uint8_t*)realloc(ptr, sizeof(uint8_t)*8 );

# BAI11: STACK

### 1.Tổng quan
Ngăn xếp (STACK) là một danh sách tuyến tính, trong đó cho phép thêm và loại bỏ một phần tử khỏi ngăn xếp luôn luôn thực hiện ở một đầu gọi là đỉnh (top).

![](https://github.com/langtoan22/image_C_Cpp_Advanced/blob/main/bai11_stack.png?raw=true)

### 1.1.Hàm kiểm tra ngăn xếp đầy

// return true if stack empty else false

            bool isEmpty(){
            if(i == -1){
                return true;
            }
            else{
                return false;
            }
        }
### 1.2.Hàm kiểm tra ngăn xếp rỗng
 // return true if stack is full else false

            bool isFull(){
                if(i == SIZE - 1){
                    return true;
                }
                else{
                    return false;
                }
            }

### 1.3.Hàm thêm một khối vào ngăn xếp
// to insert an elememt into the stack

            void push(uint8_t stack[], uint8_t value){
                if(isFull() == true){
                    printf("stack is full\n");
                }
                else{
                    ++i;
                    stack[i] = value;
                }
            }
### 1.4.Hàm xóa một khối khỏi ngăn xếp
// to remove an element from the stack

        void pop(uint8_t stack[]){
            if(isEmpty() == true){
                printf("stack is empty\n");
            }
            else {
                stack[i--] =='\0';
            }
        }
### 1.6.Hàm trả về một khối cảu ngăn xếp     
// return the top element of the stack

        uint8_t top (const uint8_t stack[]){
            return stack[i];
        }
### 1.7.Hàm trả về kích thước của ngăn xếp       
// return the size of the stack

        uint8_t size(){
            return i + 1;
        }

# BAI12_QUEUE(HÀNG ĐỢI)
## 1.Tổng quan
Hàng đợi là một danh sách tuyến tính trong đó, phép bổ sung một phần tử vào hàng đợi được thực hiện ở một đầu, gọi là cuối hàng(rear) và phép loại bỏ một phần tử được thực hiện ở đầu kia, gọi là đầu hàng(front).

Cơ cấu của hàng đợi là vào ở một đầu, ra ở một đầu, phần tử vào trước thì ra trước, phầm tử vào sau thì ra sau.

Hàng đợi còn được gọi là danh sách kiểu FIFO(First In First Out)

![](https://github.com/langtoan22/image_C_Cpp_Advanced/blob/main/bai12_queue.png?raw=true)

- quy ước: 

        rear = -1
        front = -1

- biến thể của queue: 
    + có hai trường hợp queue rỗng: front = rear = -1(khi chưa gán data), rear = front(khi lấy hết data)

# BAI13_CÂY NHỊ PHÂN

# BÀI14_CLASS
### 1. CLASS

là một phần trong OOP, một địn nghĩa chung của các object.

Class gồm 2 phần: 
- Thuộc tính(attribue/property);
- hương thức(method, behavior). 

là các trường dữ liệu mô tả thuộc tính và hành động của lớp

Class thực chất là một kiểu dữ liệu do người lập trình định nghĩa

Object(đối tượng): là một thực thể của Class


**vidu:** Class connguoi bao gồm: 
- Các thuộc tính: tên, tuổi, địa chỉ, ngày sinh, ...
- Các hành động: đi lại, ăn, ngủ...
khi đó Object là một người cụ thể nào đó.
### 1.KHAI BÁO MỘT CLASS 

        class tênclass{
            public: method();
            private: property
        };
            void tênclass :: method(){
            };
        int main
            tenclass object;
            object.method();


### 2.Phạm vi truy cập của class (Acess modifier)

- public: object có thể truy cập đến được
- private: chỉ có thể truy cập trong class đó;
- protected: cho phép các class con có thể truy cập đến và sửa được; các phương thức và thuộc tính chỉ có thể truy cập qua các class kế thừa nó hoặc chính nó
### 3.Method declaration
Phương thức cũng giống như một hàm bình thường.

Đối với phương thức thì có hai cách định nghĩa thi hành: định nghĩa thi hành trong
lúc định nghĩa class và định nghĩa thi hành bên ngoài class.
### 4. Hàm dựng

Constructor(hàm khởi tạo): một hàm được khởi tạo khi khai báo một thực thể mới(object), nó có cùng tên với tên Class và không có kiểu trả về.

Destructor(hàm huỷ): nó có cùng tên với tên Class và không có kiểu trả về. nhưng có dấu ~ trước hàm

### 5.Static member

Static member hay thành viên tĩnh trong class C++ cũng tương tự như với static variable (biến tĩnh) trong function 

Đối với class, thành viên tĩnh sẽ là thuộc tính dùng chung cho tất cả các đối tượng của class đó, cho dù là không có đối tượng nào tồn tại. Tức là bạn có thể khai báo nhiều object, mỗi object các thuộc tính của nó đều khác nhau nhưng riêng static thì chỉ có một và static member tồn tại trong suốt chương trình cho dù có hay không có object nào của nó hay nói ngắn gọn là dùng chung một biến static

các object đều dùng chung một địa chỉ khi trỏ đến một property sau khi khai báo 1 static .

**vidu**:

        class tênclass{
                    public: method();
                    private: property
                    static int mssv
                };
                    int tênclass :: mssv;

                    void tênclass :: method(){
                    };
                int main
                    tenclass object;
                    object.method();
// :: toán tử phạm vi

vidu về một class hoàn chỉnh: 

        #include <iostream>
        #include <string>
        using namespace std ;

        class sinhvien{
            public://pham vi truy cap
                void setthongtin();
                void hienthi(); //method

            private: 
                int tuoi;// property
                int lop;
                string ten;
        };

            void sinhvien::setthongtin(){
                    cout << "nhap vao ten:\n";
                    cin >> ten;
            }

            void sinhvien::hienthi(){
                cout <<"ten:" << ten <<"\n";
            }

        int main(int argc, char const *argv[])
        {
            sinhvien sv1; //Oject thuoc class sinh vien

            sv1.setthongtin();
            sv1.hienthi();

            return 0;
        }

# BÀI15_OOP

gồm 2 phần là class và object:
- class là một định nghĩa chung của object;
- object là một đối tượng chủ thể riêng biệt trong định nghĩa của class.
 ## 1. OOP

- Object-oriented programming(OOP): xoay quang các đối tượng, dữ liệu thay vì xoay quành các hàm và thủ tục
- Cố gắng mô phỏng các đối tượng trong thực tế thành các đối tượng trong ngôn ngữ lập trình thông qua các trường dữ liệu (data field) thuộc tính (attributes) và các hành động(behavior)

 ví dụ; con người có các thuộc tính tên tuổi, địa chỉ và các hành  động đi đứng ngồi ...
 - OOP tập chung vào các đối tượng thay vì logic phù hợp với các chương trình lớn và hay active, bảo trì...
 - Điểm mạnh của OOP: có khả năng tái sự dụng lại code(code reusability), mở rộng(scalability), và hiệu quả(efficiency).

## 2.CÁC TÍNH CHẤT CỦA OOP

### 2.1.TÍNH KẾ THỪA(Inheritance)

- Đặc tính này cho phép xây dựng một lớp mới có
thể có sẵn các đặc tính mà các lớp khác đã có
thông qua kế thừa.
- Điều này cho phép các lớp chia sẻ hay mở rộng các
đặc tính sẵn có mà không phải tiến hành định nghĩa
lại

#### 2.1.1.XÂY DỰNG KẾ THỪA

        class <tenClass2>:<phạm vi kế thừa> <tenClass1>
        {
        //Nội dung lớp dẫn xuất
        };

Khi tenClass1 để phạm vi truy cập của property là private thì tenClass2 không kế thừa được

vidu: 

            class tenClass1{
                public: method();
                        property
            };
            void tenClass1 :: method(){
                
            };
        

        //tenclass2 kế thừa toàn bộ property và method của tenClass1

            class tenClass2 : public tenClass1{
                //định nghĩa mới của class con
            };
            void tenClass2 :: method(){
                ghi đè định nghĩa mới dựa trên class cha
            }
            

#### 2.1.2. PHẠM VI KẾ THỪA (Acess mode)

- **Public**: Khi đó phạm vi truy cập(acess modifier) của class con sẽ giống của class cha.

- **Private**: khi đó tất cả các property và method của class cha sẽ có phạm vi truy cập( acess modifier) là private ở class con, khi đó các đối tượng (object) sẽ không truy cập được vào các thông tin(property và method) của class cha mà class con đã kế thừa thay và chỉ truy cập được vào các thông tin mà class con đã định nghĩa.
- **protected**: khi đó tất cả thông tin( property và method) của class cha khi để phạm vi truy cập( acess modifier) là pubic thì class con sẽ là protected.


**vidu:** 

        #include <iostream>
        #include <string>

        using namespace std;
        class DoiTuong{
            public:
                string ten;
            
                void NhapThongTin(string ten);
                void HienThi();
        };

            void DoiTuong :: NhapThongTin(string ten, int tuoi, int lop){
                DoiTuong :: ten = ten;
            }

            void  DoiTuong ::HienThi(){
                cout << "day la class DoiTuong:\n";
                cout <<"ten: " <<ten<<endl;
            }

        //class SinhVien kế thừa class DoiTuong
        class SinhVien :public DoiTuong{
                
        };

        int main(int argc, char const *argv[])
        {
            SinhVien sv1;

            sv1.NhapThongTin("Hoang", 17, 11);
            sv1.HienThi();
            return 0;
        }

####  GHI ĐÈ (overridding)

Khi class con muốn thêm property và sử dụng lại method của class cha.
khi đó class con định nghĩa lại method khi cần thêm các property;

### 2.2. TÍNH ĐA HÌNH(polymorphism)
- các method trong class sẽ phân biệt dựa vào các input parameter.

### 2.3.TEMPLATE
- Template (khuôn mẫu) là một từ khóa trong C++, và là một kiểu dữ liệu trừu tượng tổng quát hóa cho các kiểu dữ liệu int, float, double, bool...
- Template trong C++ có 2 loại đó là function template & class template.
- Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu dữ liệu khác nhau.

### 2.4. TÍNH TRỪU TƯỢNG(Abstraction)
- trong lập trình hướng đối tượng là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông tin cần xử lý.
- Điều đó có nghĩa, bạn có thể xử lý một đối tượng bằng cách gọi tên một phương thức và thu về kết quả xử lý, mà không cần biết làm cách nào đối tượng đó được các thao tác trong class.
- Ví dụ đơn giản, bạn có thể nấu cơm bằng nồi cơm điện bằng cách rất đơn giản là ấn công tắc nấu, mà không cần biết là bên trong cái nồi cơm điện đó đã làm thế nào mà gạo có thể nấu thành cơm

###  2.5.TÍNH ĐÓNG GÓI(Encapsulation)
- Khi khai báo property thì phải khai báo ở phạm vi truy cập(acess modifier) là private hoặc protected không được phép khai báo ở public, phòng trường hợp người dùng truy cập trực tiếp và thay đổi giá trị dẫn đến sai chương trình.

# BÀI16

### 1.namespace

Định nghĩa vùng nhớ, mỗi namespace sẽ định nghĩa vùng nhớ riêng biệt hay con gọi thư viện riêng, cho phép đặt tên hai biến, class, mảng... trùng tên với nhau trong 2 thư viện khác nhau.

**using namspace**: gọi một thư viện được khai báo trước đó 

### 2.virtual fuction 
Chỉ dùng trong class

Còn được gọi là hàm ảo, khi các phương thức của classs cha dùng virtual thì class con kế thừa sẽ load lại phương thức và hiển thị phương thức đã được định nghĩa và ghi đè

class con khi kế thừa và ghi đè thì vẫn trên phân vùng địa chỉ của class cha, nên khi không dùng virtual thì khi gọi các phương thức đã được định nghĩa và ghi đè mới của class con thì sẽ hiện các phương thức của class cha.

### 3.string
Sử dụng thư viện: include< string>
### 4.vector

Sử dụng thư viện: include< vector>

vector giống như mảng động(linklist) có thể thay đổi được kích thước tuy nhiên các địa chỉ trong vector là liền kề nhau.

Cú pháp: vector <kiểu dữ liệu> ten_vector

Các hàm vector: 
- Thêm phần tử: ten_vector.**push_back()**;
    >array.push_back(5);
- Xóa phần tử cuối: ten_vector.**pop_back()**;
- Chèn phần tử: ten_vector.**insert(array.begin()+giá trị địa chỉ dịch chuyển tính từ vị trí đầu,giá trị phần tử cần chèn)**
    >array.insert(array.begin()+2, 8);
- Tạo một mảng gồm các phần tử cùng giá trị: ten_vector. **assign(số lượng phần tử, giá trị phần tử)**; ví dụ tạo 4 phần tử có giá trị là 3
    >array.assign(4,3);
- kích thước vector: ten_vector.**size()**;

kĩ thuật duyệt( for cải tiến) qua các phần tử: 
- for(datatype ten_bien : ten_vector){
    printf("%d\n", ten_bien);
}

Các địa chỉ trong vector sẽ được gán cho ten_bien và in ra cho đến hết các phần tử trong vector.

# BÀI17_LIST_MAP

### 1.list
Sử dụng thư viện: include< list >

list giống vector về các hàm, nhưng khác về cách hoạt động, phần vùng địa chỉ vì địa chỉ của list không phải là các giá trị liền kề nhau.
### 2.map

Trong c++ có kiểu dữ liệu **auto**: là kiểu dữ liệu mà căn cứ vào giá trị đằng sau để tự động chọn kiểu dữ liệu phù hợp
>auto 100; // tự động chọn kiểu dữ liệu int

Sử dụng thư viện: include< map >;

Map lưu các cặp key-value, các phần tử trong map sẽ là các cặp key-value. các key sẽ phải là duy nhất và value có thể lặp lại được.

Cú pháp: **map <kiểu dữ liệu 1, kiểu dữ liệu 2> ten_map;**
- kiểu dữ liệu 1 thể hiện **key**, kiểu dữ liệu 2 thể hiện **value**.

có 3 phương thức chính: 
- Thêm 1 cặp key-value;
- Truy suất một giá trị thông qua key;
- Xóa một cặp key-value khỏi map;

