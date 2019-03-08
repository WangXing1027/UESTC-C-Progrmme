#include<stdio.h>
#define MAX 80
void Encrypt(char a[],int sh)
{
    int i;
    for(i = 0;i < MAX;++i)
    {
        if(a[i] >= 65&&a[i] <= 90)
            a[i] = ((a[i] - 'A') + sh)%26 + 'A';

        if(a[i] >= 97 && a[i] <= 127)
            a[i] = ((a[i] - 'a') + sh)%26 + 'a';
    }
}

int main()
{
    char a[MAX];
    int j;

    printf("Enter message to be encrypted: ");
    gets(a);

    printf("Enter shift amount (1-25): ");
    scanf("%d", &j);

    Encrypt(a,j);
    printf("Encrypted message: %s\n",a);

    return 0;

}
