#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sterg(char *p,int poz,int cate)
{
    strcpy(p+poz,p+poz+cate);
    return p;
}

char *inserez(char *p, char *s,int poz)
{
    int L=strlen(s),i;
    strcat(s,p+poz);
    for(i=L-1;i<strlen(s)-1;i++)
    {
        s[i]=s[i+1];
    }
    strcpy(p+poz,s);
    return p;
}

void inlocuire(char *p,char *s,char *text)
{

}

void Cuvinte(char *s)
{
    char *p=strtok(s," ,.;:");
    while(p != NULL)
    {
        fputs(p,stdout);
        printf("\n");
        p=strtok(NULL," ,.;:");
    }
}

int main()
{
    char s[50],*p,s2[50],s3[200],choice;
    int poz,cate;
    printf("Alegeti ce subpunct sa fie executat:\na)\nb)\nc)\nd)\n");
    do
        {
            scanf("%c",&choice);
            switch(choice)
            {
                case 'a':
                        printf("Sirul initial:\n");
                        getchar();
                        fgets(s,50,stdin);
                        printf("Sa se stearga de pe pozitia:");
                        scanf("%d",&poz);
                        printf("Cate caractere:");
                        scanf("%d",&cate);
                        p=sterg(s,poz,cate);
                        fputs(p,stdout);
                        break;
                case 'b':
                        printf("Sirul initial:\n");
                        getchar();
                        fgets(s,50,stdin);
                        printf("Sirul ce trebuie inserat:\n");
                        fgets(s2,50,stdin);
                        printf("Pozitia:");
                        scanf("%d",&poz);
                        p=inserez(s,s2,poz);
                        fputs(p,stdout);
                        break;
                case 'c':
                        printf("Cuvantul cautat: ");
                        getchar();
                        fgets(s,50,stdin);
                        printf("Cuvantul cu care sa fie inlocuit: ");
                        fgets(s2,50,stdin);
                        printf("Textul:\n");
                        fgets(s3,200,stdin);
                        inlocuire(s,s2,s3);
                        fputs(s3,stdout);
                        break;
                case 'd':
                        printf("Fraza data:\n");
                        getchar();
                        fgets(s3,200,stdin);
                        Cuvinte(s3);
            }
        }while(choice >= 'a' && choice <= 'd');
    return 0;
}
