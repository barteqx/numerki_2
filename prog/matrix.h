#ifndef __MATRIX_H
#define __MATRIX_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

class Matrix {
 protected:
  std::vector<std::vector<double> > mat;
  unsigned int size;

 public:
  Matrix(unsigned int _size, double _initial);
  Matrix(const Matrix& rhs);
  ~Matrix();

  // Operator overloading, for "standard" mathematical matrix operations                                                                                                                                                          
  void operator=(const Matrix& rhs);

  // Matrix mathematical operations                                                                                                                                                                                               
  Matrix operator+(const Matrix& rhs);
  Matrix operator-(const Matrix& rhs);
  Matrix operator*(const Matrix& rhs);

  // Matrix/scalar operations                                                                                                                                                                                                     
  Matrix operator*(double rhs);

  Matrix L();
  Matrix D();
  Matrix U();
  Matrix N();

  // Matrix/vector operations                                                                                                                                                                                                     
  std::vector<double> operator*(const std::vector<double>& rhs);

  // Access the individual elements                                                                                                                                                                                               
  const double operator()(unsigned int row, unsigned int col) const;

  // Access the row and column sizes                                                                                                                                                                                              
  unsigned int get_size() const;

};

class HillbertMatrix : public Matrix {
public:
    HillbertMatrix(unsigned int _size);
};

class PeyaMatrix : public Matrix {
public:
    PeyaMatrix(unsigned int _size, double d);
};

double norm_inf(std::vector<double> & vec);

const std::vector<double> operator-(const std::vector<double> & lhs, const std::vector<double> & rhs);

const std::vector<double> operator+(const std::vector<double> & lhs, const std::vector<double> & rhs);

std::ostream& operator<<(std::ostream& out, const std::vector<double>& vec);

std::ostream& operator<<(std::ostream& out, const Matrix & m);

#endif