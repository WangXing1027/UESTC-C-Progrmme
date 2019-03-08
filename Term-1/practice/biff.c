#include<stdio.h>
int main()
{
    char c;
    while((c = getchar()) != '\n')
    {
        
        switch(c)
        {
            case 'A':printf("1");break;
            case 'B':printf("8");break;
            case 'E':printf("3");break;
            case 'I':printf("1");break;
            case 'O':printf("0");break;
            case 'S':printf("5");break;
            default:printf("%c",c);
        }
    }
    printf("!!!!!!!!!!!");
    return 0;
}