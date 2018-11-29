#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{

int data1[6] = {1,2,3,4,5,6};
int data2[4] = {0,0,0,0};

    Matrix mat1(2,3,data1);
    Matrix mat2(3,2,data1);
    Matrix mat3(3,2,data1);
    Matrix mat4;
    int x=5;
    --mat1;
    cout<<mat1;
    return 0;
}
