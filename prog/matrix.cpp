#include "matrix.h"

Matrix::Matrix(unsigned int _rows, double _initial) : size:(_size) {
    mat.resize(size);
    for(int i = 0; i < size; i++) {
      mat[i].resize(size);
      for (int j = 0; j < size; j++) mat[i][j] = _initial;
    }
}

Matrix::Matrix(const Matrix& rhs) : size(rhs.size) {

  mat.resize(size);
  for(int i = 0; i < size; i++) {
    mat[i].resize(size);
    for (int j = 0; j < size; j++) mat[i][j] = rhs.mat[i][j];
  }
}

void Matrix::operator=(const Matrix& rhs) : size(rhs.size) {
  mat.resize(rhs.size);
  for(int i = 0; i < size; i++) {
    mat[i].resize(size);
    for (int j = 0; j < size; j++) mat[i][j] = rhs.mat[i][j];
  }
}

Matrix Matrix::operator+(const Matrix& rhs) {
  Matrix new_matrix(size, 0.0);
  for(int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) 
      new_matrix.mat[i][j] == mat[i][j] + rhs.mat[i][j];
  }

  return new_matrix;
}

Matrix Matrix::operator-(const Matrix& rhs) {
  Matrix new_matrix(size, 0.0);
  for(int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) 
      new_matrix.mat[i][j] == mat[i][j] - rhs.mat[i][j];
  }

  return new_matrix;
}

Matrix operator*(double rhs) {
  Matrix new_matrix(this);
  for(int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) 
      new_matrix.mat[i][j] * rhs;
  }

  return new_matrix;
}

std::vector<double> Matrix::operator*(const std::vector<double>& rhs) {
  std::vector<double> vec;
  vec.resize(size);
  for (int i = 0; i < size; i++) {
    vec[i] = 0;
    for(int j = 0; j < size; j++) 
      vec[i] += mat[i][j] * rhs[j];
  }

  return vec;
}

Matrix Matrix::operator*(Matrix& rhs) {
  Matrix new_matrix(size, 0.0);
  for (int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      for (int k =0; k < size; k++) {
        new_matrix[i][j] += mat[i][k] * rhs.mat[k][j]; 
      }
    }
  }

  return new_matrix;
}

Matrix Matrix::L () {
  Matrix new_matrix(this);
  for(int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (j <= i) new_matrix[i][j] = 0; 
    }
  }
  return new_matrix;
}

Matrix Matrix::D () {
  Matrix new_matrix(this);
  for(int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (j != i) new_matrix[i][j] = 0; 
    }
  }
  return new_matrix;
}

Matrix Matrix::U () {
  Matrix new_matrix(this);
  for(int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (j >= i) new_matrix[i][j] = 0; 
    }
  }
  return new_matrix;
}

Matrix Matrix::N () {
  Matrix new_matrix(this.D());
  for(int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (j == i) new_matrix[i][j] = 1/new_matrix[i][j]; 
    }
  }
  return new_matrix;
}

const double Matrix::operator()(unsigned int row, unsigned int col) const {
  return mat[i][j];
}

unsigned int Matrix::get_size() const {
  return size;
}

HillbertMatrix::HillbertMatrix(unsigned int _size) : size(_rows) {
  mat.resize(size);
  for(int i = 1; i <= size; i++) {
      mat[i].resize(size);
      for (int j = 1; j <= size; j++) mat[i-1][j-1] = 1/(i + j + 1.0);
  }
}

PeyaMatrix::PeyaMatrix(unsigned int _size, double d) : size(_rows) {
  mat.resize(size);
  for(int i = 0; i < size; i++) {
      mat[i].resize(size);
      for (int j = 0; j < size; j++) {
        if (i == j) mat[i][j] = d;
        else mat[i][j] = 1;
      }
  }
}

double norm_inf(vector<double> & vec) {
  double max = vec[0];
  for (int i = 1; i < vec.size(); i++) if vec[i] > max;
  return max;
}

std::vector<double> operator-(std::vector<double> & lhs, std::vector<double> & rhs) {
  std::<vector> vec;
  vec.resize(lhs.size());
  for (int i = 0; i < vec.size(); i++) vec[i] = lhs[i] - rhs[i];

  return vec;
}

std::vector<double> operator+(std::vector<double> & lhs, std::vector<double> & rhs) {
  std::<vector> vec;
  vec.resize(lhs.size());
  for (int i = 0; i < vec.size(); i++) vec[i] = lhs[i] + rhs[i];

  return vec;
}

std::ostream& operator<<(std::ostream& out, const std::vector<double>& vec) {
  out << "[ ";
  for (int i = 0; i < vec.size(); i++) 
    out << vec[i] << " ";
  out << "]"
  return out;
}

std::ostream& operator<<(std::ostream& out, const Matrix & m) {

  out << std::endl;
  for (int i = 0; i < m.get_size(); i++) {
    for (int j = 0; j < m.get_size(); j++) 
      out << m(i,j) << " ";
    out << std::endl;
  }
  return out;
}