#include <stdio.h>
#include <string.h>

char largest_word[100],smallest_word[100],s[100];

int main()
{
	printf("Enter word: ");

	scanf("%s",s);
    strcpy(smallest_word,s);
    strcpy(largest_word,s);

	while(1)
    {
        if (s == '\n') break;
		if (strlen(s)==4) break;

        printf("Enter word: ");
        scanf("%s",s);
        if (strcmp(largest_word,s)<0) strcpy(largest_word,s);
        if (strcmp(smallest_word,s)>0) strcpy(smallest_word,s);

    }

	printf("\nSmallest word: %s\n",smallest_word);
	printf("Largest word: %s\n",largest_word);

	return 0;
}
