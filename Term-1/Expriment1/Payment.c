#include<stdio.h>

int main()
{
    float a, b, c;
    printf("Enter amount of loan: ");
    scanf("%f",&a);
    printf("Enter interest rate: ");
    scanf("%f",&b);
    printf("Enter monthly payment: ");
    scanf("%f",&c);

    float d, e, f, g;

    d = 1 + b / 12 / 100;
    e = a * d - c;
    f = e * d - c;
    g = f * d - c;
    printf("\nBalance remaining after first payment: $%.2f\n",e);
    printf("Balance remaining after second payment: $%.2f\n",f);
    printf("Balance remaining after third payment: $%.2f\n",g);

    return 0;
}
