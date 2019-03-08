//root.c

#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    double d, x1, x2;

    printf("Please input a, b, c:");
    scanf("%f%f%f", &a, &b, &c);

    d = b * b - 4 * a * c;
    x1 = (-b + sqrt(d)) / 2 / a;
    x2 = (-b - sqrt(d)) / 2 / a;

    printf("The roots are: %.3lf, %.3lf\n", x1, x2);
    return 0;
}
