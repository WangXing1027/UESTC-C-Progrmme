#include <stdio.h>
int main()
{
	int s;
	scanf("%d",&s);
	
	switch(s / 10)
	{
		case 10:
		case 9: printf("Outstandig");break;
		case 8: printf("Excellent");break;
		case 7: printf("Acceptable");break;
		case 6: printf("Poor");break;
		default:printf("Bad");
		
	}
	return 0;
}
