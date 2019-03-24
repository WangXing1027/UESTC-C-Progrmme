#include<stdio.h>
#include<stdlib.h>
 
void swap(int a[], int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
 
int partition(int a[], int lo, int hi)
{
	int key;
	key = a[lo];
	while (lo < hi)//以key为交换媒介，大于它的放在后边，小于它的放在前面
	{
		while (lo < hi && a[hi] >= key)//条件判断 lo < hi
			hi--;
		swap(a, lo, hi);
		while (lo < hi && a[lo] <= key)
			lo++;
		swap(a, lo, hi);
	}
	return lo;
}
 
void quick_sort(int A[], int lo, int hi)
{
	int idx;
	if (lo < hi)
	{
		idx = partition(A, lo, hi);//将a[]一分为二
 
		quick_sort(A, lo, idx - 1);//对低子表递归排序
		quick_sort(A, idx + 1, hi);//对高子表递归排序
	}
}

int main()
{
    int A[10] = {0,2,4,1,6,5,9,8,3,7};
    int n = 10;

    quick_sort(A,0,n-1);

    for(int i = 0;i < n; ++i)
        printf("%4d",A[i]);

    return 0;
}