#include <iostream>
int main() {
	setlocale(LC_ALL, "rus");
	// вводим массив
	int n = 1;
	std::cout << "Введите количество элементов массива: \n";
	std::cin >> n;
	if (n < 1) {
		std::cout << "В массиве должен быть хотя бы один элемент\n";
		return 0;
	}
	int* mass = new int[n];
	std::cout << "введите элементы массива: " << std::endl;
	for (int i = 0; i < n; ++i) {
		std::cin >> mass[i];
	}
	// 1 - количество положительных элементов массива
	int pol = 0;
	for (int i = 0; i < n; ++i) {
		if (mass[i] > 0) {
			++pol;
		}
	}
	std::cout << "\n1. Количество положительных элементов массива равно: " << pol << std::endl;
	// 2 - сумма значений после последнего нуля
	int last = n - 1;
	bool l = true;
	for (; last >= 0; --last) {
		if (mass[last] == 0) {
			l = false;
			break;
		}
	}
	long long sum = 0;
	if (l) {
		std::cout << "2. В массиве нет нулей \n";
	}
	else {
		if (last == n - 1) {
			std::cout << "2. Нуль является последним элементом массива, суммы нет \n";
		}
		else {
			for (; last < n; ++last) {
				sum += mass[last];
			}
			std::cout << "2. Сумма элементов после последнего 0 равна: " << sum << std::endl;
		}
	}
	// 3 - преобразование массива
	int t = n - 1;
	while (std::abs(mass[t]) > 5) {
		--t;
	}
	for (int i = t; i >= 0; --i) {
		if (std::abs(mass[i]) > 5) {
			std::swap(mass[i], mass[t]);
			--t;
		}
	}
	std::cout << "3. Порядок элементов преобразованного массива: ";
	for (int i = 0; i < n; ++i) {
		std::cout << " " << mass[i];
	}
	std::cout << std::endl;
	delete[] mass;
	system("pause");
	return 0;
}