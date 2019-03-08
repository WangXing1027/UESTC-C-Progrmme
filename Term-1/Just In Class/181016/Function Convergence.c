#include <stdio.h>
int main()
{
	int i = 1,a = 3;
	double sum = 0;
	const int n = 9;//const int :常量 
	do{//do while 语句：循环 
		sum+= (1.0 / a); //sum+就是sum = sum+的意思，用1.0而不能用1：1为整数，而1.0为浮点数 
		a = 10 * a + 3;
		++i;
	}while(i <= n);
	
	printf("%lf\n",sum);
	
	return 0;
}
