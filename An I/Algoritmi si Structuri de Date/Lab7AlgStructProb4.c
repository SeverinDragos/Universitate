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

void SRD(struct node *p,int k1,int k2)
{
    if(p != NULL)
    {
        SRD(p->left,k1,k2);
        if(k1 <= p->info && k2 >= p->info)
        printf("%d ",p->info);
        SRD(p->right,k1,k2);
    }
}

int main()
{
    int n,i,k1,k2;
    printf("Numarul de elemente: ");
    scanf("%d",&n);
    printf("Introduceti capetele de interval: ");
    scanf("%d",&k1);
    scanf("%d",&k2);
    for(i=1;i<=n;i++)
        Adaugare();
    SRD(Root,k1,k2);
    return 0;
}
