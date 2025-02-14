#include <iostream>
#include <fstream>
#include <string>

int main() {
	setlocale(LC_ALL, "rus");
	std::string file_in, file_out1, file_out2;
	std::cout << "Введите имя исходного файла: \n";
	std::cin >> file_in;
	std::cout << "Введите имя первого выходного файла: \n";
	std::cin >> file_out1;
	std::cout << "Введите имя второго выходного файла: \n";
	std::cin >> file_out2;
	//  std::ifstream input ("C:\\Users\\kapit\\OneDrive\\Рабочий стол\\проекты\\input.txt");
	std::ifstream input(file_in);
	std::ofstream out1(file_out1);
	std::ofstream out2(file_out2);

	if (!input.is_open()) {
		std::cerr << "Error";
		return 1;
	}
	std::string str;
	while (!input.eof()) {
		std::getline(input, str);
	    std::cout << "(" << str << ")";
		int count = size(str);
		bool down = true, up = true;
		int n = 0;
		for (int i = 0; i < count-1; ++i) {
			if (str[i] < str[i + 1]) {
				down = false;
			}
			if (str[i] > str[i + 1]) {
				up = false;
			}
		}
		if (up) {
			//          std::cout <<" не убывает"<< "\n";
			out1 << str << "\n";
		}
		if (down) {
			//          std::cout << " не возрастает" << "\n";
			out2 << str << "\n";
		}
	}

	input.close();
	out1.close();
	out2.close();
	return 0;
}