#include<stdio.h>
int main()
{
    int a, b, i=1;
    printf("Enter number of days in month: ");
    scanf("%d",&a);

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d",&b);

    printf("\n");

    for(;i<b;++i)
    printf("   ");

    for(i=1;i<=a;i++)
    {
        if((i+b-1)%7 == 0 || i==a)
        printf("%2d",i);
        else
        printf("%2d ", i);
        if((i+b-1)%7 == 0 || i==a)
        printf("\n");
    }


    return 0;
}
