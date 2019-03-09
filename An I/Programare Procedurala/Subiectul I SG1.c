#include <stdio.h>
#include <stdlib.h>

void Scot1Si0(int n,int *cif1,int *cif0)
{
    int nr1=0,nr0=0;
    while(n != 0)
    {
        if(n%2 == 0)  nr0++;
        else          nr1++;
        n/=2;
    }
    *cif1=nr1;
    *cif0=nr0;
}

void Rotunde()
{
    int a,b,cif1,cif0,i;
    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);
    for(i=a;i<=b;i++)
    {
        Scot1Si0(i,&cif1,&cif0);
        if (cif1 == cif0)   printf("%d ",i);
    }
}

int main()
{
    Rotunde();
    return 0;
}
