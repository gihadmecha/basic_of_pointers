#include "stdio.h"




int matrix[2][5]={{1, 2, 3, 4, 5},
                  {6, 7, 8, 9, 10}};

int matrix3d[3][2][4]={{{1, 2, 3, 4},{5, 6, 7,8}},
                       {{9, 10, 11, 12},{13, 14, 15, 16}},
                       {{17, 18, 19, 20},{21, 22, 23, 24}}};


int display2darray(int array[][5], int rows){

for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            printf("matrix[%d][%d]   %d\n", i, j, array[i][j]);
        }
    }
}

int display3darray(int (*array3d)[2][4], int rows3d){

for (int i = 0; i < rows3d; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
           for (int k = 0; k < 4; ++k)
           {
               printf("matrix[%d][%d][%d]   %d\n", i, j, k, array3d[i][j][k]);
           }
        }
    }
}

int main()
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            printf("matrix[%d][%d]   %d   %d\n", i, j, &matrix[i][j], matrix[i][j]);
        }
    }

    printf("%d\n", matrix);
    printf("%d\n", matrix+1);

    printf("%d\n", sizeof(matrix[0]));

    printf("%d   %d\n", matrix[0], *(matrix[0]));
    printf("%d   %d\n", matrix[0]+1, *(matrix[0]+1));

    int (*pmatrix)[5] = matrix;
    printf("%d   %d\n", (*pmatrix),   (*pmatrix)[0]);
    printf("%d   %d\n", (*pmatrix)+1, (*pmatrix)[1]);
    printf("%d   %d\n", (*pmatrix)+7, (*pmatrix)[7]);


  
    display2darray(matrix, 2);

    display3darray(matrix3d, 3);



    return 0;
}