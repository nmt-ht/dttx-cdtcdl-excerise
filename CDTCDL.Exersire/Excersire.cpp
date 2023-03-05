/*
	Student Name : Nguyễn Minh Tư
	Student Id   : 21850024
	Reference    : Vũ Quốc Hoàng, Bí kíp luyện Lập trình C (Quyển 1), hBook, 2017
*/

#include <iostream>
#include <windows.h>
using  namespace std;

const char FULL_BLOCK = 219;
const char LOWER_HAFT_BLOCK = 220;
const char UPPER_HAFT_BLOCK = 223;
const char LIGHT_SHADE = 176; //Correct Code: 176
const char MEDIUM_SHADE = 177; //Correct Code: 177
const char DARK_SHADE = 178;
const char SP = 32; //Whitespace

/*
	Bài tập 1.5.7: Tính tổng các chữ số của một số nguyên không âm.
*/
void Excersire1()
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
}

/*
	Bài tập 1.5.8: Nhập một số nguyên và xuất ra số nguyên đó với các dấu phẩy (,)
	phân cách mỗi 3 chữ số. Ví dụ: nhập 1234567 xuất ra 1,234,567.
*/

int getLengthOfNumber(long long number) {
	int len = 0;
	while (number >= 10)
	{
		len++;
		number /= 10;
	};
	return len + 1;
}

int getDigitPosition(long long number, int index, int len) {
	index = len - 1 - index;
	for (int j = 0; j < index; j++)
		number /= 10;
	return number % 10;
}

void Excersire2()
{
	long long number = 0;
	cout << "Nhap vao so nguyen khong am can dinh dang: ";
	cin >> number;

	if (number < 0)
	{
		cout << "-";
		number = -number;
	}

	int len = getLengthOfNumber(number);

	int firstLenght = len % 3;
	for (int i = 0; i < firstLenght; i++)
		cout << getDigitPosition(number, i, len);

	int lastLenght = len - firstLenght;
	if (firstLenght > 0 && lastLenght > 0)
		cout << ",";

	for (int i = 0; i < lastLenght / 3; i++) {
		cout << getDigitPosition(number, firstLenght + 3 * i, len);
		cout << getDigitPosition(number, firstLenght + 3 * i + 1, len);
		cout << getDigitPosition(number, firstLenght + 3 * i + 2, len);
		if (i < lastLenght / 3 - 1)
			cout << ",";
	}
}

/*
	Bài tập 1.5.10: Dùng phương pháp chia đôi trong phần mở rộng để tính căn bậc 3
	của một số thực dương.
*/
double myCubeRoot(double y)
{
	double x, l, r;
	if (y > 1)
		r = y;
	else
		r = 1;
	l = 0;
	do
	{
		x = (l + r) / 2;
		if (x * x * x > y)
			r = x;
		else
			l = x;
	} while ((r - l) / r > 0.0000001);

	return x;
}

void Excersire3() {
	double number;
	cout << "Nhap so can tinh can bac 3: ";
	cin >> number;

	if (number < 0)
	{
		cout << "-";
		number = -number;
	}

	cout << myCubeRoot(number) << endl;
}

/*
	Bài tập 1.7.4: Viết chương trình dùng các kí tự đồ họa trong bảng mã 437 để kết
	xuất giống hình tại mục “Block or High ASCII style”.
*/

void Excersire4() {

	//Reference CP437: https://en.wikipedia.org/wiki/Code_page_437#Alt_codes

	SetConsoleOutputCP(437);

	// Line 1
	cout << SP << SP << SP << SP << SP << LOWER_HAFT_BLOCK << SP << SP << SP << SP << SP << SP << SP << SP
		<< SP << SP << SP << SP << SP << LOWER_HAFT_BLOCK << FULL_BLOCK << LOWER_HAFT_BLOCK
		<< SP << FULL_BLOCK << LOWER_HAFT_BLOCK << SP << SP << SP << SP << SP << SP << LOWER_HAFT_BLOCK << endl;

	//cout << "\n";

	// Line 2
	cout << SP << LOWER_HAFT_BLOCK << FULL_BLOCK << UPPER_HAFT_BLOCK << FULL_BLOCK << DARK_SHADE << SP << LOWER_HAFT_BLOCK
		<< DARK_SHADE << UPPER_HAFT_BLOCK << UPPER_HAFT_BLOCK << FULL_BLOCK << UPPER_HAFT_BLOCK << SP << UPPER_HAFT_BLOCK
		<< UPPER_HAFT_BLOCK << UPPER_HAFT_BLOCK << FULL_BLOCK << DARK_SHADE << UPPER_HAFT_BLOCK << UPPER_HAFT_BLOCK << SP << UPPER_HAFT_BLOCK
		<< UPPER_HAFT_BLOCK << SP << SP << SP << LOWER_HAFT_BLOCK << FULL_BLOCK << UPPER_HAFT_BLOCK << FULL_BLOCK << DARK_SHADE
		<< UPPER_HAFT_BLOCK << UPPER_HAFT_BLOCK << UPPER_HAFT_BLOCK << UPPER_HAFT_BLOCK << UPPER_HAFT_BLOCK << DARK_SHADE
		<< LOWER_HAFT_BLOCK << UPPER_HAFT_BLOCK << FULL_BLOCK << FULL_BLOCK << UPPER_HAFT_BLOCK << UPPER_HAFT_BLOCK << endl;

	//cout << "\n";

	// Line 3
	cout << FULL_BLOCK << FULL_BLOCK << SP << SP << FULL_BLOCK << FULL_BLOCK << SP << UPPER_HAFT_BLOCK
		<< FULL_BLOCK << FULL_BLOCK << LOWER_HAFT_BLOCK << LOWER_HAFT_BLOCK << SP << LOWER_HAFT_BLOCK
		<< FULL_BLOCK << SP << SP << UPPER_HAFT_BLOCK << SP << LIGHT_SHADE << MEDIUM_SHADE << SP << LIGHT_SHADE
		<< MEDIUM_SHADE << SP << SP << SP << FULL_BLOCK << FULL_BLOCK << SP << SP << FULL_BLOCK << FULL_BLOCK << SP
		<< LOWER_HAFT_BLOCK << FULL_BLOCK << LOWER_HAFT_BLOCK << SP << FULL_BLOCK << UPPER_HAFT_BLOCK << SP << FULL_BLOCK << FULL_BLOCK << endl;

	//cout << "\n";

	// Line 4
	cout << FULL_BLOCK << DARK_SHADE << LOWER_HAFT_BLOCK << UPPER_HAFT_BLOCK << FULL_BLOCK << FULL_BLOCK << SP << SP
		<< LOWER_HAFT_BLOCK << SP << UPPER_HAFT_BLOCK << FULL_BLOCK << FULL_BLOCK << SP << DARK_SHADE << FULL_BLOCK
		<< SP << SP << SP << MEDIUM_SHADE << DARK_SHADE << SP << MEDIUM_SHADE << DARK_SHADE << SP << SP << SP << FULL_BLOCK
		<< DARK_SHADE << LOWER_HAFT_BLOCK << UPPER_HAFT_BLOCK << FULL_BLOCK << FULL_BLOCK << SP << DARK_SHADE << FULL_BLOCK
		<< SP << UPPER_HAFT_BLOCK << LOWER_HAFT_BLOCK << SP << SP << FULL_BLOCK << DARK_SHADE << endl;

	//cout << "\n";

	// Line 5
	cout << FULL_BLOCK << MEDIUM_SHADE << SP << SP << FULL_BLOCK << DARK_SHADE << SP << FULL_BLOCK << FULL_BLOCK
		<< LOWER_HAFT_BLOCK << DARK_SHADE << UPPER_HAFT_BLOCK << SP << UPPER_HAFT_BLOCK << FULL_BLOCK << LOWER_HAFT_BLOCK
		<< LOWER_HAFT_BLOCK << FULL_BLOCK << LOWER_HAFT_BLOCK << DARK_SHADE << FULL_BLOCK << SP << DARK_SHADE << FULL_BLOCK
		<< SP << SP << SP << FULL_BLOCK << MEDIUM_SHADE << SP << SP << FULL_BLOCK << DARK_SHADE << SP << MEDIUM_SHADE
		<< FULL_BLOCK << SP << SP << DARK_SHADE << FULL_BLOCK << LOWER_HAFT_BLOCK << SP << MEDIUM_SHADE << endl;

	//cout << "\n";

	// Line 6
	cout << SP << SP << SP << SP << UPPER_HAFT_BLOCK << MEDIUM_SHADE << SP << SP << SP
		<< SP << SP << SP << SP << SP << SP << SP << SP << UPPER_HAFT_BLOCK << SP << SP
		<< UPPER_HAFT_BLOCK << SP << FULL_BLOCK << UPPER_HAFT_BLOCK << SP << SP << SP
		<< SP << SP << SP << SP << UPPER_HAFT_BLOCK
		<< MEDIUM_SHADE << SP << SP << UPPER_HAFT_BLOCK << SP << SP << FULL_BLOCK
		<< UPPER_HAFT_BLOCK << SP << SP << LIGHT_SHADE << endl;
}

/*
	Bài tập 3.5.4 Cho đoạn mã:
		int a = ('1' > 1) + (1.0 < 1); //1
		double b = 10.3 + '2'; //2
		int c = (int)1.5 + 0.5; //3

	a) Giá trị của a, b, c là bao nhiêu?
	b) Nêu chi tiết các bước chuyển kiểu trong các dòng mã trên (chuyển
	   kiểu giá trị nào, từ kiểu nào sang kiểu nào, được giá trị nào).
	c) Chuyển kiểu tường minh xảy ra ở những chỗ nào trong đoạn code
	   trên? Nếu không có thì sao?
	d) Theo bạn thì bước chuyển kiểu nào là đơn giản nhất và chuyển kiểu
	   nào là phức tạp nhất trong số các bước chuyển kiểu ở trên?
*/

void Excersire5() {
	int a = ('1' > 1) + (1.0 < 1); //1
	double b = 10.3 + '2'; //2
	int c = (int)1.5 + 0.5; //3

	cout << "Gia tri cua a: " << a << endl;
	cout << "Gia tri cua b: " << b << endl;
	cout << "Gia tri cua c: " << c << endl;
}

int main()
{
	//Excersire1();
	//Excersire2();
	//Excersire3();
	//Excersire4();
	Excersire5();
	return 0;
}

