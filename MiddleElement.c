/*
Write a Program which search Last occurence of particular elemet from singly linear linked list.
Function should return position at which element is found

Input:30
Output:6

*/

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

int MiddleElement(PNODE Head)
{
    int iSize = 0;
    int i = 0;
    PNODE temp = Head;

    while(Head != NULL)
    {
        iSize++;
        Head = Head->Next;
    }
    Head = temp;

    for(i = 0; i < iSize/2; i++)
    {
        Head = Head->Next;
    }
    return Head->Data;
}

//////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    PNODE First=NULL;
    int iValue=0;
    int iRet=0;

    InsertFirst(&First,70);
    InsertFirst(&First,30);
    InsertFirst(&First,50);
    InsertFirst(&First,40);
    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,10);

    Display(First);
  
    iRet=MiddleElement(First); 
    printf("Middle Element:%d\n",iRet);

    return 0;
}
