#include "methods.h"
#include "matrix.h"

void jacobi_method(Matrix & m, std::vector<double> & b, double precision) {
  Matrix D = m.D();
  Matrix L = m.L();
  Matrix U = m.U();
  Matrix N = m.N();
  Matrix M = (N * (-1.0)) * (L + U);

  std::vector<double> current(b.size(), 0.0);
  std::vector<double> next;
  int iteration = 0;

  do {
    iteration++;
    next = M*current + N*b;
    double error = norm_inf(next - current)/norm_inf(next);
    std::cout << iteration << ": " << next << " error: " << error << std::endl;
  } while (error >= precision);
}

void gauss_siedel_method(Matrix & m, std::vector<double> & b, double precision) {
  Matrix D = m.D();
  Matrix L = m.L();
  Matrix U = m.U();
  Matrix N = m.N();

  std::vector<double> current(b.size(), 0.0);
  std::vector<double> next;

  do {
    next = N*b - (N*L)*current - (N*U)*current;
    double error = norm_inf(next - current)/norm_inf(next);
    std::cout << next << " error: " << error << std::endl;
  } while (error >= precision);

}