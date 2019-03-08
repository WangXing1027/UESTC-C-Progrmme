#include <stdio.h>
int main()
{
	float value, Commission;

	printf("Enter value of trade: ");
	scanf("%f", &value);

	while(value > 0.0)
		{
		if(value < 2500.00 && value > 0.00)
		Commission = 30.00+ 0.017 * value;

		else if(value < 6250.00)
		Commission = 56.00+ 0.0066 * value;

		else if(value < 20000.00)
		Commission = 76.00+ 0.0034 * value;

		else if(value < 50000.00)
		Commission = 100.00+ 0.0022 * value;

		else if(value < 500000.00)
		Commission = 155.00+ 0.0011 * value;

		else
		Commission = 255.00+ 0.0009 * value;

        if(Commission <39.00)
        Commission = 39.00;

        printf("Commission: $%.2f\n",Commission);

		printf("\nEnter value of trade: ");
		scanf("%f", &value);
		}

	return 0;
}
