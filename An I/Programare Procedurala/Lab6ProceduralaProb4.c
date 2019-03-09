#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,v[100][100],i,j;
    printf("Numarul de linii si coloane:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&v[i][j]);
    }
    printf("\n");
    int *p;
    for(i=0;i<n;i++)
    {
        p=v[i];
        for(j=0;j<n;j++)
        {
            printf("%d ",*p);
            p++;
        }
        printf("\n");
    }
    if(n%2 == 1)
    {
        p=v[n/2];
        p+=n/2;
        printf("Elementul de la intersectia diagonalelor este:%d\n",*p);
    }
    printf("Diagonala principala este formata din elementele:\n");
    for(i=0;i<n;i++)
    {
        p=v[i];
        p+=i;
        printf("%d ",*p);
    }
    printf("\nDiagonala secundara este formata din elementele:\n");
    for(i=0;i<n;i++)
    {
        p=v[i];
        p+=n-1-i;
        printf("%d ",*p);
    }
    return 0;
}
