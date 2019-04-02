#include<stdio.h>

int main(){
    int w = 0,x = 0,y = 0,z = 0,a = 0;
    int i=0;

    for(w = 0;w <= 2; ++w){
        for(x = 0;x <= 4;++x){
            for(y = 0;y <= 10; ++y){
                for(z = 0; z <= 20; ++z){
                    for(a = 0; a <= 100; ++a){
                        if(50*w + 25*x + 10*y + 5*z + 1*a == 100){
                            printf("50:%4d      25:%2d      10:%2d      5:%2d       1:%2d\n",w,x,y,z,a);
                            ++i;
                        }
                        if(50*w + 25*x + 10*y + 5*z + 1*a >= 100)
                            break;
                    }
                }
            }
        }
    }
    
    printf("%d ways.",i);

    return 0;

}