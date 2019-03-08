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

void inflate(circle* c, double scale)
{
    c->r *= scale;
}

void move (circle* c, double dx, double dy)
{
    c->x += dx;
    c->y += dy;
}

union X
{
    int i;
    char c;
    double d;
};

int main()
{
    union X u;

    u.i = 65;
    printf("%c, %lf\n",u.c ,u.d);
    return 0;
}

