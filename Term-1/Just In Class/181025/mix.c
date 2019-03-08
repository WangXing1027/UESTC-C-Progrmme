#include <stdio.h>

#define LEN 10

int main()
{
	int a[LEN] = {
		9, 3, 2, 10, 5, 8, 6, 4, 0, 1
	};
	int i, max = a[0], number;
	
	
	for(i = LEN - 1; i >= 0; --i)
		if(max > a[i])
		   {number = i;
		   	max = a[i];}
		
	printf("The max is: %d @%d\n",max,number+1);	
	
	return 0;
}
