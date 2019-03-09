#include <stdio.h>
#include <string.h>
#include "cod.h"

struct candidat
{
    int nr_leg;
    char nume[20],buget,admis;
    float nota_mate,nota_info,nota_bac,medie;
}v[100];

void Citire (struct candidat v[],int n)
{
    char s[20];
    int i;
    printf("Numele:");
    getchar();
    fgets(s,20,stdin);
    if(strcmp(v[0].nume,"") == 0)
    {
            strcpy(v[0].nume,s);
            printf("Nr legitimatiei:");
            scanf("%d",&v[0].nr_leg);
            printf("Nota mate:");
            scanf("%f",&v[0].nota_mate);
            printf("Nota info:");
            scanf("%f",&v[0].nota_info);
            printf("Nota bac:");
            scanf("%f",&v[0].nota_bac);
    }
    else
    {
        int flag=0;
        i=0;
        while(i<n)
        {
            if( strcmp(s,v[i].nume) <0 )
            {
                flag=1;
                int x=n;
                while(x>i)
            {
                v[x]=v[x-1];
                x--;
            }
            strcpy(v[i].nume,s);
            printf("Nr legitimatiei:");
            scanf("%d",&v[i].nr_leg);
            printf("Nota mate:");
            scanf("%f",&v[i].nota_mate);
            printf("Nota info:");
            scanf("%f",&v[i].nota_info);
            printf("Nota bac:");
            scanf("%f",&v[i].nota_bac);
            break;
            }
            else
                i++;
        }
        if(flag == 0)
        {
            strcpy(v[i].nume,s);
            printf("Nr legitimatiei:");
            scanf("%d",&v[i].nr_leg);
            printf("Nota mate:");
            scanf("%f",&v[i].nota_mate);
            printf("Nota info:");
            scanf("%f",&v[i].nota_info);
            printf("Nota bac:");
            scanf("%f",&v[i].nota_bac);
        }
    }
}

void Afisare(struct candidat v[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Candidatul: %s",v[i].nume);
        printf("Nr legitimatiei: %d\n",v[i].nr_leg);
        printf("Nota mate: %f\n",v[i].nota_mate);
        printf("Nota info: %f\n",v[i].nota_info);
        printf("Nota bac: %f\n",v[i].nota_bac);
        printf("Media: %f\n",v[i].medie);
        printf("Admis: %c\n",v[i].admis);
        printf("Buget: %c\n",v[i].buget);
    }
}

void StabilireBuget (struct candidat v[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
            if(v[i].medie < v[j].medie)
        {
            struct candidat inter=v[i];
            v[i]=v[j];
            v[j]=inter;
        }
    }
    int nr_promovati=0;
    for(i=0;i<n;i++)
        if(v[i].admis == 'Y')   nr_promovati++;
    nr_promovati=(float)(nr_promovati)*0.75;
    printf("Mi-a iesit nr promovati:%d\n",nr_promovati);
    int numar=nr_promovati;
    for(i=0;i<=numar;i++)
    {
        if(nr_promovati)
            v[i].buget='Y';
        else
            v[i].buget='N';
            nr_promovati--;
    }
}

void AfisareLaAlegere(struct candidat v[],int n)
{
    int choice,i,j;
    printf("Alegeti ce sa se afiseze:\nToti candidatii (alfabetic): 1\nAdmisi la buget: 2\nAdmisi la taxa: 3\nRespinsi: 4\n");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
                if(strcmp(v[i].nume,v[j].nume)>0)
            {
                struct candidat inter=v[i];
                v[i]=v[j];
                v[j]=inter;
            }
        }
            for(i=0;i<n;i++)
        {
            printf("Candidatul: %s",v[i].nume);
            printf("Nr legitimatiei: %d\n",v[i].nr_leg);
            printf("Nota mate: %f\n",v[i].nota_mate);
            printf("Nota info: %f\n",v[i].nota_info);
            printf("Nota bac: %f\n",v[i].nota_bac);
            printf("Media: %f\n",v[i].medie);
            printf("Admis: %c\n",v[i].admis);
            printf("Buget: %c\n",v[i].buget);
        }
        break;
        case 2:
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
                if(v[i].medie < v[j].medie)
            {
                struct candidat inter=v[i];
                v[i]=v[j];
                v[j]=inter;
            }
        }
        for(i=0;i<n;i++)
        {
            if(v[i].buget == 'Y')
            {
            printf("Candidatul: %s",v[i].nume);
            printf("Nr legitimatiei: %d\n",v[i].nr_leg);
            printf("Nota mate: %f\n",v[i].nota_mate);
            printf("Nota info: %f\n",v[i].nota_info);
            printf("Nota bac: %f\n",v[i].nota_bac);
            printf("Media: %f\n",v[i].medie);
            printf("Admis: %c\n",v[i].admis);
            printf("Buget: %c\n",v[i].buget);
            }
        }
        break;
        case 3:
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
                if(v[i].medie < v[j].medie)
            {
                struct candidat inter=v[i];
                v[i]=v[j];
                v[j]=inter;
            }
        }

        for(i=0;i<n;i++)
        {
            if(v[i].buget == 'N')
            {
            printf("Candidatul: %s",v[i].nume);
            printf("Nr legitimatiei: %d\n",v[i].nr_leg);
            printf("Nota mate: %f\n",v[i].nota_mate);
            printf("Nota info: %f\n",v[i].nota_info);
            printf("Nota bac: %f\n",v[i].nota_bac);
            printf("Media: %f\n",v[i].medie);
            printf("Admis: %c\n",v[i].admis);
            printf("Buget: %c\n",v[i].buget);
            }
        }
        break;
        case 4:
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
                if(v[i].medie < v[j].medie)
            {
                struct candidat inter=v[i];
                v[i]=v[j];
                v[j]=inter;
            }
        }

        for(i=0;i<n;i++)
        {
            if(v[i].admis == 'N')
            {
            printf("Candidatul: %s",v[i].nume);
            printf("Nr legitimatiei: %d\n",v[i].nr_leg);
            printf("Nota mate: %f\n",v[i].nota_mate);
            printf("Nota info: %f\n",v[i].nota_info);
            printf("Nota bac: %f\n",v[i].nota_bac);
            printf("Media: %f\n",v[i].medie);
            printf("Admis: %c\n",v[i].admis);
            printf("Buget: %c\n",v[i].buget);
            }
        }
        break;
    }
}

int main()
{
    int n,citit=0,i;
    printf("Numarul de candidati:");
    scanf("%d",&n);
    while(citit<n)
        {
            Citire(v,citit);
            citit++;
        }
    for(i=0;i<n;i++)
    {
        v[i].medie=admitere(v[i].nota_mate,v[i].nota_info,v[i].nota_bac);
        if(v[i].medie >= promovat)
            v[i].admis='Y';
        else
            v[i].admis='N';
    }
    Afisare(v,n);
    StabilireBuget(v,n);
    Afisare(v,n);
    AfisareLaAlegere(v,n);
    return 0;
}
