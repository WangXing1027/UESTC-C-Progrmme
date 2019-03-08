#include<stdio.h>

void bubble_sort(int *A,int n)
{
    for(int i = 0; i < n-1; ++i)
        for(int j = 0;j < n-i; ++j)
            if(A[j] > A[j+1])
            {
                int t = A[j];
                A[j] = A[j+1];
                A[j+1] = t;
            }
}

void bubble_sort_2(int *A,int n)
{
    for(int i = 0;i < n-1;++i)
    {
        int flag = 0;                           //flag为元素交换的标志
            for(int j = 0;j < n-i; ++j)
                if(A[j] > A[j+1])
                {
                    int t = A[j];
                    A[j] = A[j+1];
                    A[j+1] = t;
                    flag = 1;
                }
        if(flag == 0)    break;
    }
}

void bubble_sort_3(int *A,int n)
{
    int i = n;
    while(i > 1)
    {
        int flag = 1;                           //flag为元素交换的位置
        for(int j = 1;j < i;++j)
            if(A[j] > A[j+1])
            {
                int t = A[j];
                A[j] = A[j+1];
                A[j+1] = t;
                flag = j;
            }
        i = flag;
    }
}

int main()
{
    int A[10] = {0,2,4,1,6,5,9,8,3,7};
    int n = 10;
    bubble_sort_3(A,n);
    for(int i = 0;i < n; ++i)
        printf("%4d",A[i]);
    return 0;
}