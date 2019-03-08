#include<stdio.h>

int main()
{
    char a,b,ch[64];
    scanf("%c,%c,%s",&a,&b,ch);
    for(int i = 0; ch[i] != '\0'; ++i)
    {
        if(ch[i] == a)
            ch[i] = b;
    }
    puts(ch);
    return 0;
}