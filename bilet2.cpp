#include <iostream>
#include <cmath>

// Функція для обчислення суми додатних елементів масиву
double sumOfPositiveElements(double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }
    return sum;
}

// Функція для обчислення добутку елементів масиву, розташованих між максимальним за модулем і мінімальним за модулем елементами
double productBetweenMinMax(double arr[], int size) {
    int maxIndex = 0;
    int minIndex = 0;

    // Знаходимо індекси максимального та мінімального за модулем елементів
    for (int i = 1; i < size; i++) {
        if (std::abs(arr[i]) > std::abs(arr[maxIndex])) {
            maxIndex = i;
        }
        if (std::abs(arr[i]) < std::abs(arr[minIndex])) {
            minIndex = i;
        }
    }

    // Визначаємо початковий та кінцевий індекси для обчислення добутку
    int startIndex = std::min(maxIndex, minIndex) + 1;
    int endIndex = std::max(maxIndex, minIndex) - 1;

    // Обчислюємо добуток елементів між максимальним та мінімальним елементами
    double product = 1;
    for (int i = startIndex; i <= endIndex; i++) {
        product *= arr[i];
    }

    return product;
}

// Функція для сортування масиву за спаданням (використовує алгоритм сортування "бульбашкою")
void sortDescending(double arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Обмін значень
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    std::cout << "Введіть розмір масиву: ";
    std::cin >> size;

    double* arr = new double[size];

    std::cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < size; i++) {
        std::cout << "Елемент " << i << ": ";
        std::cin >> arr[i];
    }

    // Обчислення та виведення суми додатних елементів масиву
    double sum = sumOfPositiveElements(arr, size);
    std::cout << "Сума додатних елементів: " << sum << std::endl;

    // Обчислення та виведення добутку елементів між максимальним та мінімальним елементами
    double product = productBetweenMinMax(arr, size);
    std::cout << "Добуток елементів між максимальним та мінімальним: " << product << std::endl;

    // Сортування масиву за спаданням
    sortDescending(arr, size);

    // Виведення відсортованого масиву
    std::cout << "Відсортований масив (за спаданням): ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}
