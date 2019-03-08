#include <stdio.h>

int main()
{
    int a[5] = {0}, b[5] = {0};
    int i;

    for (i = 0; i < 20; ++i) b[i] = i;

    for (i = 0; i < 5; ++i) printf("%4d", b[i]); 
    putchar('\n');
    for (i = 0; i < 5; ++i) printf("%4d", a[i]); 
    putchar('\n');

    return 0;
}