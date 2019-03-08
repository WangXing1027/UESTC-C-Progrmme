#include<stdio.h>
#define MAX 80
float evaluation(float c,char a,float b)
{
    switch(a)
    {
    case '+':return c + b;break;
    case '-':return c - b;break;
    case '*':return c * b;break;
    case '/':return c / b;
    }

}

int main()
{
    float n;
    char c;

    printf("Enter an expression: ");
    scanf("%f", &n);

    while((c = getchar()) != '\n')
    {
        float a;
        scanf("%f", &a);
        n = evaluation(n, c, a);
    }

    int x = (int)n;

    if(n - x == 0.0)
        printf("Value of expression: %d\n",x);
    else
        printf("Value of expression: %.1f\n",n);
    return 0;


}
