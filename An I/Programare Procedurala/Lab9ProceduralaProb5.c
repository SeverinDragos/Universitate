#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f=fopen("Ex5.txt","a+b");
    char *sir=(char*)calloc(200,sizeof(char)),*cuvant=(char*)malloc(25*sizeof(char)),*p;
    fread(sir,sizeof(char),200,f);
    printf("Cuvantul este: ");
    fgets(cuvant,25,stdin);
    sir[strlen(sir)-1]='\0';
    cuvant[strlen(cuvant)-1]='\0';

    p=strtok(sir," ,.?!;'");
    while(p)
    {
        if(strstr(p,cuvant))
        {
            fwrite(p,sizeof(char),strlen(p),f);
            fputs(" ",f);
        }
        p=strtok(NULL," ,.?!;'");
    }
    fclose(f);
    return 0;
}
