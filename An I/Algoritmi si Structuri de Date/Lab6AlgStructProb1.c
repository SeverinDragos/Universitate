#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start=NULL;

void AdaugareInceput()
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    printf("Adaugam la inceput valoarea:\n");
    scanf("%d",&p->info);
    p->next=start;
    p->prev=NULL;
    if(start != NULL)   start->prev=p;
    start=p;

}

void AdaugareFinal()
{
    struct node* nou=(struct node*)malloc(sizeof(struct node));
    if(start==NULL)
    {
    printf("Adaugam la final valoarea:\n");
    scanf("%d",&nou->info);
    nou->prev=NULL;
    nou->next=NULL;
    start=nou;
    }
    else
    {
    struct node *p=start;
    while(p->next != NULL)
            p=p->next;
    printf("Adaugam la final valoarea:\n");
    scanf("%d",&nou->info);
    p->next=nou;
    nou->prev=p;
    nou->next=NULL;
    }
}

void AdaugarePePozitie()
{
    int poz,c=1;
    printf("Sa se adauge pe pozitia (Considerate de la 1 la n): \n");
    scanf("%d",&poz);
    if(poz == 1)
    {
        struct node *p=(struct node*)malloc(sizeof(struct node));
        printf("Adaugam valoarea:\n");
        scanf("%d",&p->info);
        p->next=start;
        p->prev=NULL;
        if(start != NULL)   start->prev=p;
        start=p;
    }
    else
    {
    struct node *p=start;
    while(p != NULL && c<poz)
    {
        p=p->next;
        c++;
    }
    if(p == NULL)
    {
    if(c < poz)
        printf("Nu se poate adauga pe pozitia data\n");
    else
    if(c == poz)
    {
        struct node *q=start,*nou=(struct node*)malloc(sizeof(struct node));
        while(q->next != NULL)
            q=q->next;
        printf("Adaugam valoarea:\n");
        scanf("%d",&nou->info);
        q->next=nou;
        nou->prev=q;
        nou->next=NULL;

    }
    }
    else
    {
        struct node *p1=p->prev,*nou=(struct node*)malloc(sizeof(struct node));
        printf("Adaugam valoarea:\n");
        scanf("%d",&nou->info);
        nou->next=p;
        p->prev=nou;
        nou->prev=p1;
        p1->next=nou;
    }
    }
}

void AfisareInOrdine()
{
    if(start == NULL) printf("Lista este vida\n");
    else
    {
    struct node *p=start;
    while(p->next != NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
    printf("%d\n",p->info);
    }
}

void AfisareInOrdineInversa()
{
    if(start == NULL) printf("Lista este vida\n");
    else
    {
    struct node *p=start;
    while(p->next != NULL)
        p=p->next;
    while(p!= NULL)
    {
        printf("%d ",p->info);
        p=p->prev;
    }
    printf("\n");
    }
}
void StergereDupaValoare()
{
    int val;
    printf("Sa se stearga elementul cu valoarea:\n");
    scanf("%d",&val);
    struct node *p=start;
    while(p != NULL )
    {
        if(p->info == val)
        {
            struct node *p1=p->prev,*p2=p->next;
            if(p1 != NULL)   // tratat ultimul si primul element
            p1->next=p->next;
            if(p2 != NULL)
            p2->prev=p->prev;
            if(start == p)
            start=p->next;
            free(p);
            break;
        }
        p=p->next;
    }
    if(p == NULL)
        printf("Nu s-a gasit elementul cu valoarea %d\n",val);
}

void StergereDupaPozitie()
{
    int poz,c=1;
    printf("Sa se stearga elementul de pe pozitia (Considerate de la 1 la n): \n");
    scanf("%d",&poz);
    struct node *p=start;
    while(p != NULL && c<poz)
    {
        p=p->next;
        c++;
    }
    if(p == NULL)
        printf("Pozitia data nu se afla in lista\n");
    else
    {
        struct node *p1=p->prev,*p2=p->next; // nu ex ->next, e null
        if(p1 != NULL)
        p1->next=p->next;
        if(p2 != NULL)
        p2->prev=p->prev;
        if (poz == 1)   start=p->next;
        free(p);
    }
}
int main()
{
    int choice;
    printf("Alegeti una din urmatoarele operatii:\nAdaugarea la inceputul listei: 1\nAdaugarea la finalul listei: 2\nAdaugarea pe pozitie: 3\nAfisarea in ordine: 4\nAfisarea in ordine inversa: 5\nStergerea dupa pozitie (de la 1 la n): 6\nStergerea dupa valoare:7\nIesirea din executie: 0\n");
    do
    {
        printf("Sa se execute operatia: ");
        scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            AdaugareInceput();
            AfisareInOrdine();
            break;
        case 2:
            AdaugareFinal();
            AfisareInOrdine();
            break;
        case 3:
            AdaugarePePozitie();
            AfisareInOrdine();
            break;
        case 4:
            AfisareInOrdine();
            break;
        case 5:
            AfisareInOrdineInversa();
            break;
        case 6:
            StergereDupaPozitie();
            AfisareInOrdine();
            break;
        case 7:
            StergereDupaValoare();
            AfisareInOrdine();
            break;
    }
    }while(choice != 0);
    return 0;
}
