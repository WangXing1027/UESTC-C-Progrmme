#include<stdio.h>

void draw_triangle(int a)
{
    int i,j;
    for(i = 1;i <= a;++i)
    {
        for(j = 1; j <= a-i; ++j)
            printf(" ");
        for(j = 1; j <= i; ++j)
            printf("*");
        putchar('\n');
    }
}

int main()
{
    draw_triangle(5);
    return 0;
}
