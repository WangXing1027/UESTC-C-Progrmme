#include <stdio.h>

const double PI = 3.1415926;

struct date
{
	int year,month,day;
};

struct student
{
	unsigned id;
	char name[64];
	struct date dob;
	char gender; 
}stu = {1,"David",{2000,1,1},'M'};

typedef struct date  DATE;
int main()
{
	DATE d;

	printf("%u\n",stu.dob.year);
	
	return 0;
}
