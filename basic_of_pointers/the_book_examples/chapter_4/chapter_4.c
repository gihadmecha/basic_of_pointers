#include "stdio.h"
#include <stdlib.h>

int vector[5] = {1, 1, 1, 1, 1};
int* pv = vector;
int matrix[2][3] = {{1, 2, 3},
                    {4, 5, 6}};

int arr3d[3][2][4] = {{{ 1,  2,  3,  4},{ 5,  6,  7,  8}},
                      {{ 9, 10, 11, 12},{13, 14, 15, 16}},
                      {{17, 18, 19, 20},{21, 23, 24, 25}}};


void displayarray(int* arr,int size){
    for (int i = 0; i < 5; ++i)
    {
        printf("%d\n", *(arr+i));
    }
}
void display2darray(int array[][3]){
    for (int i = 0; i < 2; ++i)
    {
      for (int j = 0; j < 3; ++j)
        {
           printf("array[%d][%d]   address:%d   value:%d\n", i, j, &array[i][j], array[i][j]);
        }  
    }
}
void display2darray_with_pointer(int* array, int row, int column){
    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < column; ++j)
        {
           printf("%d  ", array+i*column+j);
           printf("%d ", (array+i)[j]);
           printf("%d\n ", &(array+i)[j]);
        }  
    }
}

int main()
{
    printf("%d\n", sizeof(vector));
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(vector)/sizeof(int));
    for (int i = 0; i < 5; ++i)
    {
        printf("%d\n", (vector+i));
    }
    for (int i = 0; i < 5; ++i)
    {
        printf("%d\n", &(*(vector+i)));
    }
    displayarray(vector,5);
    int value = 3;
    for(int i=0; i<5; i++) {
        *(pv+i) *= value;
        printf("%d\n", *pv);
    }
    for (int i = 0; i < 2; ++i)
    {
        printf("%d\n", **(matrix+i));
    }

    int* malloc_array = malloc(5*sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        *(pv+i) = i+1;
        printf("%d\n", *(pv+i));
        printf("%d\n", pv+i);
    }
    printf("%d\n", pv);
    free(malloc_array);
    malloc_array = NULL;

    int* for_each_element[5];
    for(int i = 0; i < 5; i++){
    *(for_each_element+i) = (int*)malloc(sizeof(int));
    **(for_each_element+i) = i+1;
    printf("%d\n", **(for_each_element+i));
    free(*(for_each_element+i));
    *(for_each_element+i) = NULL; 
    }

    for (int i = 0; i < 2; ++i)
    {
      for (int j = 0; j < 3; ++j)
        {
           printf("matrix[%d][%d]   address:%d   value:%d\n", i, j, &matrix[i][j], matrix[i][j]);
        }  
    }
    int (*matrix_pointer)[3] = matrix;
    printf("\n%d\n", (*matrix_pointer));
    printf("%d\n\n", *(*matrix_pointer));
    

    printf("%d\n", matrix_pointer);
    printf("%d\n", *matrix_pointer);
    printf("%d\n\n", **matrix_pointer);


    printf("%d\n", *(matrix_pointer)+1);
    printf("%d\n", *(*(matrix_pointer)+1));
    printf("%d\n\n", **(matrix_pointer)+1);

    printf("%d\n\n", sizeof(matrix[0]));

    printf("%d\n", matrix[0]);
    printf("%d\n", *matrix[0]);
    printf("%d\n", matrix[0]+1);
    printf("%d\n\n", *(matrix[0]+1));


    printf("%d\n", matrix_pointer+1);
    printf("%d\n", *(matrix_pointer+1));
    printf("%d\n", *(*(matrix_pointer+1)));
    printf("%d\n\n", **(matrix_pointer+1));

    display2darray(matrix);

    display2darray_with_pointer(matrix, 2, 3);

    return 0;
}