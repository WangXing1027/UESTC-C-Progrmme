#include<stdio.h>
int main()
{
    int m, n, i, a;

    printf("Enter two integers: ");
    scanf("%d%d", &m, &n);


    if(m < n)
        {
        a = n;
        n = m;
        m = a;
        }

    while( i != 0)
    {
        i = m%n;
        m = n;
        n = i;
    }

    printf("Greatest common divisor: %d", m);


    return 0;
}
