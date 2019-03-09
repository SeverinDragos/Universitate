#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left,*right;
}*Root=NULL;

void Adaugare()
{
    if(Root == NULL)
    {
        printf("Se adauga valoarea: ");
        struct node *nou=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&nou->info);
        nou->left=NULL;
        nou->right=NULL;
        Root=nou;
    }
    else
    {
        int flag=0;
        struct node *p=Root;
        while(flag == 0)
        {
        if(p->left == NULL)
        {
            struct node *nou=(struct node*)malloc(sizeof(struct node));
            p->left=nou;
            printf("Se adauga valoarea: ");
            scanf("%d",&nou->info);
            nou->left=NULL;
            nou->right=NULL;
            flag=1;
        }
        else
            if(p->right == NULL)
        {
            struct node *nou=(struct node*)malloc(sizeof(struct node));
            p->right=nou;
            printf("Se adauga valoarea: ");
            scanf("%d",&nou->info);
            nou->left=NULL;
            nou->right=NULL;
            flag=1;
        }
        else
        {
            struct node *q=p->left;
            if(q->left == NULL)
                p=q;
            else
                if(q->right == NULL)
                p=q;
            else
            {
                q=p->right;
                if(q->left == NULL)
                    p=q;
                else
                    if(q->right == NULL)
                    p=q;
                else q=p->left;
            }
        }
        }
    }
}

void SRD(struct node *p)
{
    if(p != NULL)
    {
        SRD(p->left);
        printf("%d ",p->info);
        SRD(p->right);
    }
}

void RSD(struct node *p)
{
    if(p != NULL)
    {
        printf("%d ",p->info);
        SRD(p->left);
        SRD(p->right);
    }
}

void SDR(struct node *p)
{
    if(p != NULL)
    {
        SRD(p->left);
        SRD(p->right);
        printf("%d ",p->info);
    }
}

int main()
{
    int choice;
    printf("Operatiile sunt:\nAdaugare: 1\nParcurgere SRD: 2\nParcurgere RSD: 3\nParcurgere SDR: 4\nIesirea din executie: 0\n");
    do
    {
        printf("Sa se execute operatia: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            Adaugare();
            break;
        case 2:
            SRD(Root);
            break;
        case 3:
            RSD(Root);
            break;
        case 4:
            SDR(Root);
            break;
        }
    }while(choice);
    return 0;
}
