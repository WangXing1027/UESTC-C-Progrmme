#include <stdio.h>
int main()
{
	int i,j;
	
	for(i = 1; i<= 9; ++i)
	{	for(j = 1; j<= 9 && j <= 10-i; ++j)
			printf("%4d",i*j);//1*1,2,3,...9��ѭ��ִ�����������ѭ�� 
			putchar('\n');//putchar:��� getchar�����롣����ڶ���'' 

	} //�����ţ�ÿִ�е�i*9����		
	return 0;
} 
