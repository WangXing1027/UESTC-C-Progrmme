#include <stdio.h>
int main()
{
	int m, n, d, r;
	printf("Enter two integers: ");
	scanf("%d%d", &m, &n);
	
	if(m < n)
	{
		d = m;
		m = n;
		n = d;
	}
	else
	m = m;
	n = n;
	
	do
	{
		r = n;
		n = m % n;
		m = r;
	}while(n == 0);
	
	printf("Greatest common divisor: %d\n",m);
	
	return 0;
}
