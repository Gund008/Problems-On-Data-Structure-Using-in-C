/*
Write a Program which search first occurence of particular elemet from singly linear linked list.
Function should return position at which element is found

Input:30
Output:3

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

int SearchFirstOcc(PNODE Head,int no)
{
    PNODE temp=Head;
    int iPos=0;
    while(temp!=NULL)
    {
       if(temp->Data==no)
       {
         iPos=iPos+1;
         break;
       }
       iPos++;
       temp=temp->Next;
    }
    return iPos;
}

////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    PNODE First=NULL;
    int iValue=0;
    int iRet=0;

    InsertFirst(&First,70);
    InsertFirst(&First,60);
    InsertFirst(&First,50);
    InsertFirst(&First,40);
    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,10);

    Display(First);
    printf(" Please Enter the first Occurence of Element:\n");
    scanf("%d\n",&iValue);

    iRet=SearchFirstOcc(First,iValue); //Call by value
    printf("Position:%d\n",iRet);


    return 0;
}
