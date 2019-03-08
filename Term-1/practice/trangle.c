#include<stdio.h>

int main()
{
    int tr;
    int j,i;
    scanf("%d",&tr);
    if(tr % 2 == 0)
        printf("error");
    else
    {
        for (i = 0;i < (tr + 1)/2; ++i)
        {
            for(j = 0;j < i; ++j)
                printf(" ");
            for(j = 0;j < tr - 2*i; ++j)
                printf("*");
            for(j = 0;j < i; ++j)
                printf(" ");
            printf("\n");
        }      
    }
    return 0;
}