#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
using namespace std;


class Matrix
{
    public:
        Matrix(int a,int b,int num[]);
        Matrix();
        Matrix(const Matrix& mat);
        Matrix operator=(const Matrix& mat);
        ~Matrix();


        Matrix operator+(Matrix mat1);
        Matrix operator-(Matrix mat1);
        Matrix operator*(Matrix mat1);
        Matrix operator+ (int scalar);
        Matrix operator- (int scalar);
        Matrix operator* (int scalar);


        Matrix& operator+=(const Matrix& mat);
        Matrix& operator-= (const Matrix& mat);
        Matrix operator+= (int scalar);
        Matrix operator-= (int scalar);
        void  operator++ ();
        void  operator--();
        friend istream& operator>> (istream& in, Matrix& mat);
        friend ostream& operator<< (ostream& out, Matrix& mat);

    private:
        int row,col;
        int *data;
};

#endif // MATRIX_H
