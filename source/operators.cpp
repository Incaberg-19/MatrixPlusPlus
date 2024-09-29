#include "../s21_matrix_oop.h"

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  S21Matrix temp(other);
  *this = std::move(temp);
  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  if (this != &other) {
    deleteMatrix();
    new (&*this) S21Matrix(std::move(other));
  }
  return *this;
}

double &S21Matrix::RowProxy::operator[](int j) {
  if (j >= col_ || j < 0) {
    throw std::out_of_range("Col index out of range");
  }
  return row_[j];
}

S21Matrix::RowProxy S21Matrix::operator[](int i) {
  if (i >= rows_ || i < 0) {
    throw std::out_of_range("Row index out of range");
  }
  return RowProxy(matrix_[i], cols_);
}

S21Matrix S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}
S21Matrix S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}
S21Matrix S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}
S21Matrix S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}
bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix temp(*this);
  temp.SumMatrix(other);
  return temp;
}
S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix temp(*this);
  temp.SubMatrix(other);
  return temp;
}
S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix temp(*this);
  temp.MulMatrix(other);
  return temp;
}
S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix temp(*this);
  temp.MulNumber(num);
  return temp;
}
