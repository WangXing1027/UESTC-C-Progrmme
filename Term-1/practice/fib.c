//fib(n) = O(n)
#include<stdio.h>

void fib(int x)
{
    int f = 0,g = 1;
    for(int i = 1;i <= x; ++i)
    {
        g = g + f;
        f = g - f;
        printf("fib(%d) = %d\n",i, g);
    }
}

int main()
{
    int x;
    scanf("%d",&x);
    fib(x);
    return 0;
}