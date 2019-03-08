#include<stdio.h>

void selection_sort(int *A,int n)
{
    int i,k,j;
    for(i = 0; i < n-1; ++i)
    {
        k = i;
        for(j = i; j < n; ++j)
            if(A[j] < A[k])
                k = j;
        int t = A[i];
        A[i] = A[k];
        A[k] = t;
    }
}

int main()
{
    int A[10] = {0,2,4,1,6,5,9,8,3,7};
    int n = 10;
    selection_sort(A,n);
    for(int i = 0;i < n; ++i)
        printf("%4d",A[i]);
    return 0;
}