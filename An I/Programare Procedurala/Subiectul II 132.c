#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct complex
{
    float Re,Im,modul;
}v[100];

FILE *fin,*fout;

void Citire()
{
    fin=fopen("complexe.txt","r");
    if(fin == NULL)
        printf("Eroare la deschiderea fisierului");
    int n,i;
    fscanf(fin,"%d",&n);
    for(i=0;i<n;i++)
    {
        fscanf(fin,"%f",&v[i].Re);
        fscanf(fin,"%f",&v[i].Im);
    }
    fclose(fin);
}

void CalculareModul()
{
    fin=fopen("complexe.txt","r");
    if(fin == NULL)
        printf("Eroare la deschiderea fisierului");
    int n,i;
    float max=0;
    fscanf(fin,"%d",&n);
    for(i=0;i<n;i++)
    {
        int x=v[i].Re*v[i].Re+v[i].Im*v[i].Im;
        v[i].modul=sqrt(x);
        if(v[i].modul > max)    max=v[i].modul;
    }
    for(i=0;i<n;i++)
    {
        if(v[i].modul == max)   printf("%f %f\n",v[i].Re,v[i].Im);
    }
    fclose(fin);
}

int cmp(void const *a,void const *b)
{
    if( ((struct complex*)a)->modul == ((struct complex*)b)->modul )
        return ((struct complex*)a)->Re - ((struct complex*)b)->Re;
    return ((struct complex*)b)->modul - ((struct complex*)a)->modul;
}


int main()
{
    Citire();
    CalculareModul();
    fin=fopen("complexe.txt","r");
    if(fin == NULL)
        printf("Eroare la deschiderea fisierului");
    int n,i;
    fscanf(fin,"%d",&n);
    qsort(v,n,sizeof(struct complex),cmp);
    fout=fopen("complexe_sort.txt","w");
    for(i=0;i<n;i++)
        fprintf(fout,"%f %f\n",v[i].Re,v[i].Im);
    return 0;
}
