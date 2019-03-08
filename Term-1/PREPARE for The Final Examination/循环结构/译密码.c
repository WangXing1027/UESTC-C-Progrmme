#include<stdio.h>
int main()
{
    char c;
    while((c = getchar()) != '\n')
    {
        if (c >= 97 && c <= 122)
            printf("%c", (c - 'a' + 4)%26 + 'a');
        else if (c >= 65 &&c <= 90)
            printf("%c", (c - 'A' + 4)%26 + 'A');
        else printf("%c",c);
    }

    return 0;
}
