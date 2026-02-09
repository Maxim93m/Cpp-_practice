#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	float a, b, c, Xn, Xk, dX, x, F;

	for (;;) {
		cout << "\nВвведите значение Xn: = ";
		cin >> Xn;
		cout << "Ввведите значение Xk: = ";
		cin >> Xk;
		if (Xk <= Xn) {
			cout << "\nКонечное значение Xk не может быть меньше или равно начального значения Xn!\n";
		}
		cout << "Ввведите значение dX: = ";
		cin >> dX;
		cout << "\nВвведите значение a: = ";
		cin >> a;
		cout << "Ввведите значение b: = ";
		cin >> b;
		cout << "Ввведите значение c: = ";
		cin >> c;
		cout << "\n";
		
		for (x = Xn; x <= Xk; x +=dX) {
			if (x < 0 && b != 0) {
				F = a * pow(x, 2) + b;
				if (((int(a) | int(b)) & (int(a) | int(c)))!=0) {
					cout << "F = a*x^2+b -->| F = " << F << " | " << "X = " << x << " | " << "\n";
				}
				else {
					cout << "F = a*x^2+b -->| F = " << int(F) << " | " << "X = " << x << " | " << "\n";
				}
			}
			else if (x > 0 && b == 0) {
				F = (x - a) / (x - c);
				if (((int(a) | int(b)) & (int(a) | int(c))) != 0) {
					cout << "F = (x - a)/(x - c) -->| F = " << F << " | " << "X = " << x << " | " << "\n";
				}
				else {
					cout << "F = (x - a)/(x - c) -->| F = " << int(F) << " | " << "X = " << x << " | " << "\n";
				}
			}
			else {
				F = x / c;
				if (((int(a) | int(b)) & (int(a) | int(c))) != 0) {
					cout << "F = x/c -->| F = " << F << " | " << "X = " << x << " | " << "\n";
				}
				else {
					cout << "F = x/c -->| F = " << int(F) << " | " << "X = " << x << " | " << "\n";
				}
			}
		}
	}
}
