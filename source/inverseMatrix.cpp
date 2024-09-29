#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  if (s21_check_accuracy(det, 0.0, ACCURACY) == false) {
    throw std::invalid_argument("Self matrix determinant equal zero");
  }
  S21Matrix result(*this);
  result = result.CalcComplements();
  result = result.Transpose();
  result.MulNumber(1 / det);

  return result;
}