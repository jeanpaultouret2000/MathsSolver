#include <bits/stdc++.h>

#include <vector>
#include <cmath>

using namespace std;

template <typename T> class Matrix
{

public:

    Matrix(int height, int width){n = height; m = width;};
    ~Matrix() {delete elements;};

    T height(){return n;};
    T width(){return m;};

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
        //An operator for the multiplications between two matrices, we assume that width = a.height.
        Matrix res(n, a.width);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a.width; j++) {
                T elm = 0;
                for (int k = 0; k < m; k++) {
                    elm += elements[i][k] * a(k, j);
                }
                res(i, j) = elm;
            }
        }
        return res;
    };
    
     bool operator = (const Matrix& a) {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {
                if (elements[i][j] != a(i, j)) {
                    return 0;
                }
            }
        }
        return 1;
    };
    

    Matrix crop_row(int r) {
    //Returns a matrix where the 1st column and the i-th row were removed, input is expected to be a square matrix.
        Matrix cropped(n-1, m-1);
        if (r > 0){
            for (int i = 0; i < r; i++) {
                for (int j = 1; j < m; j++){
                    cropped(i, j) = elements[i][j];
                }
            }
        }
        if (r+1 < m) {
            for (int i = r+1; i < m; i++) {
                for (int j = 1; j < m; j++){
                    cropped(i, j) = elements[i][j];
                }
            }
        }
        return cropped;
    };

    T det(){
    //Computes the determinant of a matrix, assuming it is a square matrix.
        if (n == 1) {
            return elements[0][0];
        } else {
            T d = 0;
            for (int i = 0; i < n; i++) {
                Matrix cropped = (*this).crop_row(i);
                if (i%2) {
                    d += cropped.det() * elements(i, 1);
                } else {
                    d -= cropped.det() * elements(i, 1);
                }
            }
            return d;
        }
    };

    Matrix adj() {
    //Computes the adjacent matrix of a matrix, assuming it is a square matrix.
    };
    Matrix inverse(){
    //Computes the inverse of a matrix, assuming it is a square matrix.
    };

private:
    int n, m;
    vector< vector<T> > elements ;
};
