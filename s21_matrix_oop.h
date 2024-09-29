#ifndef S21_MATRIX_OOP
#define S21_MATRIX_OOP

#include <iostream>

#define ACCURACY 1e-7
#define S21_INF_NEGATIVE (-1.0 / 0.0)
#define S21_INF_POSITIVE (+1.0 / 0.0)

#define S21_IS_NAN(x) (x != x)
#define S21_IS_INF(x) (x == S21_INF_POSITIVE || x == S21_INF_NEGATIVE)

void checkOverflow(long double checkVar);
long double s21_fabs(double x);
bool s21_check_accuracy(double a, double b, double epsilon);

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

  class RowProxy {
   private:
    double* row_;  // pointer to row
    int col_;      // number of element
   public:
    RowProxy(double* ptrRow, int col) : row_(ptrRow), col_(col){};
    double& operator[](int j);
  };

 public:
  S21Matrix(const S21Matrix& other);
  S21Matrix(int rows, int cols);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();
  S21Matrix();

  void MulMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  bool EqMatrix(const S21Matrix& other);
  void MulNumber(const double num);

  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();
  S21Matrix Transpose();
  double Determinant();

  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*=(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*=(const double num);
  S21Matrix::RowProxy operator[](int i);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix& other);

  void SumSubMatrix(const S21Matrix& other, bool isSum);
  void SetRows(int rows);
  void SetCols(int cols);
  int getRows() const { return rows_; };
  int getCols() const { return cols_; };
  void deleteMatrix();
  void print();
};

#endif