#include <iostream>
int get_sum(int **matrix, int n, int m) {
	std::cout << "1.\n";
	char num_of_z = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			long long sum = 0;
			if (matrix[i][j] == 0) {
				++num_of_z;
				for (int k = 0; k < m; ++k) {
					sum += matrix[i][k];
				}
				std::cout << " Сумма элементов " << i + 1 << " строки равна: " << sum << " \n";
				break;
			}
		}
	}
	if ((num_of_z != n) && (num_of_z != 0)) {
		std::cout << " В остальных строках нулей нет\n";
	}
	if (num_of_z == 0) {
		std::cout << " В матрице нулей нет\n";
	}
	return 1;
}
int get_sedl(int **matrix, int n, int m) {
	int* min = new int[n];
	for (int i = 0; i < n; ++i) {
		int min_n = matrix[i][0];
		for (int j = 1; j < m; ++j) {
			if (matrix[i][j] < min_n) {
				min_n = matrix[i][j];
			}
		}
		min[i] = min_n;
	}
	int* max = new int[m];
	for (int j = 0; j < m; ++j) {
		int max_n = matrix[0][j];
		for (int i = 0; i < n; ++i) {
			if (matrix[i][j] > max_n) {
				max_n = matrix[i][j];
			}
		}
		max[j] = max_n;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (matrix[i][j] == min[i] && matrix[i][j] == max[j])
				ans++;
		}
	}
	return ans;
}
int **get_new_matrix(int** matrix, int n, int m) {
	std::cout << "3.\n"<<" Преобразованная матрица имеет вид:\n";
	int* mass_sum = new int[n];
	for (int i = 0; i < n; ++i) {
		int sum_n = 0;
		for (int j = 0; j < m; ++j) {
			if (matrix[i][j] > 0) {
				sum_n += matrix[i][j];
			}
		}
		mass_sum[i] = sum_n;
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i; j < n; ++j) {
			if (mass_sum[j] < mass_sum[i]) {
				std::swap(matrix[i], matrix[j]);
				std::swap(mass_sum[i], mass_sum[j]);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout <<" "<< matrix[i][j];
		}
		std::cout<<std::endl;
	}	
	return matrix;
}
int get_n_column(int** matrix, int n, int m) {
	int ans = 0;
	for (int j = 0; j < m; ++j) {
		bool f = 1;
		for (int i = 0; i < n; ++i) {
			if (matrix[i][j] ==0) {
				f = 0;
			}
		}
		if (f) {
			++ans;
		}
	}
	std::cout << "4.\n"<<" Количество столбцов, не содержащих 0, равно: " << ans<<"\n";
	return ans;
} 
int main() {
	setlocale(LC_ALL, "rus");
	int n = 0, m = 0;
	std::cout << "Введите количество строк матрицы: ";
	std::cin >> n;
	if (n < 1 || n>20) {
		std::cout << "Количество строк в матрице должно входить в диапазон от 1 до 20";
		return 1;
	}
	std::cout << "Введите количество столбцов матрицы: ";
	std::cin >> m;
	if (m < 1 || n>20) {
		std::cout << "Количество столбцов в матрице должно входить в диапазон от 1 до 20";
		return 1;
	}
	int **matrix = new int* [n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new int[m];
	}
	std::cout << "Введите элементы матрицы: \n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> matrix[i][j];
		}
	}
	get_sum(matrix, n, m);
	std::cout << "2.\n Количество всех седловых точек матрицы равно: " << get_sedl(matrix, n, m) << std::endl;
	get_new_matrix(matrix, n, m);
	get_n_column(matrix, n, m);
	for (int i = 0; i < n; i++) {
		delete [] matrix[i];
	}
	delete[] matrix;
	return 0;
}