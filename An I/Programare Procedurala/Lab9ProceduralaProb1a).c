#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f,*fout;
    f=fopen("ex1.txt","rb");
    if(f == NULL)
        printf("Eroare la deschiderea fisierului\n");

    char c,*sir;
    sir=(char*)malloc(sizeof(char)*100);
    c=fgetc(f);
    fseek(f,1,SEEK_CUR);
    fread(sir,sizeof(char),100,f);

    char *p;
    p=strchr(sir,c);
    while(p)
    {
        strcpy(p,p+1);
        p=strchr(sir,c);
    }

    fout=fopen("ex1a).out","w");
    fwrite(sir,sizeof(char),strlen(sir),fout);
    if(fout == NULL)
        printf("Eroare la deschiderea fisierului\n");

    fclose(f);
    fclose(fout);
    return 0;
}
