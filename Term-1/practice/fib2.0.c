#include<stdio.h>

int main()
{
    long int i;
    long int f,g,h,s;
    g = 0;f = 1;h = 1;
    scanf("%ld",&i);
    
    for(long int j = 0; j < i; ++j)
    {
        s = g + f + h;
        g = f;
        f = h;
        h = s;
    }

    printf("%ld", f);
    return 0;
}