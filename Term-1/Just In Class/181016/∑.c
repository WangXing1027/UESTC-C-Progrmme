#include <stdio.h>
int main()
{
	int i = 1, sum = 0;
	for(;i <= 100;)
	{
		sum +=i++;
		if(i > 100)
		break;
	}
	
		printf("%d\n%d\n",sum,i);
	
	return 0;
}
