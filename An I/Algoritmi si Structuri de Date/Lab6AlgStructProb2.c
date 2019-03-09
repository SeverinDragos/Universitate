#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info,prioritate;
    struct node *next;
}*start=NULL;

void Adaugare()
{
    printf("Prioritatea:");
    int prio;
    scanf("%d",&prio);
    if(start == NULL)
    {
        struct node *nou=(struct node*)malloc(sizeof(struct node));
        nou->prioritate=prio;
        printf("Valoarea:");
        scanf("%d",&nou->info);
        nou->next=NULL;
        start=nou;
    }
    else
    {
        struct node *p=start,*q=NULL;
        while(p != NULL)
        {
            if(prio < p->prioritate)
                break;
            q=p;
            p=p->next;
        }
        if(p == NULL)
        {
            struct node *nou=(struct node*)malloc(sizeof(struct node));
            nou->prioritate=prio;
            printf("Valoarea:");
            scanf("%d",&nou->info);
            q->next=nou;
            nou->next=NULL;
        }
        else
        {
            struct node *nou=(struct node*)malloc(sizeof(struct node));
            nou->prioritate=prio;
            printf("Valoarea:");
            scanf("%d",&nou->info);
            if(q==NULL)
            {
                nou->next=start;
                start=nou;
            }
            else
            {
                q->next=nou;
                nou->next=p;
            }
        }
    }
}


void Stergere()
{
    struct node *sterg=start;
    start=start->next;
    free(sterg);
}

void AfisareInOrdine()
{
    if(start == NULL) printf("Lista este vida\n");
    else
    {
    struct node *p=start;
    while(p != NULL)
    {
        printf("%d (%d) ",p->info,p->prioritate);
        p=p->next;
    }
    printf("\n");
    }
}

int main()
{
    int choice;
    printf("Alegeti una din urmatoarele operatii:\nAdaugare: 1\nStergere: 2\nIesirea din executie: 0\n");
    do
    {
        printf("Sa se execute operatia: ");
        scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            Adaugare();
            AfisareInOrdine();
            break;
        case 2:
            Stergere();
            AfisareInOrdine();
            break;
    }
    }while(choice != 0);
    return 0;
}
