//Write a Program which display all Pallindrome elements of singly linked list
//Output-11 6 414


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

void DisplayPallindrome(PNODE Head)
{
    int iRev=0;
    int iDigit=0;

    while(Head!=NULL)
    {
        while(Head->Data!=0)
        {
            iDigit=Head->Data % 10;
            iRev=(iRev * 10 ) + iDigit;
            Head->Data=Head->Data /10;
        }
        if(Head->Data==iRev)
        {
            printf("%d\t",iRev);
        }  
        Head=Head->Next; 
    }
}
       
///////////////////////////////////////////////////////////////////////////////////////
int main()
{
    PNODE First=NULL;
   
    InsertFirst(&First,89);
    InsertFirst(&First,6);
    InsertFirst(&First,414);
    InsertFirst(&First,17);
    InsertFirst(&First,28);
    InsertFirst(&First,11);

    Display(First);

    DisplayPallindrome(First);

    return 0;
}