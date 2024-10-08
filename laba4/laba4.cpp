#include <iostream>
#include <vector>
#include <climits>  // Для INT_MIN

// Функция для вывода матрицы
void printMatrix(const std::vector<std::vector<int>>& matrix) {
  for (const auto& row : matrix) {
    for (int elem : row) {
      std::cout << elem << "\t";
    }
    std::cout << std::endl;
  }
}

int main() {

  setlocale(LC_ALL, "rus");

  // Пример заданной матрицы
  std::vector<std::vector<int>> H = {
      {1, -2, 3, 4},
      {-5, 6, -7, 8},
      {9, -10, 11, -12},
      {13, 14, -15, 16}
  };

  // Вывод исходной матрицы
  std::cout << "Исходная матрица:" << std::endl;
  printMatrix(H);
  std::cout << std::endl;

  // Обработка матрицы
  std::vector<int> positiveCount(H.size(), 0);
  std::vector<int> maxPositive(H.size(), INT_MIN);

  for (size_t i = 0; i < H.size(); ++i) {
    for (int elem : H[i]) {
      if (elem > 0) {
        ++positiveCount[i];
        if (elem > maxPositive[i]) {
          maxPositive[i] = elem;
        }
      }
    }
  }

  // Вывод результатов
  std::cout << "Результаты обработки:" << std::endl;
  for (size_t i = 0; i < H.size(); ++i) {
    std::cout << "Строка " << i + 1 << ": "
      << "Число положительных элементов = " << positiveCount[i]
      << ", Наибольший положительный элемент = " << maxPositive[i] << std::endl;
  }

  return 0;
}