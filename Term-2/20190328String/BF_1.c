#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int BF_1(char* T, char* P){
    int m = strlen(T);int i = 0;
    int n = strlen(P);int j = 0;

    while(i < m-n+1 && j < n)
        if (T[i] == P[j]){
            i++;
            j++;
        }
        else{
            i -= j-1;
            j = 0;
        }

    return i - j;
}

int BF_2(char* T, char* P){
    int m = strlen(T);  int i = 0;
    int n = strlen(P);  int j = 0;

    for(i = 0; i < m-n+1; ++i){
        for(j = 0; j < n; ++j){
            if(T[i+j] != P[j])    break;
        }
        if(j >= n)
            break;
    }
    return i;
}

int main(){
    char* T = "What's your name?";
    char* P = "you";

    int i = BF_1(T, P);
    int j = BF_2(T, P);

    printf("i : %d,j : %d",i,j);
    system("Pause");

    return 0;
}