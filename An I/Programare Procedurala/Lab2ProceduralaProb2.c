#include <stdio.h>
#include <math.h>

int i=1,v[33];

void Baza2(int x)
{
    v[i++]=x%2;
    if(x!=1)    Baza2(x/2);
}

int main()
{
    int x,n,nr;
    printf("x=");
    scanf("%d",&nr);
    printf("Afiseaza bitul:");
    scanf("%d",&n);
    // afisare bit n
    x=nr;
    Baza2(x);
    printf("%d",v[n]);
    // setare bit n
    printf("\nSeteaza bitul:");
    scanf("%d",&n);
    int b=1<<(n-1);
    x=x|b;
    printf("%d",x);
    // stergere bit n
    printf("\nSterge bitul:");
    scanf("%d",&n);
    b=1<<(n-1);
    x=nr;
    x=x&(~b);
    printf("%d",x);
    // completementare bit n
    printf("\nComplementeaza bitul:");
    scanf("%d",&n);
    b=1<<(n-1);
    x=nr;
    x=x^b;
    printf("%d",x);
    return 0;
}
