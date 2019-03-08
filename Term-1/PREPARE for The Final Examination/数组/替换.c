/*
#include<stdio.h>
#include<string.h>

int main()
{
    char a[] = "abc", b[] = "ttt";
    char c[4];
    char s[1024];
    int j, i = 0;

    gets(s);

    while(s[i] != '\0')
    {
        for(j = 0; j < 3; ++j)
            c[j] = s[i+j];

        c[3] = '\0';

        if(strcmp(a,c) == 0)
            for(j = 0; j < 3; ++j)
                s[j+i] = b[j];

        ++i;
    }

    puts(s);

}
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char m_str[100], a_str[100], b_str[100];
    char new_str[100] = "\0";
    char *ptr;
    printf("Please input the pre str: ");
    gets(m_str);
    printf("Please input the A str: ");
    gets(a_str);
    printf("Please input the B str: ");
    gets(b_str);

    while((ptr = strstr(m_str, a_str)) != NULL)
    {
        *ptr = '\0';
        strcat(new_str,m_str);
        strcat(new_str,b_str);
        strcpy(m_str,ptr+strlen(a_str));
    }

    strcat(new_str, m_str);
    printf("The new str is: %s",new_str);

    return 0;

}
