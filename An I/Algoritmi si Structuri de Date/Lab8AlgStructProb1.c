#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info,bal;
    struct node *left,*right;
}*Root=NULL;

int max(int a,int b)
{
    if(a>=b)    return a;
    return b;
}

int min(int a,int b)
{
    if(a<=b)    return a;
    return b;
}

void SS(struct node *p,struct node *parinte)
{
    struct node *q=p->left;
    p->left=q->right;
    q->right=p;
    q->bal++;
    p->bal=-q->bal;

    if(parinte)
    {
        if(parinte->info < p->info)
            parinte->right=q;
        else
            parinte->left=q;
    }
    else
        Root=q;
}

void SD(struct node *p,struct node *parinte)
{
        struct node *q=p->left,*r=q->right;
        q->right=r->left;
        r->left=q;
        p->left=r->right;
        r->right=p;
        p->bal=-min(r->bal,0);
        q->bal=-max(r->bal,0);
        r->bal=0;

        if(parinte)
        {
            if(parinte->info < p->info)
                parinte->right=r;
            else
                parinte->left=r;
        }
        else
            Root=r;
}

void DD(struct node *p,struct node *parinte)
{
    struct node *q=p->right;
    p->right=q->left;
    q->left=p;
    q->bal--;
    p->bal=-q->bal;

    if(parinte)
    {
        if(parinte->info < p->info)
            parinte->right=q;
        else
            parinte->left=q;
    }
    else
        Root=q;
}

void DS(struct node *p,struct node *parinte)
{
    struct node *q=p->right,*r=q->left;
    q->left=r->right;
    r->right=q;
    p->right=r->left;
    r->left=p;
    p->bal=-max(r->bal,0);
    q->bal=-min(r->bal,0);
    r->bal=0;

    if(parinte)
        {
            if(parinte->info < p->info)
                parinte->right=r;
            else
                parinte->left=r;
        }
        else
            Root=r;
}

void Adaugare(struct node **p,struct node *parinte,int x,int *h)
{
    if((*p) == NULL)
    {
        (*p)=(struct node*)malloc(sizeof(struct node));
        (*p)->info=x;
        (*p)->bal=0;
        (*p)->left=NULL;
        (*p)->right=NULL;
        *h=1;
    }
    else
        if((*p)->info > x)
        {
            Adaugare(&((*p)->left),(*p),x,h);
            if(*h == 1)
            {
                (*p)->bal--;
                if((*p)->bal == 0) *h=0;
                if((*p)->bal == -2)
                {
                    if((*p)->left->bal == 1)    SD((*p),parinte);
                    else SS((*p),parinte);
                    *h=0;
                }
            }
        }
        else
        if((*p)->info < x)
        {
            Adaugare(&((*p)->right),(*p),x,h);
            if(*h == 1)
            {
                (*p)->bal++;
                if((*p)->bal == 0)  *h=0;
                if((*p)->bal == 2)
                {
                    if((*p)->right->bal == -1)  DS((*p),parinte);
                    else    DD((*p),parinte);
                    *h=0;
                }
            }
        }
}

void Stergere(struct node **p,struct node *parinte,int x,int *h)
{
    if((*p) == NULL)
    {
        printf("Elementul nu a fost gasit in arbore\n");
        *h=0;
    }
    else
    {
        if((*p)->info == x)
            {
                if((*p)->left == NULL && (*p)->right == NULL)
                {
                    if(parinte != NULL)
                    {
                    if(x < parinte->info)
                        parinte->left=NULL;
                    if(x >= parinte->info)
                        parinte->right=NULL;
                    free(p);
                    }
                    else
                    {
                    free(Root);
                    Root=NULL;
                    }
                    *h=1;
                }
                else
                if((*p)->left != NULL && (*p)->right == NULL)
                {
                    if(parinte != NULL)
                    {
                    if(x < parinte->info)
                        parinte->left=(*p)->left;
                    if(x >= parinte->info)
                        parinte->right=(*p)->left;
                    free(p);
                    }
                    else
                    {
                        Root=(*p)->left;
                        free(p);
                    }
                    *h=1;
                }
                else
                if((*p)->left == NULL && (*p)->right != NULL)
                {
                    if(parinte != NULL)
                    {
                    if(x < parinte->info)
                        parinte->left=(*p)->right;
                    if(x >= parinte->info)
                        parinte->right=(*p)->right;
                    free(p);
                    }
                    else
                    {
                        Root=(*p)->right;
                        free(p);
                    }
                    *h=1;
                }
                else
                {
                    struct node *mutat=(*p)->right;
                    while(mutat->left != NULL)
                        mutat=mutat->left;
                    (*p)->info=mutat->info;
                    Stergere(&((*p)->right),(*p),mutat->info,h);
                    if(*h == 1)
                    {
                    (*p)->bal--;
                    if((*p)->bal == -1) *h=0;
                    if((*p)->bal == -2)
                    {
                        if((*p)->left->bal == 0)    *h=0;
                        if((*p)->left->bal == 1)    SD((*p),parinte);
                        else SS((*p),parinte);
                    }
                    }
                }
                }
            else
            if((*p)->info > x)
            {
                Stergere(&((*p)->left),(*p),x,h);
                if(*h == 1)
                {
                    (*p)->bal++;
                    if((*p)->bal == 1)  *h=0;
                    if((*p)->bal == 2)
                    {
                        if((*p)->right->bal == 0)   *h=0;
                        if((*p)->right->bal == -1)  DS((*p),parinte);
                        else    DD((*p),parinte);
                    }
                }
            }
            else
            if((*p)->info < x)
            {
                Stergere(&((*p)->right),(*p),x,h);
                if(*h == 1)
                {
                    (*p)->bal--;
                    if((*p)->bal == -1) *h=0;
                    if((*p)->bal == -2)
                    {
                        if((*p)->left->bal == 0)    *h=0;
                        if((*p)->left->bal == 1)    SD((*p),parinte);
                        else SS((*p),parinte);
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
        if(p->left == NULL && p->right == NULL)
            printf("%d\n",p->info);
        else
            if(p->left != NULL && p->right == NULL)
            printf("%d S:(%d)\n",p->info,p->left->info);
            else
                if(p->right != NULL && p->left == NULL)
            printf("%d D:(%d)\n",p->info,p->right->info);
            else
        printf("%d S:(%d) D:(%d)\n",p->info,p->left->info,p->right->info);
        SRD(p->right);
    }
}

int Cautare(struct node *p,int x)
{
    if(p == NULL)
        return 0;
    else
    {
        if(p->info < x) return 0+Cautare(p->right,x);
        if(p->info > x) return 0+Cautare(p->left,x);
        if(p->info == x)    return 1;
    }
}

struct node *Maxim(struct node *p)
{
    if(p != NULL)
    if(p->right != NULL) Maxim(p->right);
    else
        return p;
    else return NULL;
};
int main()
{
    int x,h,choice,caut;
    struct node *maximul=NULL;
    printf("Operatiile sunt:\nAdaugare: 1\nCautare: 2\nMaxim: 3\nStergere: 4\nAfisare: 5\nIesirea din executie: 0\n");
    do
    {
        printf("Sa se execute operatia: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Se adauga valoarea: ");
            scanf("%d",&x);
            h=0;
            Adaugare(&Root,NULL,x,&h);
            SRD(Root);
            break;
        case 2:
            printf("Se cauta valoarea: ");
            scanf("%d",&x);
            caut=Cautare(Root,x);
            if(caut)    printf("Elementul a fost gasit\n");
            else    printf("Elementul nu se gaseste in arbore\n");
            break;
        case 3:
            maximul=Maxim(Root);
            if(maximul != NULL)
            printf("Maximul este %d\n",maximul->info);
            else
            printf("Arborele este null\n");
            break;
        case 4:
            printf("Se sterge valoarea: ");
            scanf("%d",&x);
            h=0;
            Stergere(&Root,NULL,x,&h);
            SRD(Root);
            break;
        case 5:
            SRD(Root);
            break;

        }
    }while(choice);
    return 0;
}
