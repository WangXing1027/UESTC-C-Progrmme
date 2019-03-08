#include<stdio.h>

struct _circle
{
    double x,y;
    double r;
};

typedef struct _circle  circle;

double area(circle c)
{
    return c.r * c.r *3.1415;
}

circle make_a_circle(double x, double y, double r)
{
    circle c;
    c.x = x;
    c.y = y;
    c.r = r;
    return c;
}

int main()
{
    circle c;
    c = make_a_circle(0,0,7);
    printf("%.1f\n",area(c));
    return 0;
}
