#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elev
{
    char nume[50],prenume[50];
    float notaInfo,notaMate,Media;
}v[100];

FILE *fin,*fout;

void Citire()
{
    fin=fopen("elevi.txt","r");
    if(fin == NULL)
        printf("Eroare la deschiderea fisierului");
    int n,i,nr,nr2;
    float nr3;
    fscanf(fin,"%d",&n);
    fgetc(fin);
    char buffer[120],*p;
    for(i=0;i<n;i++)
    {
        fgets(buffer,120,fin);

        p=strtok(buffer," ");
        strcpy(v[i].nume,p);

        p=strtok(NULL," ");
        strcpy(v[i].prenume,p);

        p=strtok(NULL,",.");
        nr=(int)(p[0]-48);
        p=strtok(NULL," ");
        nr2=(int)(p[0]-48);
        nr3=nr2;
        nr3/=10;
        nr3+=nr;
        v[i].notaInfo=nr3;

        p=strtok(NULL,",.");
        nr=(int)(p[0]-48);
        p=strtok(NULL," ");
        nr2=(int)(p[0]-48);
        nr3=nr2;
        nr3/=10;
        nr3+=nr;
        v[i].notaMate=nr3;

        v[i].Media=(v[i].notaInfo+v[i].notaMate)/2;
    }
    fclose(fin);
}

void AfisareMedieMax()
{
    fin=fopen("elevi.txt","r");
    if(fin == NULL)
        printf("Eroare la deschiderea fisierului");
    int n,i;
    fscanf(fin,"%d",&n);
    float max=0;
    for(i=0;i<n;i++)
        if(v[i].Media > max)    max=v[i].Media;
    for(i=0;i<n;i++)
        if(v[i].Media == max)
    {
        fputs(v[i].nume,stdout);
        printf(" ");
        fputs(v[i].prenume,stdout);
        printf("\n");
    }
    fclose(fin);
}

int cmp(const void *a,const void *b)
{
    if( ((struct elev*)a)->Media  ==  ((struct elev*)b)->Media )
        return ((struct elev*)a)->notaMate - ((struct elev*)b)->notaMate;
    return ((struct elev*)b)->Media - ((struct elev*)a)->Media;
}

int main()
{
    Citire();
    AfisareMedieMax();
    fin=fopen("elevi.txt","r");
    if(fin == NULL)
        printf("Eroare la deschiderea fisierului");
    int n,i;
    fscanf(fin,"%d",&n);
    qsort(v,n,sizeof(struct elev),cmp);
    fout=fopen("elevi_sort.txt","w");
    for(i=0;i<n;i++)
    {
        fputs(v[i].nume,fout);
        fprintf(fout," ");
        fputs(v[i].prenume,fout);
        fprintf(fout," ");
        fprintf(fout,"%f ",v[i].notaInfo);
        fprintf(fout,"%f ",v[i].notaMate);
        fprintf(fout,"%f\n",v[i].Media);
    }
    return 0;
}
