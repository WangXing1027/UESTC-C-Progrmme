//root.c

#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    double d, x1, x2;

    printf("Please input a, b, c:");
    scanf("%lf%lf%lf", &a, &b, &c);

    d = b * b - 4 * a * c;
    
    if (d > 0)
    {
    	x1 = (-b + sqrt(d)) / 2 / a;
    	x2 = (-b - sqrt(d)) / 2 / a;

    	printf("The roots are: %.3lf, %.3lf\n", x1, x2);
    }
    
    else if (fabs(d) < 1e-7)
  	 	{
  	 		x1 = -b / 2 / a;
  	 		printf("Two identical roots: %.3lf",x1);
	    }
   	else 
		{
			x1 = -b / 2 / a;
			x2 = sqrt(-d) / 2 / a;
			
			printf("roots1:%.3lf+%.3lfi\n", x1 , x2);
			printf("roots1:%.3lf-%.3lfi\n", x1 , x2);
		}
		
    return 0;
}
