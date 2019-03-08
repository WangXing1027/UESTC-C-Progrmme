#include<stdio.h>
void del(char * s,int n,int len)
{
    if(s==NULL||n<0)
    {
        printf("error");
    }
    else
    {
        char *p;
        s+=n;
        for(p=s+len;*s++=*p++;);
    }
}
int main()
{
    char s[]="apple";

    del(s,2,2);
    puts(s);
    return 0;
}