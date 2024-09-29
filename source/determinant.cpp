#include "../s21_matrix_oop.h"

double S21Matrix::Determinant() {
  if (matrix_ == nullptr) {
    throw std::invalid_argument("Self matrix are not initialized");
  }
  if (rows_ != cols_) {
    throw std::logic_error("rows and cols should be equal");
  }

  double result = 0.0;
  int swapCount = 0;
  S21Matrix temp(*this);

  for (int i = 0; i < rows_; i++) {
    double ratio = 1.0;

    // Проверяем наличие ненулевого элемента в текущей строке или ниже
    int foundNonZero = 0;
    for (int j = i + 1; j < rows_ && !foundNonZero; j++) {
      if (temp[j][i] != 0) {
        // Обмен строк
        for (int k = 0; k < cols_; k++) {
          double tempValue = temp[i][k];
          temp[i][k] = temp[j][k];
          temp[j][k] = tempValue;
        }
        swapCount++;
        foundNonZero = 1;
      }
    }

    if (temp[i][i] == 0 && !foundNonZero) {
      result = 0;
      break;
    } else {
      // Приводим матрицу к треугольной форме
      for (int j = i + 1; j < rows_; j++) {
        if (temp[i][i] != 0) {
          ratio = temp[j][i] / temp[i][i];
          checkOverflow(ratio);
          for (int k = i; k < cols_; k++) {
            temp[j][k] -= ratio * temp[i][k];
            checkOverflow(result);
          }
        }
      }
    }
  }
  if (s21_check_accuracy(result, 0.0, ACCURACY) == false) {
    result = 1.0;
    for (int i = 0; i < rows_; i++) {
      result *= temp[i][i];
    }
    checkOverflow(result);
    // Меняем знак результата в зависимости от количества перестановок
    if (swapCount & 1) result *= -1;
  }

  return result;
}