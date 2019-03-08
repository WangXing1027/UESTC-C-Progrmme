#include <stdio.h>
int main()
{
    float a,b,c,d,e,f,g;
    printf("Enter amount of loan: ");
    scanf("%f",&A);
    printf("Enter interest rate: ");
    scanf("%f",&b);
    printf("Enter monthly payment: ");
    scanf("%f",&c);
    printf("\n");
	d=1+b/1200;
	e=A*d-c;
    f=e*d-c;
    g=f*d-c;
	printf("Balance remaining after first payment: $%.2f\n",e);
    printf("Balance remaining after second payment: $%.2f\n",f);
    printf("Balance remaining after third payment: $%.2f\n",g);
	return 0;
}

