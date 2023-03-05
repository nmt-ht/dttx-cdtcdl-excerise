/*
	Student Name : Nguyễn Minh Tư
	Student Id   : 21850024
	Reference    : Vũ Quốc Hoàng, Bí kíp luyện Lập trình C (Quyển 1), hBook, 2017
*/

#include <iostream>
#include "complex.h"
using namespace std;

/*
   1. Bài tập 4.1.6:
   Hãy xem lại phần Mở rộng 4.1. Cho một mẫu dữ liệu, ta gọi trung vị (median) của mẫu là giá trị “ở giữa” hay giá trị “chia đôi dữ liệu” của mẫu.
   Tương tự giá trị trung bình, trung vị là một con số phản ánh trung tâm của số liệu. Hãy tham khảo tài liệu để hiểu rõ khái niệm trung vị
   và viết hàm tính giá trị này của một mẫu dữ liệu (prototype tương tự hàm mean hay var của Mã 4.1.4).
*/

void sort(double arr[], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] < arr[j])
			{
				double t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
}

//finding median
double median(double arr[], int n) {
	//sort the array
	sort(arr, n);

	return n % 2 == 0
		? (arr[n / 2 - 1] + arr[n / 2]) / 2
		: arr[n / 2];
}

/*
  2. Bài tập 4.2.6 - Mảng hai chiều
  Viết hàm tính số tổ hợp 𝐶𝑛𝑘 = 𝑛!
	𝑘!(𝑛−𝑘)! (𝑛 ≥ 0,0 ≤ 𝑘 ≤ 𝑛) bằng cách
	“tách bạch, ngây thơ” và cách “tích hợp, tinh vi” (xem Bài 3.2):
	- Viết riêng hàm tính giai thừa và dùng hàm này khi tính 𝐶𝑛𝑘.
	- Phân tích, biến đổi, … để tính 𝐶𝑛𝑘.
	So sánh ưu khuyến điểm của hai cách làm
*/

unsigned long long Combination(int k, int n)
{
	unsigned long long a[100][100];

	if (k == 0 || k == n)
		return 1;
	else
	{
		for (int i = 0; i <= k; i++) {
			for (int j = i; j <= n; j++)
			{
				if (i == 0 || i == j)
					a[i][j] = 1;
				else
					a[i][j] = a[i][j - 1] + a[i - 1][j - 1];
			}
		}
	}

	return a[k][n];
}

void Input(int& k, int& n)
{
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter k: ";
	cin >> k;
}

void PrintC(int k, int n)
{
	cout << "Combination " << k << " of " << n << " = " << Combination(k, n);
}

/*
  3. Bài tập 4.4.1
  Làm lại Bài tập 1.5.6, Bài tập 1.5.7 và Bài tập 1.5.8 nhưng cho số nguyên không âm siêu lớn (không quá 100 chữ số thập phân).
  (Gợi ý: bạn biết rồi đó, đánh lừa thôi, làm trên chuỗi số chứ không phải là số.)
*/

bool IsNumber(char s)
{
	if (s >= '0' && s <= '9')
		return true;
	return false;
}

int countNumber(char n[1000]) {
	int length = 0;
	int index = 0;
	while (n[index] != NULL)
	{
		if (IsNumber(n[index]))
			length++;
		index++;
	}

	return length;
}

int totalOfNumer(char n[1000]) {
	int total = 0;
	int index = 0;
	while (n[index] != NULL)
	{
		if (IsNumber(n[index]))
			total += n[index] - '0';
		index++;
	}

	return total;
}

void formatNumber(char n[1000]) {
	int index = 0;
	int length = 0;
	char result[1000];
	bool isNegativeNumber = false;
	while (n[index] != NULL)
	{
		if (n[index] == 45) // minus
			isNegativeNumber = true;

		if (IsNumber(n[index]) && n[index] != '0')
		{
			result[length] = n[index];
			length++;
		}

		index++;
	}

	int firstLenght = length % 3;
	for (int i = 0; i < firstLenght; i++)
	{
		if (isNegativeNumber)
			cout << "-";
		cout << result[i];
	}

	int lastLenght = length - firstLenght;
	if (firstLenght > 0 && lastLenght > 0)
		cout << ",";

	for (int i = 0; i < lastLenght / 3; i++) {
		cout << result[firstLenght + 3 * i];
		cout << result[firstLenght + 3 * i + 1];
		cout << result[firstLenght + 3 * i + 2];
		if (i < lastLenght / 3 - 1)
			cout << ",";
	}
}

int main()
{
	//int n;
	//double arr[1000];
	//cout << "Enter the size of array: ";
	//cin >> n;

	////input in the array
	//for (int i = 0; i < n; i++)
	//{
	//	cout << "Enter the element " << i + 1 << " : ";
	//	cin >> arr[i];
	//}

	//cout << "\nMedian = " << median(arr, n);

	/*int k, n;
	Input(k, n);
	PrintC(k, n);*/

	char n[1000];
	cout << "Nhap vao so can kiem tra: ";
	cin >> n;

	cout << countNumber(n) << endl;
	cout << totalOfNumer(n) << endl;
	formatNumber(n);

	return 0;
}
