#include <bits/stdc++.h>

using namespace std;

template <typename T> class Matrix
{
    
public:
    
    Matrix(int height, int width){n = height; m = width;};
    ~Matrix() {delete elements;};
    
    Matrix column(T j) {
        //Returns the j-th column of the matrix, we assume j < m.
        Matrix<T> res(n, 1);
        for (T i = 0; i < n; i++){
            res(i, 1) = elements[i][j];
        }
        return res;
    };
    
    Matrix row(T i) {
        //Returns the i-th row of the matrix, we assume i < n.
        Matrix<T> res(1, m);
            for (T j = 0; j < n; j++){
                res(1, j) = elements[i][j];
            }
        return res;
    };
    
    Matrix operator()(T i,T j) {return elements[i][j];};
    
    Matrix operator + (const Matrix& a) {
        //An operator for the additions between two matrices.
        Matrix<T> res(n, m);
        for (T i = 0; i < n; i++) {
            for (T j = 0; j < m; j++) {
                res(i, j) = elements[i][j] + a(i, j);
            }
        }
        return res;
    };
    
    Matrix operator - (const Matrix& a) {
        //An operator for the substractions between two matrices.
        Matrix<T> res(n, m);
        for (T i = 0; i < n; i++) {
            for (T j = 0; j < m; j++) {
                res(i, j) = elements[i][j] - a(i, j);
            }
        }
        return res;
    };
    
    Matrix operator * (const T& k) {
        //An operator for the multiplications between a matrix and a scalar, which will be useful to compute the determinant.
        Matrix<T> res(n, m);
        for (T i = 0; i < n; i++) {
            for (T j = 0; j < m; j++) {
                res(i, j) = k * elements[i][j];
            }
        }
        return res;
    };
    
    Matrix operator * (const Matrix& a) {
        //An operator for the multiplications between two matrices.
        
    };
    
    T det(){
    //Computes the determinant of a matrix.
    };
    
    Matrix adj() {
    //Computes the adjacent matrix of a matrix.
    };
    Matrix inverse(){
    //Computes the inverse of a matrix.
    };
    
private:
    int n, m;
    vector< vector<T> > elements ;
};
