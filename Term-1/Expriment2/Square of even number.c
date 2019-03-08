#include<stdio.h>
#include<math.h>

int main()
{
    int a, i, square;
    printf("Enter a number: ");
    scanf("%d",&a);

    for(i=2;i*i<=a;i = i+2)
   {
    square = i*i;
    printf("%d\n",square);
    }
    return 0;
}
