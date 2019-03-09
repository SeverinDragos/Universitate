#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct angajat
{
    unsigned int varsta : 6;
    char nume[30];
    unsigned int norma : 1;
    char CNP[10];
};

int main()
{
    printf("Structura ocupa %d octeti",sizeof(struct angajat));
    return 0;
}
