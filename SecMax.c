//Write a Program which returns Second Maximum elements from singly linear linked list.
//Output-240

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int Data;
    struct node *Next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE Head,int no)
{
    PNODE newn=NULL;

    newn=(PNODE)malloc(sizeof(NODE));

    newn->Next=NULL;
    newn->Data=no;

    if(*Head==NULL)
    {
        *Head=newn;
    }
    else
    {
        newn->Next=*Head;
        *Head=newn;
    }
}
//////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE Head)
{
    while(Head!=NULL)
    {
        printf(" | %d |->",Head->Data);
        Head=Head->Next;
    }
    printf("NULL\n");
}

////////////////////////////////////////////////////////////////////////////////////////
int SecMaximum(PNODE Head)
{
    PNODE temp=Head;
    int iSecMax=0;

    while(temp->Next!=NULL)
    {
        temp=temp->Next;
    }
    iSecMax=temp->Data;
    return iSecMax;
   
}
///////////////////////////////////////////////////////////////////////////////////////
int main()
{
    PNODE First=NULL;
    int iRet=0;
   
    InsertFirst(&First,240);
    InsertFirst(&First,320);
    InsertFirst(&First,230);
    InsertFirst(&First,110);

    Display(First);

    iRet=SecMaximum(First);
    printf("Maximum elements:%d\n",iRet);

    return 0;
}