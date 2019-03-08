#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int value_type;

typedef struct _node
{
	value_type data;
	struct _node *next;	
} node;

typedef node* nodeptr;

typedef struct
{
	node head;  //head node
	nodeptr tail;  //tail pointer
	size_t size;
} list, *listptr;

typedef void CALLBACK(value_type*); //CALLBACK is a function type
//typedef void (*CALLBACK)(value_type*); //CALLBACK is a function pointer type 

extern listptr list_init(listptr);
extern listptr list_create();
extern listptr list_create_from_file(const char*);
extern listptr list_push_front(listptr, value_type);
extern listptr list_push_back(listptr, value_type);
extern listptr list_clear(listptr);
extern value_type list_top(listptr);
extern void list_pop(listptr);
extern bool list_empty(listptr);
extern void list_traverse(listptr, CALLBACK);
extern void list_save_to_file(listptr, const char*);
