#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=1;
    char *p;
    p=&x;
    p+=3;
    if(*p == 1) printf("Big-endian");
    else        printf("Little-endian");
    return 0;
}
