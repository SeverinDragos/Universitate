#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int v[4001]={0};

int main()
{
    int n,m,i,sum=0,x;
    printf("n=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x<=0)
            v[abs(x)]++;
        else
            v[x+2000]++;
    }
    printf("m=");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&x);
        if(x<=0)
            v[abs(x)]++;
        else
            v[x+2000]++;
    }
    for(i=0;i<=2000;i++)
        if(v[i]==2) sum++;
    for(i=2000;i<=4000;i++)
        if(v[i]==2) sum++;
    printf("%d",sum);
    return 0;
}
