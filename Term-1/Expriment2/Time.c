#include <stdio.h>
int main()
{
	int a,b,c;

	printf("Enter a 24-hour time: ");
	scanf("%d:%2d",&a,&b);

	c = a - 12;

	if(a<12)
	printf("Equivalent 12-hour time: %d:%2.2d AM\n",a,b);

	else if( a == 24 )
    printf("Equivalent 12-hour time: 00:%2.2d AM\n",b);

	else
	printf("Equivalent 12-hour time: %d:%2.2d PM\n",c,b);

	return 0;
}
