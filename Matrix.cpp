#include<iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(int a,int b,int num[])
{
    row=a;
    col=b;
    data = new int [row * col];
    for (int i = 0; i < row * col; i++)
    data [i] = num [i];
}
Matrix::Matrix(){}

Matrix:: Matrix (const Matrix& mat){
    row=mat.row;
    col=mat.col;
    data=new int [row*col];
    for(int i=0;i<col*row;i++){

       data[i]=mat.data[i];

    }



}
Matrix Matrix::operator=(const Matrix& mat){
    row=mat.row;
    col=mat.col;
    data=new int [row*col];
    for(int i=0;i<col*row;i++){

       data[i]=mat.data[i];

    }
    return *this;

}
Matrix:: ~Matrix(){
delete[]data;
}
Matrix Matrix:: operator+(Matrix mat1){

    int data3[row*col];
    Matrix mat3(mat1.row,mat1.col , data3);
    if(mat1.row == this->row && this->col==mat1.col){
        for (int i = 0 ; i < row*col; i++){
                mat3.data[i] = this->data[i] + mat1.data[i];

        }
         return mat3 ;
    }
}

Matrix Matrix:: operator-(Matrix mat1){


    int data3[row*col];
    Matrix mat3(mat1.row,mat1.col , data3);
    if(mat1.row == this->row && this->col==mat1.col){
        for (int i = 0 ; i < row*col; i++){
                mat3.data[i] = this->data[i] - mat1.data[i];

        }
         return mat3 ;
    }
}


Matrix Matrix:: operator*  (Matrix mat1)
{
    int data[row * col];
    Matrix mat3(this->row , mat1.col , data);;

    if(this->col==mat1.row)
    {
        for (int i = 0; i < this->row ; i++)
        {
            for (int j = 0; j < mat1.col  ; j++)
            {
                int sum = 0;
                for (int k = 0; k < this->col  ; k++)
            {


                sum += this->data[i*this->col+k] * mat1.data[k*mat1.col+j] ;
                mat3.data[i*mat1.col+j] = sum ;

            }

            }
        }return mat3 ;}}

Matrix Matrix:: operator+(int scalar)
{
    int data[row * col];
    Matrix mat3(row , col , data);
    for (int i = 0; i < this->row * this->col ; i++)
        {
            mat3.data[i]= this->data [i] + scalar ;
        }
        return mat3;
}

Matrix Matrix:: operator-(int scalar)
{
    int data[row * col];
    Matrix mat3(row , col , data);
    for (int i = 0; i < this->row * this->col ; i++)
        {
            mat3.data[i]= this->data [i] - scalar ;
        }
        return mat3;
}

Matrix Matrix:: operator*(int scalar)
{
    int data[row * col];
    Matrix mat3(row , col , data);
    for (int i = 0; i < this->row * this->col ; i++)
        {
            mat3.data[i]= this->data [i] * scalar ;
        }
        return mat3;
}




Matrix& Matrix::operator+=(const Matrix& mat){

     if(row==mat.row && col==mat.col){
        for(int i=0 ; i<row*col ; i++){
            data[i]+=mat.data[i];
        }
    }
    else{
        cout<<"they can not add "<<endl;
    }
    return *this ;
}
Matrix& Matrix::operator-=(const Matrix& mat){

     if(row==mat.row && col==mat.col){
        for(int i=0 ; i<row*col ; i++){
            data[i]-=mat.data[i];
        }
    }
    else{
        cout<<"they can not subtract "<<endl;
    }
    return *this ;
}
Matrix Matrix::operator-=(int scaler){
for(int i=0;i<row*col;i++)
    data[i]-=scaler;
return Matrix(row,col,data);
}

Matrix Matrix::operator+=(int scaler){
for(int i=0;i<row*col;i++)
    data[i]+=scaler;
return Matrix(row,col,data);
}


void Matrix:: operator++ (){

for(int i=0 ; i<row*col ; i++){
    data[i]+=1;

}
}
void Matrix:: operator-- (){

for(int i=0 ; i<row*col ; i++){
    data[i]-=1;
}


}
istream& operator>> (istream& in, Matrix& mat) {
           cout<<"enter the row and col :";
           in>>mat.row >> mat.col ;
           mat.data = new int[mat.row*mat.col];
           cout<<"enter the matrix data :";
           for(int i=0 ; i<mat.row*mat.col ; i++){
                in>>mat.data[i];

           }

           return in;
       }


ostream& operator<< (ostream& out, Matrix& mat)   {
	           int c=0;
	           for(int i=0 ; i<mat.row*mat.col ; i++){
                if(c==mat.col){
                    cout<<endl;
                    c=0;
                }
                    out<<mat.data[i]<<" ";
                    c++;
	           }
	           return out;
}
