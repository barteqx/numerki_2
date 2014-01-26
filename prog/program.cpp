#include "matrix.h"
#include "methods.h"

int main(int argc, char const *argv[])
{
  std::vector<std::string> arguments;
  std::vector<double> b;

  Matrix A(1, 0.0);

  char method, matrix;
  double precision, d;
  unsigned int size;


  for (int i = 1; i < argc; i++) {
    arguments.push_back(static_cast<std::string>(argv[i]));
  }

  while (!arguments.empty()) {

    if (arguments[0] == "-peya") {
      matrix = 'p';
      d = std::stod(arguments[1]);
      arguments.erase(arguments.begin(), arguments.begin()+2);
    }

    else if (arguments[0] == "-hillbert") {
      matrix = 'h';
      arguments.erase(arguments.begin(), arguments.begin()+1);
    }

    else if (arguments[0] == "-p") {
      precision = std::stod(arguments[1]);
      arguments.erase(arguments.begin(), arguments.begin()+2);
    }

    else if (arguments[0] == "-v") {
      size = std::stoi(arguments[1]);
      b.resize(size);
      for (int i = 2; i < size + 2; i++) b[i-2] = std::stod(arguments[i]);
      arguments.erase(arguments.begin(), arguments.begin() + size + 2);
    }

    else if (arguments[0] == "-j") {
      method = 'j';
      arguments.erase(arguments.begin(), arguments.begin()+1);
    }

    else if (arguments[0] == "-gs") {
      method = 's';
      arguments.erase(arguments.begin(), arguments.begin()+1);
    }

    else {
      std::cout << "unknown parameter!\n";
      exit(1);
    }
  }


  switch (matrix) {
    case 'p':
      A = PeyaMatrix(size, d);
      break;

    case 'h':
      A = HillbertMatrix(size);
      break;
  }

  switch (method) {
    case 'j':
      jacobi_method(A, b, precision);
      break;

    case 's':
      gauss_seidel_method(A, b, precision);
      break;
  }

  return 0;
}


