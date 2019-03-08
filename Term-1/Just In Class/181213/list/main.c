#include <stdio.h>

#include "list.h"

#define NEWLINE putchar('\n')

void print(value_type* v)
{
	printf("%5d", *v);
}

void dbl(value_type* v)
{
	*v *= 2;
}

int main()
{
	listptr l;
	value_type v;
	int i;

	l = list_create_from_file("data.txt");
	list_traverse(l, print);
	NEWLINE;

	list_traverse(l, dbl);
	list_traverse(l, print);
	NEWLINE;

	list_push_front(l, 111);
	list_push_front(l, 222);
	list_traverse(l, print);
	NEWLINE;

	v = list_top(l);
	printf("top: %d\n", v);
	
	for (i = 0; i < 4; ++i) list_pop(l);
	list_traverse(l, print);
	NEWLINE;

	list_save_to_file(l, "data.txt");

	list_clear(l);
	
	return 0;
}
