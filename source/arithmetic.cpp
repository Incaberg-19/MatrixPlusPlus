#include "../s21_matrix_oop.h"

void S21Matrix::SumMatrix(const S21Matrix& other) { SumSubMatrix(other, true); }

void S21Matrix::SubMatrix(const S21Matrix& other) {
  SumSubMatrix(other, false);
}

void S21Matrix::SumSubMatrix(const S21Matrix& other, bool isSum) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error("Rows and colums must be equal");
  }
  if (matrix_ == nullptr) {
    throw std::invalid_argument("Self matrix are not initialized");
  }
  if (other.matrix_ == nullptr) {
    throw std::invalid_argument("Came matrix are not initialized");
  }

  S21Matrix temp(rows_, cols_);
  long double tempValue = 0.0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (isSum == true) {
        tempValue = matrix_[i][j] + other.matrix_[i][j];
      } else {
        tempValue = matrix_[i][j] - other.matrix_[i][j];
      }
      checkOverflow(tempValue);
      temp[i][j] = tempValue;
    }
  }
  *this = std::move(temp);
}

void S21Matrix::MulNumber(const double num) {
  if (matrix_ == nullptr) {
    throw std::invalid_argument("Self matrix are not initialized");
  }
  S21Matrix temp(rows_, cols_);
  long double tempValue = 0.0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      tempValue = num * matrix_[i][j];
      checkOverflow(tempValue);
      temp[i][j] = tempValue;
    }
  }
  *this = std::move(temp);
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (matrix_ == nullptr) {
    throw std::invalid_argument("Self matrix are not initialized");
  }
  if (other.matrix_ == nullptr) {
    throw std::invalid_argument("Came matrix are not initialized");
  }

  if (cols_ != other.rows_) {
    throw std::logic_error("Cols self matrix should be equal rows came matrix");
  }

  S21Matrix temp(rows_, other.cols_);
  long double tempValue = 0.0;

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      tempValue = 0.0;
      for (int k = 0; k < other.rows_; k++) {
        tempValue += matrix_[i][k] * other.matrix_[k][j];
      }
      checkOverflow(tempValue);
      temp.matrix_[i][j] = tempValue;
    }
  }
  *this = std::move(temp);
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool returnValue = true;
  if (matrix_ == nullptr) {
    throw std::invalid_argument("Self matrix are not initialized");
  }
  if (other.matrix_ == nullptr) {
    throw std::invalid_argument("Came matrix are not initialized");
  }

  if (rows_ != other.rows_ || cols_ != other.cols_) {
    returnValue = false;
  }

  for (int i = 0; i < rows_ && returnValue == true; i++) {
    for (int j = 0; j < cols_ && returnValue == true; j++) {
      if (s21_check_accuracy(matrix_[i][j], other.matrix_[i][j], ACCURACY) ==
          1) {
        returnValue = false;
      }
    }
  }
  return returnValue;
}