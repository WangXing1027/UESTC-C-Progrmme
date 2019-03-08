#include<stdio.h>

int main()
{
    int a, b, c, d ,e;
    printf("Enter a dollar amount: ");
    scanf("%d",&a);

    b = a / 20 ;
    c = (a - b * 20) / 10 ;
    d = (a - b * 20 - c * 10) / 5;
    e = a - b * 20 - c * 10 - d * 5;
    printf("$20 bills: %d\n",b);
    printf("$10 bills: %d\n",c);
    printf("$5 bills: %d\n",d);
    printf("$1 bills: %d\n",e);

    return 0;
}
