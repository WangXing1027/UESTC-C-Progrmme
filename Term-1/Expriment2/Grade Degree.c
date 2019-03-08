#include <stdio.h>
int main()
{
	int a;
	printf("Enter numerical grade: ");
	scanf("%d",&a);

	if (a <= 100 && a >= 0)
	{
		switch(a / 10)
		{
			case 10:
			case 9: printf("Letter Grade: A\n");break;
			case 8: printf("Letter Grade: B\n");break;
			case 7: printf("Letter Grade: C\n");break;
			case 6: printf("Letter Grade: D\n");break;
			default: printf("Letter Grade: F\n");
		}
	}

	else printf("Error, grade must be between 0 and 100.\n");

	return 0;
}
