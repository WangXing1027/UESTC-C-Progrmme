#include <stdio.h>
int main()
{
	#define N 6
 
 	int a[N+2][N+2]={0};
 	int m = 1;
 	int i,j;
 	#define EAST =0
 	#define SOUTH = 1
 	#define WEST = 2
 	#define NORTH = 3
 	int dir = EAST;
 	
 	for(j = 0; j < N+2; ++j)
 		a[N+1][j] = a[0][j] = 1;
	
	for(i = 0; i < N+2; ++i)
		a[i][0] = a[i][N+1] = 1;
 	i = j = 1;
 	
 	
 	while(m < = N*N )
 	{
	 	if (a[i][j] == 0)
		{
		a[i][j] = m++;
		 switch(dir)
		 {
 			case EAST: ++j;break;
 			case SOUTH: ++j;break;
 			case WEST: --i;break;
 			case NORTH: --j;break;
		 }
		}
		 
		 else
		 {
		 switch(dir)
			{
 			case EAST: dir = SOUTH; --j; ++i;break;
 			case SOUTH: dir = WEST; --j; --i;break;
 			case WEST: dir = NORTH; ++j; --i;break;
 			case NORTH: dir = EAST; ++j; ++i;break;
		 	}
 		 }
	 }

	for(i = 0; i < N; ++i)
	{
	for(j = 0;j < N; ++j)
		printf("%4d", a[i][j]);
		putchar('\n');
	}

 		
	return 0;
}
