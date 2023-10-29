#ifndef LISTH 
#define LISTH
#include <stdlib.h>


typedef struct{
       size_t size;
       size_t capacity;
       char** base;
}
List;

List create_List();

void print_List(const List lst);

size_t sizeof_List(const List lst);

void append_List(List* lst, char* string);


#endif  
