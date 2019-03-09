#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*Front=NULL,*Rear=NULL;

void AdaugareInceput()
{
    struct node *nou=(struct node*)malloc(sizeof(struct node));
    printf("Adaugam la inceput valoarea:\n");
    scanf("%d",&nou->info);
    nou->next=Front;
    nou->prev=NULL;
    if(Front != NULL)   Front->prev=nou;
    else    Rear=nou;
    Front=nou;
}

void AdaugareFinal()
{
    struct node* nou=(struct node*)malloc(sizeof(struct node));
    if(Rear==NULL)
    {
    printf("Adaugam la final valoarea:\n");
    scanf("%d",&nou->info);
    nou->prev=NULL;
    nou->next=NULL;
    Rear=nou;
    Front=nou;
    }
    else
    {
    printf("Adaugam la final valoarea:\n");
    scanf("%d",&nou->info);
    Rear->next=nou;
    nou->prev=Rear;
    nou->next=NULL;
    Rear=nou;
    }
}

void StergereInceput()
{
    struct node *sterg=Front;
    if(Front == Rear)
    Rear=Rear->next;
    else    Front->next->prev=NULL;
    Front=Front->next;
    free(sterg);
}

void StergereFinal()
{
    struct node *sterg=Rear;
    if(Front == Rear)
    Front=Front->prev;
    else    Rear->prev->next=NULL;
    Rear=Rear->prev;
    free(sterg);
}

void AfisareInOrdine()
{
    if(Front == NULL) printf("Lista este vida\n");
    else
    {
    struct node *p=Front;
    while(p != NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
    printf("\n");
    }
}

int main()
{
    int choice;
    printf("Alegeti una din urmatoarele operatii:\nAdaugarea la inceputul listei: 1\nAdaugarea la finalul listei: 2\nStergerea de la inceput: 3\nStergerea de la final:4\nIesirea din executie: 0\n");
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
            StergereInceput();
            AfisareInOrdine();
            break;
        case 4:
            StergereFinal();
            AfisareInOrdine();
            break;
    }
    }while(choice != 0);
    return 0;
}
