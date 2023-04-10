# Ex 3:
## 1 .Mô hình dữ liệu hàng đợi ưu tiên (priority queue) là mô hình dữ liệu cho phép quản lý
một tập các đối tượng theo độ ưu tiên. Độ ưu tiên của mỗi đối tượng là một con số nguyên.
Một hàng đợi ưu tiên có hai thao tác đi kèm:
- Insert: chèn một đối tượng có độ ưu tiên được cho vào hàng đợi.
- RemoveMax: Gỡ đối tượng có độ ưu tiên lớn nhất ra khỏi hàng đợi và trả về đối tượng đó.
a) Hãy đưa ra cấu trúc dữ liệu phù hợp và cài đặt cụ thể một hàng đợi ưu tiên quản lý các số
nguyên.
b) Từ cấu trúc dữ liệu đã xây dựng ở câu (a) hãy viết hàm sắp xếp tăng dần một dãy số
nguyên

## 2. Mô hình dữ liệu túi (bag)
Một túi các số nguyên là một bộ sưu tập các số nguyên trong đó không để ý đến thứ tự các
phần tử nhưng cho phép các phần tử xuất hiện nhiều lần. Chẳng hạn túi {2, 1, 1, 2, 3, 1} có 3
phần tử, trong đó phần tử 1 xuất hiện 3 lần, phần tử 2 xuất hiện 2 lần và phần tử 3 xuất hiện 1
lần. Mô hình túi các số nguyên cung cấp các thao tác cơ bản sau:
- Khởi tạo: tạo túi rỗng không chứa phần tử nào, {}.
- Thêm: thêm một số nguyên vào túi. Sau khi thêm thì số lần xuất hiện của số nguyên đó sẽ
tăng thêm 1. Ví dụ, thêm số 2 vào túi {1, 2, 1, 3} sẽ được túi {1, 2, 1, 3, 2}.
- Xóa: xóa một số nguyên khỏi túi. Sau khi xóa thì số lần xuất hiện của số nguyên đó sẽ bớt
đi 1. Ví dụ, xóa số 1 khỏi túi {1, 2, 1, 3} sẽ được túi {2, 1, 3}.
- Xóa hết: xóa hết một số nguyên khỏi túi. Sau khi xóa hết thì số nguyên đó sẽ không còn
là phần tử của túi. Ví dụ, xóa hết số 1 khỏi túi {1, 2, 1, 3} sẽ được túi {2, 3}.
- Đếm số lần xuất hiện: đếm số lần xuất hiện của một số nguyên trong túi.
- Kiểm tra bằng nhau: hai túi là bằng nhau khi chúng có cùng các phần tử với cùng số lần
xuất hiện. Ví dụ, túi {2, 1, 1, 2, 3, 1} và túi {1, 1, 1, 2, 2, 3} là bằng nhau.- Kiểm tra là túi con: túi A là con của túi B nếu mọi phần tử của A đều là phần tử của B
với số lần xuất hiện trong A không quá số lần xuất hiện trong B. Ví dụ: túi {1, 1, 2} là túi
con của túi {1, 1, 2, 2, 3} nhưng không là túi con của túi {1, 2}.
- Hợp hai túi: túi hợp của hai túi A, B là túi chứa tất cả các phần tử của A và B với số lần
xuất hiện là tổng số lần xuất hiện trong A và B (nếu không là phần tử thì coi như là xuất
hiện 0 lần).

## 3. Giả sử cấu trúc một nút của danh sách liên kết các số nguyên được khai báo như sau:
struct NODE
{
int data;
NODE *next;
};
Hãy viết hàm int sumNeg(NODE *head) để tính tổng các số âm trong danh sách liên kết
có nút đầu trỏ bởi head bằng kĩ thuật đệ qui

## 4. Giả sử cấu trúc một nút của cây nhị phân các số nguyên được khai báo như sau
struct NODE
{
int data;
NODE *left, *right;
};
Hãy viết hàm int sumNeg(NODE *root) để tính tổng các số âm của cây nhị phân có nút
gốc trỏ bởi root bằng kĩ thuật đệ qui.
