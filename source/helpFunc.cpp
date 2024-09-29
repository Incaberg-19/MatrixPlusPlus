#include <limits>

#include "../s21_matrix_oop.h"

void checkOverflow(long double checkVar) {
  if (checkVar >= std::numeric_limits<double>::max()) {
    throw std::overflow_error("Overflow was discovered");
  }
  if (checkVar <= std::numeric_limits<double>::lowest()) {
    throw std::underflow_error("Underflow was discovered");
  }
  if (S21_IS_INF(checkVar)) {
    throw std::runtime_error("Infinity was discovered");
  }
  if (S21_IS_NAN(checkVar)) {
    throw std::runtime_error("Nan was discovered");
  }
}

long double s21_fabs(double x) { return (x < 0) ? x * (-1) : x; }

bool s21_check_accuracy(double a, double b, double epsilon) {
  double diff = s21_fabs(a - b);
  return (diff > epsilon);
}