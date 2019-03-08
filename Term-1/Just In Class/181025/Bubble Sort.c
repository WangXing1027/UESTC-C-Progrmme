#include <stdio.h>

#define LEN 10

int main()
{
	int a[LEN] = {9, 3, 2, 10, 5, 8, 6, 4, 0, 1};
	int i, j;

	for(i = 0; i < LEN - 1; ++i)
 		for(j = i; j > LEN - i; --j)
 			if(a[i]<a[j])
 			{
 				int t;
			 	t = a[i];
				a[i] = a[j];
				a[j] = t;
		 	}

	for(i = 0; i < LEN; ++i)
	printf("%4d", i);
	return 0;
}
