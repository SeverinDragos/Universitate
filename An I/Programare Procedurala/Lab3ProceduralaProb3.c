#include <stdio.h>
#include <stdlib.h>

int main()
{
    long x,y,v[50],i=0;
    printf("x=");
    scanf("%ld",&x);
    printf("y=");
    scanf("%ld",&y);
    int sumacif=0,leftover=0;
    while(x || y || leftover)
    {
        sumacif=(x%10+y%10)+leftover;
        v[i++]=sumacif%10;
        leftover=sumacif/10;
        x/=10;
        y/=10;
    }
    for(i=i-1;i>=0;i--)
    {
        printf("%d",v[i]);
    }
    return 0;
}
