#include<stdio.h>

int day_of_year(int a, int b, int c)
{
    int t;
    int i;
    int MONTH[11]={31,28,31,30,31,30,31,31,30,31,30};

    if(c % 4 == 0)
        MONTH[1]=29;
    for(i = 0;i < a - 1; ++i)
        t+=MONTH[i];

    t+= b;

    return t;
}
int main()
{
    int month, day, year;
    int t;
    scanf("%d%d%d", &month, &day, &year);
    t = day_of_year(month, day, year);

    printf("%d of %d", t, year);

    return 0;
}
