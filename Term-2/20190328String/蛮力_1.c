#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 100

int Substring(char* T,char* P){
    int n = strlen(T);
    int i = 0;
    int m = strlen(P);
    int j = 0;

    while(j < m && i < n){
        if(T[i] == P[j]) {
            i++;
            j++;
        }

        else {
            i -= j - 1;
            j = 0;
        }
    }

    return i-j;
}

int main(){
    char *T = "what do you want to major in?";
    char *P = "you";
    int i = Substring(T, P);
    
    printf("%d\n", i);
    for(int j = i;j < i + strlen(P);++j)
        printf("%c",T[j]);

    printf("\n");
    system("Pause");

    return 0;
}