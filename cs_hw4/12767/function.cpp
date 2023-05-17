// 12767 - The One Function and The Power Of Matrix 
// all accepted
#include "function.h"
#include<math.h>
// TODO: The Destructor
Matrix::~Matrix(){
    for(int i=0;i<n;i++)
        delete [] matrix[i];
    delete [] matrix;
}

// TODO: The Customize Constructor
Matrix::Matrix(int n){
    this->n = n;
    matrix = new long long*[n];
    for(int i=0;i<n;i++) matrix[i] = new long long[n];
    this->toZero();
}

// TODO: Copy contructor
// Will be trigger when the following condition:
// Matrix m = ref; -> Call copy contructor to copy from 'ref' to 'm'
Matrix::Matrix(const Matrix& ref){
    n = ref.n;
    // create new array
    matrix = new long long*[n];
    for(int i=0;i<n;i++) matrix[i] = new long long[n];
    // copy data
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            matrix[i][j] = ref.matrix[i][j];
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
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) matrix[i][j] = 1;
            else matrix[i][j] = 0;
        }
    }
}

// TODO: Overload operator * 
Matrix Matrix::operator*(const Matrix& rhs) const{
    Matrix* m = new Matrix(n);
    m->toZero();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int b=0;b<rhs.n;b++){
                m->matrix[i][j] = (m->matrix[i][j] + (this->matrix[i][b] * rhs.matrix[b][j])%mod)%mod;
            }
        }
    }
    return *m;
}

// TODO: Return the matrix power of 'k'
Matrix Matrix::power(int k) const{
    Matrix* init = new Matrix(n),* ret = new Matrix(n);
    init->toIdentity();
    *ret = *this;
    int power=0,k_p = k;
    while(k>0){
        if(k%2==1) *init = *init * *ret;
        *ret = *ret * *ret;
        k/=2;
    }
    return *init;
}

// TODO: Construct a matrix
Matrix constructMatrix(int n){
    Matrix* m = new Matrix(n);
    for(int i=0;i<n;i++) (*m)(n-1,i) = 1;
    for(int i=n-2;i>=0;i--) (*m)(i,i+1) = 1;
    return *m;
}
