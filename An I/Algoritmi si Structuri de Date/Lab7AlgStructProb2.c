#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
}*Root=NULL;

int flag;

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

void Search(struct node *p,int val)
{
    if(p != NULL)
    {
        Search(p->left,val);
        if(p->info == val)  flag=1;
        Search(p->right,val);
    }
}

int FindMax()
{
    if(Root == NULL)
        printf("Arborele este vid\n");
    else
    {
    struct node *p=Root;
    while(p->right != NULL)
        p=p->right;
        return p->info;
    }
}

void Delete(int val)
{
    if(Root == NULL)
        printf("Arborele este vid\n");
    else
    {
        struct node *p=Root,*q=NULL;
        while(p->info != val)
        {
            q=p;
            if(val < p->info)   p=p->left;
            else
            if(val > p->info)   p=p->right;
            if(p == NULL) break;
        }
        if(p == NULL)   printf("Valoarea data nu se regaseste in arbore\n");
        else
        {
        if(p->left == NULL && p->right == NULL)
        {
            if(p->info < q->info)   q->left=NULL;
            else
            if(p->info > q->info)   q->right=NULL;
            free(p);
        }
        else
        if(p->left != NULL && p->right == NULL)
        {
            if(p->info < q->info)   q->left=p->left;
            else
            if(p->info > q->info)   q->right=p->left;
            free(p);
        }
        else
        if(p->left == NULL && p->right != NULL)
        {
            if(p->info < q->info)   q->left=p->right;
            else
            if(p->info > q->info)   q->right=p->right;
            free(p);
        }
        else
        if(p->left != NULL && p->right != NULL)
        {
            struct node *sterg=p;
            q=p;
            p=p->left;
            while(p->right != NULL)
            {
                q=p;
                p=p->right;
            }
            if(sterg == q)
            {
                q->left=p->left;
                sterg->info=p->info;
                free(p);
            }
            else
            {
                q->right=p->left;
                sterg->info=p->info;
                free(p);
            }
        }
        }
    }
}

int main()
{
    int choice,val;
    printf("Operatiile sunt:\nAdaugare: 1\nParcurgere SRD: 2\nCautare element: 3\nGasire maxim: 4\nStergere element: 5\nIesirea din executie: 0\n");
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
            printf("\n");
            break;
        case 3:
            printf("Se cauta valoarea: ");
            scanf("%d",&val);
            flag=0;
            Search(Root,val);
            printf("%d\n",flag);
            break;
        case 4:
            printf("%d\n",FindMax());
            break;
        case 5:
            printf("Sa se stearga nodul cu valoarea: ");
            scanf("%d",&val);
            Delete(val);
            break;
        }
    }while(choice);
    return 0;
}
