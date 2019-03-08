#include <stdio.h>

int main()
{
    int a[10], *p;

    printf("Enter 10 numbers:");
    for (p = a; p < 10+a; ++p) scanf("%d", p);

    printf("In reverse order:");
    for (p = 9+a; p >= a; --p) printf("%d", *p);
    printf("\n");

    return 0;
}