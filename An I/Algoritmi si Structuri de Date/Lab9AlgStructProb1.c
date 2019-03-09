#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partion(int v[], int p, int r)
{

    int Nrpivot=p+rand()%(r-p+1),pivot,i=p-1,j;
    pivot=v[Nrpivot];
    swap(&v[Nrpivot], &v[r]);
    for (j=p;j<r;j++)
    {
        if (v[j]<pivot)
        {
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i+1], &v[r]);
    return i + 1;
}



void QSort(int v[100], int p, int q)
{

    int j;
    if (p < q)
    {
        j=partion(v,p,q);
        QSort(v,p,j-1);
        QSort(v,j+1,q);
    }

}

int main()
{
    srand(time(NULL));
    int i,*v=(int *)malloc(sizeof(int)*100),n;
    printf("Numarul de elemente:");
    scanf("%d",&n);
    printf("Elementele: ");
    for (i=0;i<n;i++)
        scanf("%d",&v[i]);
    QSort(v,0,n-1);
    printf("Vectorul sortat crescator:");
    for (i=0;i<n;i++)
         printf("%d ", v[i]);
    return 0;

}
