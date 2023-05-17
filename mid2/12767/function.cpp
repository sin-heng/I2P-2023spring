#include "function.h"
// TODO: The Destructor
  Matrix::~Matrix(){
    for(int i=0;i<n;i++) delete [] matrix[i];
    delete [] matrix;
  }

  // TODO: The Customize Constructor
  Matrix::Matrix(int n):n(n){
    matrix = new long long*[n];
    for(int i=0;i<n;i++) matrix[i] = new long long[n];
    this->toZero();
  }
  
  // TODO: Copy contructor
  // Will be trigger when the following condition:
  // Matrix m = ref; -> Call copy contructor to copy from 'ref' to 'm'
  Matrix::Matrix(const Matrix& ref){
    n = ref.n;
    matrix = new long long*[n];
    for(int i=0;i<n;i++){
        matrix[i] = new long long[n];
        for(int j=0;j<n;j++) matrix[i][j] = ref.matrix[i][j];
    }
  }

  // TODO: copy assignment,
  // Will be trigger when the following condition:
  // Matrix a;
  // a = ref; -> Call copy assignment to copy from 'ref' to 'a'
  Matrix& Matrix::operator=(const Matrix& ref){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) 
            matrix[i][j] = ref.matrix[i][j];
    return *this;
  }

  // TODO: Overload operator()
  // This operator allow the following code
  // This operator can help you access the data easily
  // 1. cout << m(1, 2) << endl; -> Shorthand of `cout << m.matrix[1, 2] << endl;`
  // 2. m(1, 2) = 100; -> Shorthand of `m.matrix[1, 2] = 100`
  long long& Matrix::operator()(const int& row, const int& column) const{
    return matrix[row][column];
  }

  // Utilities functions
  // TODO: Make the matrix identity matrix
  void Matrix::toIdentity(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i==j) matrix[i][j] = 1;
            else matrix[i][j] = 0;
  }

  // TODO: Overload operator * 
  Matrix Matrix::operator*(const Matrix& rhs) const{
    Matrix tmp(n);
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            for(int k=0;k<rhs.n;k++)
                tmp.matrix[row][col] = (tmp.matrix[row][col] + (this->matrix[row][k] * rhs.matrix[k][col])%mod)%mod;
        }
    }
    return tmp;
  }

  // TODO: Return the matrix power of 'k'
  Matrix Matrix::power(int k) const{
    Matrix ret = *this, Init(n);
    Init.toIdentity();
    while(k>0){
      if(k%2==1) Init = ret * Init;
      ret = ret*ret;
      k/=2;
    }
    return Init;
}

// TODO: Construct a matrix
Matrix constructMatrix(int n){
  Matrix tmp(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==(n-1)) tmp(i,j)=1;
      else if(j==(i+1)) tmp(i,j)=1;
      else tmp(i,j)=0; 
    }
  }
  return tmp;
}
