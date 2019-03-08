#include<stdio.h>
int main()
{
    double pi = 0.0;
    float i = 1.0;
    int sign = 1;
    while((1/i) >= 1e-7)
    {
        pi += sign * 1.0/i;
        i += 2;
        sign = -sign;
    }
    printf("%.8f",4*pi);

    return 0;
}
