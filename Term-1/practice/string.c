#include<stdio.h>
#include<string.h>
const char* get_level(int score)
{
    char level[64];
    const char* p = level;
    if(score>=0 && score<=100)
    {
        switch(score/10)
        {
            case 10:strcpy(level, "Great");break;
            case 9:strcpy(level, "S\0");break;
            case 8:strcpy(level, "A\0");break;
            case 7:strcpy(level, "B\0");break;
            case 6:strcpy(level, "C\0");break;
            default: strcpy(level, "D\0");
        }
    }
    else
    {
        strcpy(level, "Error");
    }
    return p;
}


int main()
{
    int score;
    const char* level;
    scanf("%d",&score);
    level = get_level(score);
    puts(level);
    return 0;
}