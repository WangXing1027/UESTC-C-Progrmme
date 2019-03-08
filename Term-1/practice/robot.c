#include<stdio.h>
#include<string.h>
int main()
{
    char ch[64];
    gets(ch);
    if(strcmp(ch, "how are you") == 0)
        printf("i am fine\n");

    else
        printf("error\n");

    return 0;
    
}