#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int* buildNext(char* P){
    int m = strlen(P);int j = 0;
    int *N = (int*)malloc(sizeof(int)*m);
    int t = N[0] = -1;
    while(j < m-1){
        if(0 > t || P[j] == P[t])
            N[++j] = ++t;

        else
            t = N[t];
    }
    return N;
}

int KBP(char* T, char* P){
    int *next = buildNext(P);
    int n = strlen(T);int i = 0;
    int m = strlen(P);int j = 0;

    while(i < n && j < m){
        if(j < 0 || T[i] == P[j]){
            i++;
            j++;
        }
        else
            j = next[j];
    }
    free(next);
    return i-j;
}

int main(){
    char* T = "What's your name?";
    char* P = "you";

    int i = KBP(T, P);
    printf("%d\n", i);

    system("Pause");
    return 0;
}