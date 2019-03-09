#include <stdio.h>
#include "cod.h"

int main()
{
    char c;
    printf("Caracterul citit este:");
    scanf("%c",&c);
    if(c>'A' && c<'Z')
    {
        c+=32;
        printf("%c",c);
    }
    else
        printf("%c",c);
    return 0;
}
