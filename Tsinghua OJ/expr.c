#include<stdio.h>
int main()
{
    double  x,y;
    char ch;
    scanf("%lf %c %lf",&x,&ch,&y);
    switch (ch)
    {
        case '+':printf("%g",x+y);
            break;
        case '-':printf("%g",x-y);
            break;
        case '*':printf("%g",x*y);
            break;
        default:
            break;
    }
    return 0;

}