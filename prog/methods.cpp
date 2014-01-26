#include "methods.h"
#include "matrix.h"

 void jacobi_method(Matrix & m, std::vector<double> & b, double precision) {

  std::vector<double> current(b.size(), 20);
  std::vector<double> next(b.size(), 0.0);
  int iteration = 0;
  double error;

  do {
    iteration++;
    // next = M*current + N*b;

    for (int i = 0; i < b.size(); i++) {
      next[i] = b[i];
      for (int j = 0; j < b.size(); j++) {
        if (i != j) next[i] -= m(i,j)*current[j];
      }
      next[i] /= m(i,i);
    }
    std::vector<double> e = next - current;
    error = norm_inf(e)/norm_inf(next);
    std::cout << std::fixed << std::setprecision(9) << iteration << ": " << next << " error: " << error << std::endl;
    current = next;
  } while (fabs(error) >= precision);
}

void gauss_seidel_method(Matrix & m, std::vector<double> & b, double precision) {
  std::vector<double> current(b.size(), 0.0);
  std::vector<double> next(b.size(), 0.0);
  int iteration = 0;
  double error;

  do {
    iteration++;
    for (int i = 0; i < b.size(); i++) {
      next[i] = b[i];
      for (int j = 0; j < b.size(); j++) {
        if (i > j) next[i] -= m(i,j)*next[j];
        else if (i < j) next[i] -= m(i,j)*current[j];
      }
      next[i] /= m(i,i);
    }
    std::vector<double> e = next - current;
    error = norm_inf(e)/norm_inf(next);
    std::cout << std::fixed << std::setprecision(9) << iteration << ": " << next << " error: " << error << std::endl;
    current = next;
  } while (fabs(error) >= precision);

}