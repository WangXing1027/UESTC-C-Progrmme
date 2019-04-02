#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int SubString(char* T, char* P){
    int m = strlen(P);int i = 0;
    int n = strlen(T);int j = 0;

    for(i > 0;i < n-m+1;++i){
        for(j = 0; j < m; ++j){
            if(T[i+j] != P[j]) break;
        }
        if(m <= j)  break;
    }

    return i;
}

int main(){
    char* T = "What do you major in?";
    char* P = "you";
    
    int i = SubString(T, P);
    printf("%d", i);

    return 0;
}