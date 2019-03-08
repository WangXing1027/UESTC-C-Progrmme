#include<stdio.h>

#include <stdlib.h>

int main()

{

        int *primes_array = NULL;

        int num = 0,i = 0,j = 0,index = 0,flag = 0;

        scanf("%d",&num);

        primes_array =(int *)malloc(num*sizeof(int));

        for(i=0;i<num;i++)

        primes_array[i] = 0;

        primes_array[0] = 2;

        index = 0;

        for(i=2;i<=num;i++)

        {

                for(j=0;j<=index;j++){

                        flag = i % primes_array[j];

                        if(flag == 0)

                                break;

                }

                if(flag){

                        index ++;

                        primes_array[index] = i;

                }

        }
        for(i=0;i<index;i++)

        {

                printf("%d,",primes_array[i]);
        }

        printf("%d",primes_array[i]);
        free(primes_array);
        printf("\n");

        return 0;

}