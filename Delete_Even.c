#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*Head != NULL)
    {
        newn->next = *Head;
    }
    *Head = newn;
}

void Display(PNODE Head)
{
    printf("Elements of linked list are : \n");
    while(Head != NULL)
    {
        printf("|%d|-> ",Head->data);
        Head = Head->next;
    }
    printf("NULL \n");
}

void DeleteEven(PPNODE Head)
{
    PNODE Second=NULL;
    PNODE First=NULL;
    PNODE temp=NULL;

    if(*Head==NULL)
    {
        return;
    }

    if((*Head)->next==NULL)
    {
        if((((*Head)->data) % 2)==0)
        {
            free(*Head);
            Head=NULL;
            return;
        }
        else
        {
            return;
        }
    }
    
    First=*Head;
    Second=(*Head)->next;

    while(Second!=NULL)
    {
        if((Second->data) % 2==0)
        {
            temp=Second;
            First->next=Second->next;
            free(temp);
            Second=First->next;
        }
        else
        {
            First=Second;
            Second=First->next;
        }
    }

    if(((*Head)->data)%2==0)
    {
        (*Head)=(*Head)->next;
        free(temp);
    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    // Even odd

    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,21);
    InsertFirst(&First,51);
    InsertFirst(&First,10);

    Display(First);

    DeleteEven(&First);
    Display(First);

    return 0; 

}
