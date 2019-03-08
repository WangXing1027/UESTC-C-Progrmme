#include<stdio.h>
int main()
{
    float num1, num2;
    char b;


    printf("Enter the expression: ");
    scanf("%f %c %f",&num1,&b,&num2);
    printf("The result is: ");
    switch(b)
    {
        case '+' :printf("%.1f", num1+num2);break;
        case '-' :printf("%.1f", num1-num2);break;
        case '*' :printf("%.1f", num1*num2);break;
        case '/' :if(num2 = 0)  printf("Wrong input!");
                    else printf("%.1f", num1/num2);break;
        default :printf("Wrong input!");
    }
    putchar('\n');

    return 0;

}
