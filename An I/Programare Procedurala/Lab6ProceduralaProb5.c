#include <stdio.h>
#include <stdlib.h>

struct Complex
{
    int Rez,Imz;
    void (*pfAfis)(struct Complex);
    void (*pfCitire)(struct Complex*);
}v[100];

void Afisare(struct Complex x)
{
    printf("Rez: %d Imz: %d ",x.Rez,x.Imz);
}

void Citire(struct Complex *x)
{
    printf("Partea reala si apoi imaginara a numarului:");
    scanf("%d%d",&x->Rez,&x->Imz);
}

struct Complex AdunareComplexe(int n)
{
    struct Complex rezultat;
    int i;
    rezultat.Rez=0;
    rezultat.Imz=0;
    for(i=0;i<n;i++)
    {
    rezultat.Rez+=v[i].Rez;
    rezultat.Imz+=v[i].Imz;
    }
    return rezultat;
}

struct Complex InmultireComplexe(int n)
{
    struct Complex rezultat;
    int i,Re=0,Im=0;
    rezultat.Rez=v[0].Rez;
    rezultat.Imz=v[0].Imz;
    for(i=1;i<n;i++)
    {
    Re = (rezultat.Rez) * (v[i].Rez) - (rezultat.Imz) * (v[i].Imz);
    Im = (rezultat.Rez) * (v[i].Imz) + (v[i].Rez) * (rezultat.Imz);
    rezultat.Rez=Re;
    rezultat.Imz=Im;
    }
    return rezultat;
}

int main()
{
    int n,i;
    printf("Numarul de numere complexe:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        v[i].pfCitire=&Citire;
        v[i].pfCitire(&v[i]);
    }

    printf("Suma celor %d numere este:",n);
    struct Complex a;
    struct Complex (*pf)(int);
    pf=AdunareComplexe;
    a=(*pf)(n);
    a.pfAfis=Afisare;
    a.pfAfis(a);

    printf("\nProdusul celor %d numere este:",n);
    struct Complex b;
    struct Complex (*pf2)(int);
    pf2=InmultireComplexe;
    b=(*pf2)(n);
    b.pfAfis=Afisare;
    b.pfAfis(b);
    return 0;
}
