#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int magic, guess;
	
	srand(time(NULL));
	
	magic = rand () % 100 + 1;
	
	
	do
	{
		printf("Please input your answer: ");
		scanf("%d", &guess);

		if(magic == guess)
			printf("Bingo!\n");
			
	 	else if(guess<magic)
	 		printf("Bit smaller\n");
	 		
		else
			printf("Bit Bigger\n",magic);
			
		
	}while(magic != guess);

	return 0;
}
