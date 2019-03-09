#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f=fopen("Ex4.txt","rb");
    char *sir=(char*)calloc(200,sizeof(char)),*rez;
    int *aparitii=(int*)calloc(26,sizeof(int));
    fread(sir,sizeof(char),200,f);

    int i;
    for(i=0;i<strlen(sir);i++)
        if('a' <= sir[i] && sir[i] <= 'z')  aparitii[sir[i]-97]++;
        else    if('A' <= sir[i] && sir[i] <= 'Z')  aparitii[sir[i]-65]++;

    int max=0,PrimaAlocare=1,j=0;
    for(i=0;i<26;i++)
        {
            if(aparitii[i])
            {
            if(aparitii[i] > max)
            {
                if(PrimaAlocare)
                    PrimaAlocare=0;
                else
                    free(rez);

                rez=(char*)malloc(sizeof(char));
                j=0;
                rez[j++]=i+97;
                max=aparitii[i];
            }
            else
                if(aparitii[i] == max)
                {
                    char *aux=realloc(rez,sizeof(char)*j+1);
                    if(aux != NULL)
                        rez=aux;
                    else
                        printf("Spatiu insuficient in HEAP!\n");
                    rez[j++]=i+97;
                }
            }
        }

    if(j)
    {
        printf("Caracterele cu numar maxim de aparitii sunt:\n");
        for(i=0;i<j;i++)
            printf("%c ",rez[i]);
    }
    else
        printf("Fisierul nu contine litere!");
    fclose(f);


    return 0;
}
