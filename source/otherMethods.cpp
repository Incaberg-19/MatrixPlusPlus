#include "../s21_matrix_oop.h"

void S21Matrix::print() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      std::cout << matrix_[i][j] << " ";
    }
    std::cout << "\n";
  }
}

void S21Matrix::deleteMatrix() {
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

void S21Matrix::SetRows(int rows) {
  S21Matrix temp(rows, cols_);
  for (int i = 0; i < ((rows_ < rows) ? rows_ : rows); i++) {
    for (int j = 0; j < cols_; j++) {
      temp.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = std::move(temp);
}

void S21Matrix::SetCols(int cols) {
  S21Matrix temp(rows_, cols);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < ((cols_ < cols) ? cols_ : cols); j++) {
      temp.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = std::move(temp);
}