#include<stdio.h>
int main()
{
    int s = 0;
    int i = 1;

    while(i <= 100 )
        s += i++;

    printf("%d",s);

    return 0;
}
