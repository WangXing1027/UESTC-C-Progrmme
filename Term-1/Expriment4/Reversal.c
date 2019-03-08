#include<stdio.h>

void Reversal(char sh[],int n)
{
    int i;
    for(i = n -1;i >= 0; --i)
        putchar(sh[i]);
}

int main()
{
    char sh[63],c;
    int i = 0;

    printf("Enter a message: ");
    while(1)
    {
        c = getchar();
        if(c == '\n') break;
        sh[i] = c;
        i++;
    }
    printf("Reversal is: ");
    Reversal(sh,i);
    putchar('\n');

    return 0;
}
