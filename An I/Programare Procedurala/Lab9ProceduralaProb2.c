#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f;
    f=fopen("ex2.txt","rb");
    if(f == NULL)
        printf("Eroare la deschiderea fisierului\n");

    char litera,inlocuitor,*sir=(char*)calloc(100,sizeof(char));
    litera=fgetc(f);
    fseek(f,1,SEEK_CUR);
    inlocuitor=fgetc(f);
    fseek(f,2,SEEK_CUR);
    fread(sir,sizeof(char),100,f);

    char *p;
    p=strchr(sir,litera);
    while(p)
    {
        p[0]=inlocuitor;
        p=strchr(sir,litera);
    }
    fclose(f);

    f=fopen("ex2.txt","wb");
    fwrite(sir,sizeof(char),strlen(sir),f);
    fclose(f);

    return 0;
}
