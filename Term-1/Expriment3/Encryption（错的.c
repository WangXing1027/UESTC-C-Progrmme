#include<stdio.h>

char f(char *p, int n)
{
    char s;
    for(; p!= '0/'; ++p,++s)
    {
         if(*p >= 65 && *p <= 90)
         s = ((*p - 'A') + n) % 26 + 'A' ;
         if(*p >= 97 && *p <= 127)
         s = ((*p - 'a') + n) % 26 + 'a' ;
    }
    return s;
}

int main()
{
    char ch;
    char *p;
    int j;
    char x;

    p = ch;

    printf("Enter message to be encrypted: ");
    gets(*p);

    printf("Enter shift amount (1-25): ");
    scanf("%d", &j);

    x = f(p,j);

    printf("Encrypted message: %c",x);
    return 0;
}
