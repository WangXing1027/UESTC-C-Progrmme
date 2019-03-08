#include<stdio.h>

int* sortedSquares(int* A, int ASize, int* returnSize) {
    int i=0,j=ASize-1;
    int k=ASize-1;
    int *B=(int *)calloc(ASize,sizeof(int));
    while(i<=j){
        if(abs(A[i])<abs(A[j])){
            B[k]=A[j]*A[j];
            j--;
        }
        else{
            B[k]=A[i]*A[i];
            i++;
        }
        k--;
    }
    *returnSize=ASize;
    
    return B;
}

int main()
{
    int A[6] = {-4, -2, 0, 4, 8, 10};
    int N;
    int *B = sortedSquares(A, 6, &N);

    for(int i = 0; i < N; ++i)
    printf("%4d",*(B+i));

    return 0;
}