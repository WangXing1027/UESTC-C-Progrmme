#include <stdio.h>
int main()
{
	int i,j;
	
	for(i = 1; i<= 9; ++i)
	{	for(j = 1; j<= 9 && j <= 10-i; ++j)
			printf("%4d",i*j);//1*1,2,3,...9内循环执行完后跳到外循环 
			putchar('\n');//putchar:输出 getchar：输入。语句内都用'' 

	} //花括号：每执行到i*9后换行		
	return 0;
} 
