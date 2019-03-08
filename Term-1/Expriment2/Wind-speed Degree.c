#include <stdio.h>
int main()
{
	float a;
	printf("Enter a wind speed: ");
	scanf("%f",&a);
	
	if(a < 1.0)
	printf("Calm\n");
	
	else if(a <= 3.0)
	printf("Light air\n");
	
	else if(a <= 27.0)
	printf("Breeze\n");	
	
	else if(a <= 47.0)
	printf("Gale\n");	
	
	else if(a <= 63.0)
	printf("Storm\n");
	
	else 
	printf("Hurricane\n");
	
	return 0;
}
