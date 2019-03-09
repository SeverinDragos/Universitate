#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int CitescVector(int **v)
{
    int n,i;
    printf("Numarul de elemente: ");
    scanf("%d",&n);
    int *p=(int*)malloc(sizeof(int)*n);
    printf("Elementele: ");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    *v=p;
    return n;
}

void ScriuImpare(char fis[],int v[],int n)
{
    FILE *f=fopen(fis,"wb");
    if(f == NULL)
        printf("Eroare la deschiderea fisierului\n");
    int i;
    for(i=0;i<n;i++)
        if(v[i]%2 == 1) fprintf(f,"%d",v[i]);
    fclose(f);
}

void AdaugPrime(char fis[])
{
    FILE *f=fopen(fis,"a+b");
    if(f == NULL)
        printf("Eroare la deschiderea fisierului\n");
        int x,i=0,j,v[100];
    while(1)
    {
        printf("1");
        int prim=1;
        fscanf(f,"%d",&x);
        if(x == 1)  prim=0;
        for(j=2;j<=x/2;j++)
            if(x%j == 0)    prim=0;
        if(prim)    v[i++]=x;
        if( feof(f) )   break;
    }
    fwrite(v,sizeof(int),i,f);
    fclose(f);
}

int main()
{
    int *v,n;
    /*n=CitescVector(&v);
    ScriuImpare("Test2PP.txt",v,n);*/
    AdaugPrime("Test2PP.txt");
    return 0;
}
