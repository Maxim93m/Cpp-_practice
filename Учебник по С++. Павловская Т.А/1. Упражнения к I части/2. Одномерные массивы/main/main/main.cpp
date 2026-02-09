#include <iostream>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	const int n = 10;
	float arr[n] = {-3, 2, 15, -3.5, 4.2, -99.7, 5, -7, 88, -33.3};
	float sum = 0;

	cout << "\nИсходный массив: arr[n] =  {-3, 2, 15, -3.5, 4.2, -99.7, 5, -7, 88, -33.3}\n";
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			cout << "Отрицательный элемент массива: arr[" << i << "] = " << arr[i] << "\n";
			sum += arr[i];
		}
	}
	cout << "Сумма отрицательных элементов sum = " << sum << "\n";
		
	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < n; j++) {
			
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " \n";
	}
}
