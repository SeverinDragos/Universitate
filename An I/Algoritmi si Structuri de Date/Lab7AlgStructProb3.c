#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
}*Root=NULL;

void Adaugare()
{
    int val;
    printf("Se introduce valoarea: ");
    scanf("%d",&val);
    if(Root == NULL)
    {
        struct node *nou=(struct node*)malloc(sizeof(struct node));
        nou->info=val;
        nou->left=NULL;
        nou->right=NULL;
        Root=nou;
    }
    else
    {
        struct node *p=Root,*q=NULL;
        while(p != NULL)
        {
            q=p;
            if(val < p->info)   p=p->left;
            else
            if(val > p->info)   p=p->right;
        }
        struct node* nou=(struct node*)malloc(sizeof(struct node));
        nou->info=val;
        nou->left=NULL;
        nou->right=NULL;
        if(q->info < nou->info)   q->right=nou;
        else
        if(q->info > nou->info)   q->left=nou;
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

int main()
{
    int n,i;
    printf("Numarul de elemente: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        Adaugare();
    SRD(Root);
    return 0;
}
