#include<stdio.h>
#include<stdlib.h>

void merge(int *R,int lo,int mid, int hi)
{
    int i ,k;
    int *tmp = (int*)malloc((hi-lo+1)*sizeof(int*));    //辅助数组
    int left_lo = lo;
    int left_hi = mid;
    int right_lo = mid + 1;
    int right_hi = hi;

    for(k = 0; left_lo <= left_hi &&right_lo <= right_hi ; k++)
    {
        if(R[left_lo] <= R[right_lo])
            tmp[k] = R[left_lo++];
        else
            tmp[k] = R[right_lo++];
    }

    if(left_lo <= left_hi)
        for(i = left_lo; i<= left_hi; i++)
            tmp[k++] = R[i];

    if(right_lo <= right_hi)
        for(i = right_lo; i<= right_hi; i++)
            tmp[k++] = R[i];

    for(i = 0;i < hi-lo+1; i++)
        R[lo+i] = tmp[i];

    return;
}

//归并排序
void merge_sort(int *A, int lo, int hi)
{
    int mid;
    if(lo < hi)
    {
        mid = (lo + hi)/2;
        merge_sort(A,lo,mid);           //分
        merge_sort(A,mid+1,hi);         //分
        merge(A,lo,mid,hi);             //合
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