#include <stdio.h>
int main()
{
	int i = 1,a = 3;
	double sum = 0;
	const int n = 9;//const int :���� 
	do{//do while ��䣺ѭ�� 
		sum+= (1.0 / a); //sum+����sum = sum+����˼����1.0��������1��1Ϊ��������1.0Ϊ������ 
		a = 10 * a + 3;
		++i;
	}while(i <= n);
	
	printf("%lf\n",sum);
	
	return 0;
}
