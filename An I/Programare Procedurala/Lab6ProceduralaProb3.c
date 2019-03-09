#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x;
    printf("Numarul: ");
    scanf("%d",&x);
    double (*pf[3])(double);
    pf[0]=&sqrt;
    pf[1]=&sin;
    double rez;
    rez=(*pf[0])(x);
    printf("%d\n",rez);
    rez=(*pf[1])(x);
    printf("%d\n",rez);
    return 0;
}
