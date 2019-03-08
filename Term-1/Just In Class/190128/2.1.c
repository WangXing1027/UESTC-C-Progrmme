#include <stdio.h>
#include <string.h>

int main()
{
    char *str[] = { "Page", "Jobs", "Gates", "Zucherberg", "Dorsey", "Ellison" };
    int i, j;

    int n = sizeof(str) / sizeof(char*);
    char *temp;

    for (i = 1; i < n; ++i)
    {
        for (j = 0; j < n-i; ++j)
            if (strcmp(str[j],str[j+1]) > 0)
            {
                temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
    }

    for (i = 0; i < n; ++i) printf("%s\n", str[i]);
    return 0;
}