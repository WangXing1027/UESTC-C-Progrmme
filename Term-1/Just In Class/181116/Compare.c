#include<stdio.h>
int check(int a, int b, int c)
{
    int t;

    if(a >= 0&& a < c && b >= 0&&b < c)
        t = 1;
    else t = 0;
    return t;

}

int main()
{
    int x, y, n;
    scanf("%d %d %d",&x, &y, &n);
    printf("%d",check(x, y, n));

    return 0;
}
