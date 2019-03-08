#include<stdio.h>

void merge(int Ra[],int Rb[],int h,int s, int t)
{
    int i = h,k = h,j = s + 1;
    while(i <= s && j <= t)
    {
        if(Ra[i] < Ra[j])
            Rb[k++] = Ra[j++];
        else    Rb[k++] = Ra[j++];
    }
    while(i <= s)   Rb[k++] = Ra[i++];
    while(j <= t)   Rb[k++] = Ra[j++];
    for(i = h; i <= t; i++) Ra[i] = Rb[i];
}

int *merge_sort(int *A, int lo, int hi)
{
    int mid;
    if(lo < hi)
    {
        mid = (lo + hi)/2;
        int Aa[] = merge_sort(A,lo,mid);
        int Ab[] = merge_sort(A,mid+1,hi);
        merge(Aa[],Ab[],lo,mid,hi);
    }
}

int main()
{
    int A[10] = {0,2,4,1,6,5,9,8,3,7};
    int n = 10;
    merge_sort(A,0,n-1);
    for(int i = 0;i < n; ++i)
        printf("%4d",A[i]);
    return 0;
}