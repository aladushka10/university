#include <iostream>
#include <vector>
#include <pthread.h>
#include <unistd.h>

std::vector<int> arr;
int min, max, avg;
pthread_t min_max_thread, average_thread; //переменные для хранения идентификаторов потоков

void* find_min_max(void*) {
    min = arr[0];
    max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
        usleep(7000); // 7 миллисекунд
    }
    std::cout << "Минимальный элемент: " << min << std::endl;
    std::cout << "Максимальный элемент: " << max << std::endl;
    return NULL;
}

void* find_average(void*) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        usleep(12000); // 12 миллисекунд
    }
    avg = sum / arr.size();
    std::cout << "Среднее арифметическое: " << avg << std::endl;
    return NULL;
}

int main() {
    int size;
    std::cout << "Введите размерность массива: ";
    std::cin >> size;
    arr.resize(size);

    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    pthread_create(&min_max_thread, NULL, find_min_max, NULL);
    pthread_create(&average_thread, NULL, find_average, NULL);

    pthread_join(min_max_thread, NULL); //для ожидания завершения работы потоков
    pthread_join(average_thread, NULL);

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == min || arr[i] == max) {
            arr[i] = avg;
        }
    }

    std::cout << "Измененный массив: ";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}