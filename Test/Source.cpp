#include "complex.h"

void SimpleCalculationForTwoComplexes(int type) {
	cout << "Complex 1:" << endl;
	Complex c1 = InputComplex();
	PrintComplex(c1);
	cout << "\nComplex 2:" << endl;
	Complex c2 = InputComplex();
	PrintComplex(c2);

	Complex result;
	switch (type)
	{
	case 1: // Add
		cout << "\nAddition = ";
		result = Add(c1, c2);
		break;
	case 2: // Sub
		cout << "\nSubtraction = ";
		result = Sub(c1, c2);
		break;
	case 3: // Mul
		cout << "\nMultiplication = ";
		result = Mul(c1, c2);
		break;
	case 4: // Div
		cout << "\nDivision = ";
		result = Div(c1, c2);
		break;
	}

	PrintComplex(result);
}

void SimpleCalculationForComplex(int type) {
	Complex c = InputComplex();
	PrintComplex(c);
	switch (type)
	{
	case 1:
		cout << "\nModulus = " << Modulus(c);
		cout << "\nArgument = " << Argument(c) << endl;
		break;
	case 2:
		cout << "\nConjugate = ";
		PrintComplex(Conjg(c));
		cout << endl;
		break;
	}
}

void ProcessQuadraticEquation2() {
	double a, b, c, delta, x1, x2;
	cout << "Nhap a = ";
	cin >> a;
	cout << "Nhap b = ";
	cin >> b;
	cout << "Nhap c = ";
	cin >> c;

	if (a == 0) {
		// a == 0 phuong trinh tro thanh phuong trinh bac mot bx + c = 0
		if (b == 0) {
			if (c == 0) {
				cout << "Phuong trinh vo so nghiem" << endl;
			}
			else {
				cout << "Phuong trinh vo nghiem" << endl;
			}
		}
		else {
			cout << "Phuong trinh co nghiem duy nhat: " << -c / b << endl;
		}
	}
	else {
		delta = b * b - 4 * a * c;
		if (delta > 0) {
			x1 = (-b + sqrt(delta)) / (2 * a);
			x2 = (-b - sqrt(delta)) / (2 * a);
			cout << "Nghiem thu nhat x1 = " << x1 << endl;
			cout << "Nghiem thu hai x2 = " << x2 << endl;
		}
		else if (delta == 0) {
			cout << "Phuong trinh co nghiem kep: x1 = x2 = " << -b / 2 * a << endl;
		}
		else {
			// Delta < 0  => x1,2 = (-b +- sqrt(abs(delta))) / 2 * a
			cout << "Nghiem phuc thu nhat x1 = " << -b << "+" << sqrt(abs(delta)) << "i" << "/" << 2 * a << endl;
			cout << "Nghiem phuc thu hai x2 = " << -b << "-" << sqrt(abs(delta)) << "i" << "/" << 2 * a << endl;
		}
	}
}

void Menu() {
	cout << "==========COMPLEX PROGRAM============\n";
	cout << "0. Enter a complex\n";
	cout << "1. Modulus and Argument\n";
	cout << "2. Conjugate\n";
	cout << "3. Addition\n";
	cout << "4. Subtraction\n";
	cout << "5. Multiplication\n";
	cout << "6. Division\n";
	cout << "7. Quadratic Equation 2\n";
	cout << "8. Exit\n";
	cout << "=====================================\n";
}

int SelectMenu()
{
	int n = 0;
	cout << "\nPlease choose your option: ";
	cin >> n;
	if (n >= 0 || n < 99)
		return n;
	else return SelectMenu();
}

void ProcessMenu()
{
	int choose = SelectMenu();
	switch (choose)
	{
	case 0:
		cout << "------------------------------" << endl;
		cout << "0. Enter a complex\n\n";
		Complex c = InputComplex();
		PrintComplex(c);
		cout << "------------------------------" << endl;
		break;
	case 1:
		cout << "------------------------------" << endl;
		cout << "1. Modulus and Argument\n\n";
		SimpleCalculationForComplex(1);
		cout << "------------------------------" << endl;
		break;
	case 2:
		cout << "------------------------------" << endl;
		cout << "2. Conjugate\n\n";
		SimpleCalculationForComplex(2);
		cout << "------------------------------" << endl;
		break;
	case 3:
		cout << "------------------------------" << endl;
		cout << "3. Addition\n\n";
		SimpleCalculationForTwoComplexes(1);
		cout << "------------------------------" << endl;
		break;
	case 4:
		cout << "------------------------------" << endl;
		cout << "4. Subtraction\n\n";
		SimpleCalculationForTwoComplexes(2);
		cout << "------------------------------" << endl;
		break;
	case 5:
		cout << "------------------------------" << endl;
		cout << "5. Multiplication\n\n";
		SimpleCalculationForTwoComplexes(3);
		cout << "------------------------------" << endl;
		break;
	case 6:
		cout << "------------------------------" << endl;
		cout << "6. Division\n\n";
		SimpleCalculationForTwoComplexes(4);
		cout << "------------------------------" << endl;
		break;
	case 7:
		cout << "------------------------------" << endl;
		cout << "7. Quadratic Equation 2\n\n";
		ProcessQuadraticEquation2();
		cout << "------------------------------" << endl;
		break;
	case 8:
		exit(1);
		break;
	}
}

int main()
{
	Menu();
	while (true)
	{
		ProcessMenu();
	}
	return 0;
}