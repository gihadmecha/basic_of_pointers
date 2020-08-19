#include "stdio.h"
#include <stdlib.h>
#include <string.h>

 


int main()
{
    int* address_for_four_allocated_bytes = malloc(sizeof(int));
    if (address_for_four_allocated_bytes != NULL)
    {
        *address_for_four_allocated_bytes = 5;
        printf("%d\n", *address_for_four_allocated_bytes);
        memset(address_for_four_allocated_bytes, 0, sizeof(int));
        printf("%d\n", *address_for_four_allocated_bytes);
    }
    else{
        printf("it's NULL\n");
    }
    free(address_for_four_allocated_bytes);

    char* address_for_five_chars = (char*)malloc(6*sizeof(char));
    for (int i = 0; i < 8; ++i)
    {
        *(address_for_five_chars + i) = i;
    }
    for (int i = 0; i < 8; ++i)
    {
        printf("%d\n", *(address_for_five_chars + i));
    }
    free(address_for_five_chars);

    char* address_for_string = (char*)malloc(strlen("sawsan")+1);
    printf("%d\n", address_for_string);
    strcpy(address_for_string, "sawsan");
    while(*address_for_string != 0)
    {
        printf("%c", *address_for_string);
        address_for_string++;
    }
    printf("\n");
    printf("%d\n", address_for_string);
    for (int i = 0; i < strlen("sawsan"); ++i)
    {
        address_for_string--;
    }
    printf("%d\n", address_for_string);
    free(address_for_string);
    printf("\n");
    int* tring_NULL = malloc(NULL);
    printf("%d\n", tring_NULL);
    free(tring_NULL);
    int* declare_without_defination;
    printf("%d\n", *declare_without_defination);

    char* name;
    printf("enter name:" );
    scanf("%s",name);
    static int *pi;
    pi = malloc(sizeof(int));
    printf("%d\n", pi);
    free(pi);

    int* calloc_example = calloc(5, sizeof(int));
    printf("%d\n", calloc_example);
    printf("%d\n", *(calloc_example+1));
    printf("%d\n", *(calloc_example+2));
    printf("%d\n", *(calloc_example+3));
    printf("%d\n", *(calloc_example+4));
    free(calloc_example);


    return 0;
}