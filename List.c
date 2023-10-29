#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "List.h"

static void resize(List* lst) { 
	lst->capacity *= 2;	
	lst->base = realloc(lst->base, sizeof(char*) * lst->capacity);	
	assert(lst->base != NULL);	
}

List create_List() {
	List new;
	new.size = 0;
	new.capacity = 5;
	// start with 5 elems as base
	new.base = malloc(sizeof(char*) * new.capacity);
	assert(new.base != NULL);
	return new;
}

void print_List(const List lst) {
	if (lst.size == 0) {
		printf("empty list\n");
	}
	for(int i = 0; i < lst.size; i++) {
		printf("%s ", lst.base[i]); }
	printf("\n");
}

size_t sizeof_List(const List lst) {
	return lst.size;	
}

void append_List(List* lst, char* string) {
	if (lst->size == lst->capacity) {
		resize(lst);		
	}
	lst->base[lst->size++] = strdup(string);
}

char* get_random_List(const List lst) {
	srand(time(NULL));
	int random_index  = rand() % lst.size;
	return lst.base[random_index];
		
}

void destory_List(List* lst) {
	free(lst->base);
	lst->size = lst->capacity = 0;
}

