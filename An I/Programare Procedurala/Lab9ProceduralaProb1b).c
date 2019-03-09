#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f;
    f=fopen("ex1.txt","rb");
    if(f==NULL)
        printf("Eroare la deschiderea fisierului\n");

    char c,*sir;
    sir=(char*)calloc(100,sizeof(char));
    c=fgetc(f);
    fseek(f,2,SEEK_CUR);
    fread(sir,sizeof(char),100,f);
    puts(sir);

    char *p;
    p=strchr(sir,c);
    while(p)
    {
        strcpy(p,p+1);
        p=strchr(sir,c);
    }
    fclose(f);

    f=fopen("ex1.txt","ab");
    if(f==NULL)
        printf("Eroare la deschiderea fisierului\n");
    fseek(f,0,SEEK_END);
    fwrite(sir,sizeof(char),strlen(sir),f);

    return 0;
}
