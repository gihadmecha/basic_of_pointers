#include <stdio.h>
#include <stdlib.h>


int n1 = 5;
int n2 = 10;

const int num1 = 4;
int num2 = 2;

int value = 5;
int* pointer = &value;
int** pointer_pointer = &pointer;

typedef int (*funcptr)(int);
funcptr fptr;

typedef int (*funcptroperation)(int, int);
funcptroperation operation;

void swapwithvalue(int number1, int number2){
    int temp = 0;
    temp = number1;
    number1 = number2;
    number2 = temp;
}

void swapwithpointer(int* pn1, int* pn2){
    int temp = 0;
    temp = *pn1;
    *pn1 = *pn2;
    *pn2 = temp;
}

void PassConstantPointerToFunction(const int* PointerToConstantIntegar, int* PointerToIntegar){
    printf("PointerToIntegar:%d\n", *PointerToIntegar);
    *PointerToIntegar = *PointerToConstantIntegar;
    printf("PointerToIntegar:%d\n", *PointerToIntegar);
}

int* ReturnPointer(int size, int value){
    int* memory = malloc(size*sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        *(memory+i) = value;
    }

    return memory;
}

int* ReturnPointerFromArray(int size, int value){
    static int array[3];
    for (int i = 0; i < size; ++i)
    {
        *(array+i) = value;
    }

    return array;
}

int* checkNULL(int* array, int size, int value){
    if (array != NULL)
    {
        for (int i = 0; i < size; ++i)
        {
            *(array+i) = value;
        }
    }

    return array;
}

void PassingPointerToPointer(int** arr, int size, int value){
    *arr = malloc(size * sizeof(int));
    if (*arr != NULL)
    {
        for (int i = 0; i < size; ++i)
        {
        *(*arr+i) = value;
        }

    }
}

void PassingPointer(int* arr, int size, int value){
    arr = malloc(size * sizeof(int));
    if (arr != NULL)
    {
        for (int i = 0; i < size; ++i)
        {
        *(arr+i) = value;
        }
    }
}

int square(int num){
    return num*num;
}

int add(int num1, int num2){
    return num1+num2;
}

int subtract(int num1, int num2){
    return num1-num2;
}

int compute(funcptroperation operation, int num1, int num2){
return operation(num1, num2);
}

funcptroperation selecter(char opcode){
    switch(opcode){
    case '+': return add;
    case '-': return subtract;
    }
}

int evalute(char opcode, int num1, int num2){
    funcptroperation operation = selecter(opcode);
    return operation(num1, num2);
}

int main()
{
    swapwithvalue(n1, n2);
    printf("n1: %d   n2: %d\n", n1, n2);
    swapwithpointer(&n1, &n2);
    printf("n1: %d   n2: %d\n", n1, n2);
    PassConstantPointerToFunction(&num1, &num2);
    int* vector = ReturnPointer(5, 45);
    for (int i = 0; i < 5; ++i)
    {
        printf("%d   %d\n", vector+i, *(vector+i));
    }
    free(vector);
    vector = NULL;
    printf("\n");
    int* array_vector = ReturnPointerFromArray(3, 100);
    for (int i = 0; i < 3; ++i)
    {
        printf("%d   %d   \n", array_vector+i, *(array_vector+i));
    }
    printf("\n");

    int* allocate_for_checkNULL = malloc(5*sizeof(int));
    int* vector_checknull = checkNULL(allocate_for_checkNULL, 5, 20);
    for (int i = 0; i < 5; ++i)
    {
        printf("%d   %d\n", vector_checknull+i, *(vector_checknull+i));
    }
    free(allocate_for_checkNULL);
    allocate_for_checkNULL = NULL;

    printf("\n");
    printf("%d         %d\n", value, &value);
    printf("%d   %d   %d\n", pointer, &pointer, *pointer);
    printf("%d   %d   %d   %d\n", pointer_pointer, &pointer_pointer, *pointer_pointer, **pointer_pointer);
    printf("\n");
    
    int* middle_pointer = NULL;
    PassingPointerToPointer(&middle_pointer, 3, 3);
    printf("%d\n", middle_pointer);
    printf("%d\n", *middle_pointer);
    printf("\n");

    int* the_pointer = NULL;
    PassingPointer(the_pointer, 3, 3);
    printf("%d\n", the_pointer);
    printf("\n");

    fptr = square;
    int n = 5;
    printf("%d\n", fptr(5));
    printf("\n");

    printf("%d\n", compute(add, 5, 6));
    printf("%d\n", compute(subtract, 5, 6));

    printf("\n");
    printf("%d\n", evalute('+', 1, 2));
    printf("%d\n", evalute('-', 1, 2));

    printf("\n");
    funcptroperation operation = add;
    if(operation == add) {
     printf("fptr1 points to add function\n");
    } else {
     printf("fptr1 does not point to add function\n");
    }
    printf("\n");

    return 0;
}