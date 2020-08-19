#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct _person
{
    char* firstname;
    char* lastname;
    char* title;
    unsigned int age;
}Person;

typedef struct _alternatePerson
{
  char* firstname;
  char* lastname;
  char* title;
  short age;  
}AlternatePerson;

Person person;
Person* ptrperson;

AlternatePerson alternatePerson;

void Person_initialization(Person* pointer, const char* fn, const char* ln, const char* tl, short ae){
    pointer->firstname = malloc(sizeof(strlen(fn)+1));
    strcpy(pointer->firstname, fn);
    pointer->lastname = malloc(sizeof(strlen(ln)+1));
    strcpy(pointer->lastname, ln);
    pointer->title = malloc(sizeof(strlen(tl)+1));
    strcpy(pointer->title, tl);
    pointer->age = ae;
}

void deallocate(Person* pointer){
    free(pointer->firstname);
    free(pointer->lastname);
    free(pointer->title);
}

int main()
{  // person.age = 23;
   // ptrperson->age = 23;
   // (*ptrperson).age =23;
   // ptrperson = malloc(sizeof(Person));
   // person.firstname = malloc(sizeof(strlen(fn)+1));
   // ptrperson->firstname = malloc(sizeof(strlen("gihad")+1));
   //(*ptrperson).firstname = malloc(sizeof(strlen("gihad")+1));

    ptrperson = malloc(sizeof(Person));
    Person_initialization(&person, "gihad", "mohamed", "Engineer", 25);


    printf("%s\n", person.firstname);
    printf("%s\n", person.lastname);
    printf("%s\n", person.title);
    printf("%d\n", person.age);

    deallocate(&person);
    free(ptrperson);
    

  // printf("%d\n", ptrperson);

  // strcpy(person.firstname, "gihad"); 
   /*printf("%d   %c\n", person.firstname, *person.firstname);
   printf("%d   %c\n", person.firstname+1, *(person.firstname+1));
   printf("%d   %c\n", person.firstname+2, *(person.firstname+2));
   printf("%d   %c\n", person.firstname+3, *(person.firstname+3));
   printf("%d   %c\n", person.firstname+4, *(person.firstname+4));
   printf("%d   %d\n", person.firstname+5, *(person.firstname+5));*/

  

   

  // printf("%d\n", sizeof(Person));
  // printf("%d\n", sizeof(AlternatePerson)); 

    return 0;
}
