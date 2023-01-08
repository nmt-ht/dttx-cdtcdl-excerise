/*
	* Vũ Quốc Hoàng, Bí kíp luyện Lập trình C (Quyển 1), hBook, 2017
	* Bài tập 1.5.8: Nhập một số nguyên và xuất ra số nguyên đó với các dấu phẩy (,)
		phân cách mỗi 3 chữ số. Ví dụ: nhập 1234567 xuất ra 1,234,567.
*/

#include <iostream>
using  namespace std;

int main()
{
	unsigned long long n;
	unsigned long long tmp_n;
	unsigned long long total = 0;

	cout << "Nhap vao so nguyen khong am n: ";
	cin >> n;
	tmp_n = n;

	while (tmp_n > 0)
	{
		total += tmp_n % 10;
		tmp_n /= 10;
	}

	cout << "Tong cac chu so la: " << total << endl;

	return 0;
}
