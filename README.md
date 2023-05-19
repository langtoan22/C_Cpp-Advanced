# C_Cpp-Advanced

#Bai1

#Bai2_macro

#Bai3_input

#Bai4_Variable

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


#Bai5_PhanVungNho(trenRAM)

- Phân vùng nhớ gồm hai vùng nhớ là Flash và RAM:

    + Flash: khi mất nguồn điện thì vẫn lưu các chương trình
    + RAM : Độ truy xuất nhanh nhưng khi mất nguồn điện thì sẽ mất hết các chương trình đang chạy

- Trong bộ nhớ RAM sẽ có 5 phân vùng nhớ: text, data, bss, heap, stack

    + Text(5.1_const):  chỉ có quyền Read và không có quyền sửa
                        hằng số sẽ được lưu ở phân vùng text

    + Data(5.2_Data):   có quyền Read và write(đọc và sửa)
                        chứa biến toàn cục hoặc biến static được khởi tạo với giá trị khác
                        được giải phóng khi kết thúc chương trình 

        chú ý: căn cứ giá trị gán ở lần đầu tiên để phân vùng
            vidu: static uint8_t test = 21; sau có thay đổi giá trị 21 = 0 thì vẫn được lưu ở Data

    + bss:  có quyền Read và write(đọc và sửa)
            chứa biến toàn cục hoặc biến static được khởi tạo với giá trị = 0 hoặc không khởi tạo(ngược lại với Data)
            được giải phóng khi kết thúc chương trình 

        chú ý: căn cứ giá trị gán ở lần đầu tiên để phân vùng
            vidu: static uint8_t test = 0; sau có thay đổi giá trị 0 = 21 thì vẫn được lưu ở bss

    + Stack(5.3_Stack):     có quyền Read và write(đọc và sửa)
                            được sử dụng cấp phát cho biến local(cục bộ), input parameter...
                            sẽ được giải phóng khi ra khỏi block code/hàm

    + Heap(5.5_Heap):       có quyền Read và write(đọc và sửa)
                            được sử dụng để cấp phát bộ nhớ động như: Malloc, calloc...
                            sẽ giải phóng khi gọi hàm free...
                        phân vùng heap không có cơ chế thu hồi bộ nhớ mà phải dùng đến hàm free (5.7.c)