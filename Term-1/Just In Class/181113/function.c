#include <stdio.h>

int max(int a, int b, int c)
{
	int t = a > b ? a : b;
	t = t > c ? t : c;
	
	return t;
}
int main()
{
	int a = 1, b = 3, c = 2;
	int x = 90, y = 80, z = 101;
	int t;
	
	
	t = max(a, b, c);
	t = max(x, y, z);
	
	printf("The max is: %d  \n",t);
	return 0;
}
