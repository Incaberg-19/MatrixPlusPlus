#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  if (matrix_ == nullptr) {
    throw std::invalid_argument("Self matrix are not initialized");
  } else if (s21_check_accuracy(Determinant(), 0.0, ACCURACY) == false) {
    throw std::invalid_argument("Self matrix determinant equal zero");
  } else if (rows_ != cols_) {
    throw std::logic_error("Rows and colums must be equal");
  }

  S21Matrix result(rows_, cols_);
  if (rows_ == cols_ && rows_ == 1) {
    result[0][0] = 1;
  } else {
    S21Matrix temp(rows_ - 1, cols_ - 1);
    S21Matrix resTemp(rows_, cols_);

    for (int k = 0; k < rows_; k++) {
      for (int l = 0; l < cols_; l++) {
        int c = 0, h = 0;
        for (int i = 0; i < rows_; i++) {
          if (k == i) continue;

          for (int j = 0; j < cols_; j++) {
            if (l == j) continue;
            temp.matrix_[c][h] = matrix_[i][j];
            h++;
          }
          c++;
          h = 0;
        }
        resTemp.matrix_[k][l] = temp.Determinant();
        resTemp.matrix_[k][l] = ((k + l) & 1 ? -1 : 1) * resTemp.matrix_[k][l];
      }
    }
    result = std::move(resTemp);
  }
  return result;
}