#include <stdio.h>
int main()
{
	int a=1, b=1, c, sum, i;
	const int n = 100;
	i = 3;
	
	do{
		c = a + b;
		b = a;
		a = c;
		printf("Xn%d = %d\n",i,b);
		++i;
		
	}while(i<=n);
	
	return 0;
}
