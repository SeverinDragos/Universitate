#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Numarul: ");
    scanf("%d",&x);
    char *p;
    p=&x;
    p+=3;
    printf("Primul octet are valoarea: %d (adresa: %x)\n",*p,p);
    p--;
    printf("Al doilea octet are valoarea: %d (adresa: %x)\n",*p,p);
    p--;
    printf("Al treilea octet are valoarea: %d (adresa: %x)\n",*p,p);
    p--;
    printf("Al patrulea octet are valoarea: %d (adresa: %x)\n",*p,p);
    return 0;
}
