#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f=fopen("Ex3.txt","r+b");
    char *sir=(char*)malloc(sizeof(char)*25);
    int citire=fscanf(f,"%s",sir),i,PointerFisier=0;
    while(citire >= 0)
    {
        for(i=0;i<strlen(sir);i++)
            if('a' <= sir[i] && sir[i] <= 'z') sir[i]-=32;
                        else    sir[i]+=32;
        fseek(f,PointerFisier,SEEK_SET);
        fwrite(sir,sizeof(char),strlen(sir),f);
        PointerFisier+=strlen(sir)+1;
        fseek(f,1,SEEK_CUR);
        citire=fscanf(f,"%s",sir);
    }
    fclose(f);
    return 0;
}
