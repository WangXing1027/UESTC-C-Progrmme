#define _CRT_SECURE_NO_WARNINGS

#include "list.h"

listptr list_init(listptr l)
{
	l->head.next = l->tail = NULL;
	l->size = 0;
	return l;
}

listptr list_create()
{
	listptr l = (listptr)malloc(sizeof(list));
	list_init(l);
	return l;
}

bool list_empty(listptr l)
{
	return l->size == 0;
}

listptr list_push_front(listptr l, value_type v)
{
	nodeptr p = (nodeptr)malloc(sizeof(node));
	p->data = v;
	p->next = l->head.next;	
	l->head.next = p;
	++l->size;
	return l;
}

listptr list_push_back(listptr l, value_type v)
{
	nodeptr p = (nodeptr)malloc(sizeof(node));
	p->data = v;
	p->next = NULL;

	if (!l->tail) //the node to be pushed will be the first one
		l->tail = l->head.next = p;
	else
	{
		l->tail->next = p;
		l->tail = p;
	}
	++l->size;
	return l;
}

listptr list_clear(listptr l)
{
	nodeptr p = l->head.next, q;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	l->head.next = NULL;
	return l;
}

listptr list_create_from_file(const char* datafile)
{
	FILE* fp;
	value_type v;
	listptr l;

	l = (listptr)malloc(sizeof(list));
	list_init(l);

	fp = fopen(datafile, "rt");
	if (!fp)
	{
		printf("Cannot open file data.txt\n");
		exit(EXIT_FAILURE);
	}

	while (!feof(fp))
	{
		fscanf(fp, "%d", &v);
		list_push_back(l, v);
	}
	fclose(fp);

	return l;
}

void list_traverse(listptr l, CALLBACK f)
{
	nodeptr p = l->head.next;
	while (p != NULL)
	{
		f(&p->data);
		p = p->next;
	}
}

value_type list_top(listptr l)
{
	if (list_empty(l)) exit(EXIT_FAILURE);

	return l->head.next->data;
}

void list_pop(listptr l)
{
	if (list_empty(l)) exit(EXIT_FAILURE);

	nodeptr p = l->head.next;
	l->head.next = p->next;
	free(p);
	--l->size;
	if (list_empty(l)) l->tail = NULL;
}

void list_save_to_file(listptr l, const char* filename)
{
	FILE* fp;
	char sure;
	nodeptr p;

	printf("File %s will be overwriten. Are you sure?(y/n):", filename);
	sure = getchar();
	if (sure == 'n' || sure == 'N') return;

	fp = fopen(filename, "wt");
	if (!fp)
	{
		printf("Cannot open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	p = l->head.next;
	while (p != NULL)
	{
		fprintf(fp, "%d", p->data);
		p = p->next;
		if (p != NULL) fprintf(fp, "\n"); //if is not last data, put a newline
	}
	fclose(fp);
}
