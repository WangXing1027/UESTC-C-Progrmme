#include<stdio.h>

int main()
{
    int a[10] = {0};
    int i;
    long int s;

    printf("Enter a number: ");
    scanf("%ld",&s);

    if(s == 0)
        ++a[0];
    while(s > 0)
    {
        i = s%10;
        a[i]++;
        s /= 10;
    }

    printf("Digit:\t\t");

    for(i = 0;i < 10;++i)
    {
        if(i == 0)
            printf("%d",i);
        else
            printf(" %2d",i);
    }


    printf("\nOccurrences:\t");

    for(i = 0;i < 10;++i)
    {
        if(i == 0)
            printf("%d",a[i]);
        else
            printf(" %2d",a[i]);
    }

    printf("\n");

    return 0;
}
