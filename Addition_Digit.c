//Write a Program which Display Addition of Digits of  elements from singly linear linked list.
//Output-2  5  2  6 10


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
///////////////////////////////////////////////////////////////////////////////////////

void DisplayDigit(PNODE Head)
{
   PNODE temp=Head; 
   int iDigit=0;
   int iSum=0;
   
   while(Head!=NULL)
   { 
        while(Head->Data!=0)
        {
           iDigit=Head->Data % 10;
           iSum=iSum + iDigit;
           Head->Data=Head->Data / 10;
        }
        printf("%d\t",iSum);
        Head=Head->Next;
     
    }  
}

////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE First=NULL;
   
    InsertFirst(&First,640);
    InsertFirst(&First,240);
    InsertFirst(&First,20);
    InsertFirst(&First,230);
    InsertFirst(&First,110);

    Display(First);

    DisplayDigit(First);


    return 0;
}