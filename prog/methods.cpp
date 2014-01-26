#include "methods.h"
#include "matrix.h"

 void jacobi_method(Matrix & m, std::vector<double> & b, double precision) {
  Matrix D = m.D();
  Matrix L = m.L();
  Matrix U = m.U();
  Matrix N = m.N();
  Matrix M = N * (-1.0) * (L + U);
  
  std::vector<double> current(b.size(), 20);
  std::vector<double> next;
  int iteration = 0;
  double error;

  do {
    iteration++;
    next = M*current + N*b;
    std::vector<double> e = next - current;
    error = norm_inf(e)/norm_inf(next);
    std::cout << iteration << ": " << next << " error: " << error << std::endl;
    current = next;
  } while (fabs(error) >= precision);
}

void gauss_seidel_method(Matrix & m, std::vector<double> & b, double precision) {
  Matrix D = m.D();
  Matrix L = m.L();
  Matrix U = m.U();
  Matrix N = m.N();

  std::vector<double> current(b.size(), 0.0);
  std::vector<double> next;
  int iteration = 0;
  double error;

  do {
    iteration++;
    next = N*b - (N*L)*current - (N*U)*current;
    std::vector<double> e = next - current;
    error = norm_inf(e)/norm_inf(next);
    std::cout << iteration << ": " << next << " error: " << error << std::endl;
    current = next;
  } while (fabs(error) >= precision);

}