#include<stdio.h>

int main()
{
    int V[] = {11, 23, 19, 7, 17, 5, 3, 13, 2, 29};
    int i, j;
    
    for(i = 0;i < 2; ++i)
        for(j = 0; j < 9 - i; ++j)
            if(V[j] > V[j+1])
            {
                int t;
                t = V[j];
                V[j] = V[j+1];
                V[j+1] = t;
            }
    printf("%d\n",V[8]);
    for(i = 0; i < 10; ++i) 
        printf("%4d",V[i]);

    return 0;
}