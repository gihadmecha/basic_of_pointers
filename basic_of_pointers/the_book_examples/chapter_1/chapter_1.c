#include <stdio.h>

int num_1 = 4;
int* num_1_address = &num_1;

int num_2;
int* num_2_address = &num_2;

int num_3;
int* num_3_address = &num_3;

int* globalpi;

int vector[] = {7, 11, 21};
int* pointer_to_array = vector;

short s;
short* ps = &s;
char c;
char* pc = &c;

int voidnum = 5;
void* voidnum_pointer = &voidnum;

char* titles[] = {"prison break", "love, rose", "joy", "500 day of summer"};
char** highrate[] = {titles, titles+1};
char** lowrate[] = {titles+2, titles+3};

int justintegar = 5;
const int constantintegar = 2;

int* justintegar_pointer = &justintegar;
const int* constantintegar_pointer = &constantintegar;

int* const constantpointer = &justintegar_pointer;

const int* const constant_to_constant = &constantintegar;

const int* const* pointer = &constant_to_constant; 

void foo() {
 static int* staticpi;
 printf("the address is %d \n", globalpi);
 printf("the address is %d \n", staticpi);
}

int main()
{   
    //printf("the address is %d and the value is %d \n", num_1_address, *num_1_address);
    //num_1_address = (int*)num_1;

    printf("the address is %d and the value is %d \n", num_1_address, *num_1_address);
    printf("the address is %x and the value is %x \n", num_1_address, *num_1_address);
    printf("the address is %o and the value is %o \n", num_1_address, *num_1_address);
    printf("the address is %p and the value is %p \n", num_1_address, *num_1_address);
    printf("Value of num_1_address: %p\n", (void*)num_1_address);
    
    printf("the address is %d and the value is %d \n", num_2_address, *num_2_address);
    printf("the address is %d and the value is %d \n", num_3_address, *num_3_address);
    printf("the address size is %d and the int size is %d \n", sizeof(num_1_address), sizeof(num_1));

    void* num_5_address = num_1_address;
    printf("the address is %d \n", num_5_address);

    num_1_address = (int*)num_5_address;
    printf("the address is %d \n", num_1_address);
    
    size_t pointer_size = sizeof(void*);
    size_t void_size = sizeof(void);
    printf("void* size is %d \n", pointer_size);
    printf("void size is %d \n", void_size);
    
    foo();

    printf("the address is %d and the value is %d \n", pointer_to_array, *pointer_to_array);
    printf("the address is %d and the value is %d \n", pointer_to_array + 1, *(pointer_to_array + 1));
    printf("the address is %d and the value is %d \n", pointer_to_array + 2, *(pointer_to_array + 2));
    printf("the address is %d and the value is %d \n", pointer_to_array + 3, *(pointer_to_array + 3));

    printf("Content of ps before: %d\n",ps);
    ps = ps + 1;
    printf("Content of ps after: %d\n",ps);
    printf("Content of pc before: %d\n",pc);
    pc = pc + 1;
    printf("Content of pc after: %d\n",pc);

    printf("%p\n", voidnum_pointer);
    printf("%p\n", voidnum_pointer+1);

    pointer_to_array += 2;

    printf("%d\n", *(pointer_to_array));
    printf("%d\n", *(pointer_to_array-1));
    printf("%d\n", *(pointer_to_array-2));

    printf("%d\n", pointer_to_array - (pointer_to_array-1));
    printf("%d\n", (pointer_to_array-1) - (pointer_to_array-2));
    printf("%d\n", (pointer_to_array-2) - (pointer_to_array));

    printf("%d\n", *pointer_to_array - *(pointer_to_array-1));
    printf("%d\n", *(pointer_to_array-1) - *(pointer_to_array-2));
    printf("%d\n", *(pointer_to_array-2) - *(pointer_to_array));

    printf("%d\n", pointer_to_array > (pointer_to_array-1));
    printf("%d\n", (pointer_to_array-1) > (pointer_to_array-2));
    printf("%d\n", (pointer_to_array-2) > (pointer_to_array));

    printf("%s\n", *titles);
    printf("%s\n", *(titles+1));
    printf("%s\n", *(titles+2));
    printf("%s\n", *(titles+3));

    printf("%s\n", **highrate);
    printf("%s\n", **(highrate+1));

    printf("%s\n", **lowrate);
    printf("%s\n", **(lowrate+1));
    
    *justintegar_pointer = 10;
    printf("%d\n", *justintegar_pointer);
    constantintegar_pointer = &justintegar;
    printf("%d\n", *constantintegar_pointer);

    *constantpointer = 40;
    printf("%d\n", *constantpointer);

    printf("%d\n", pointer);
    printf("%d\n", *pointer);
    printf("%d\n", **pointer);



    return 0;
}