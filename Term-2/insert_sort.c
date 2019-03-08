#include<stdio.h>
int sequential_search(int *A, int a, int n)
{
    int i;
    for(i = 0; i < n-1; ++i)
        if(A[i] > a)
            break;
    return i;
}

//二分查找，有问题
/*
int binary_search(int *A, int a, int n)
{
    int i,mid,lo = 0, hi = n-1;
    while(1 < hi - lo)
    {
        mid = (lo + hi)/2;
        if(n < A[mid])
            hi = mid;
        else lo = mid;
    }
    i = lo+1;
}
*/

void insert(int *A,int a,int n)
{
    int i = sequential_search(A, a, n);
    for(int j = n; j > i;--j)
        A[j] = A[j-1];
    A[i] = a;
}

void insert_sort(int *A, int n)
{
    for(int i = 0;i < n-1; ++i)
    {
        if(A[i] > A[i+1])
            insert(A, A[i+1], i+1);
    }
}

int main()
{
    int A[10] = {0,2,4,1,6,5,9,8,3,7};
    int n = 10;
    insert_sort(A,n);
    for(int i = 0;i < n; ++i)
        printf("%4d",A[i]);
    return 0;
}