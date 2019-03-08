#include <stdio.h>

#define ROW 4
#define COL 7

typedef int (*AP)[COL];

void println(AP q, size_t len)
{
    for (size_t i = 0; i < len; ++i) printf("%4d", (*q)[i]);
    putchar('\n');
}

int main()
{
    int x[ROW][COL];
    size_t i;
    int *p;

    for (p = &x[0][0], i = 0; i < ROW * COL; ++p) *p = i++;

    for (i = 0; i < ROW; ++i) println(x + i, COL);

    return 0;
}
