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

void Menu() {
	cout << "==========COMPLEX PROGRAM============\n";
	cout << "0. Enter a complex\n";
	cout << "1. Modulus and Argument\n";
	cout << "2. Conjugate\n";
	cout << "3. Addition\n";
	cout << "4. Subtraction\n";
	cout << "5. Multiplication\n";
	cout << "6. Division\n";
	cout << "7. Exit\n";
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