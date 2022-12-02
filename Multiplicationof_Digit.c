//Write a Program which display product of all digit of all element from singly linear linked list(Dont consider 0)
//Output: 1  2  6  4


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
//////////////////////////////////////////////////////////////////////////////////////

void DisplayProduct(PNODE Head)
{
    int iDigit=0;
    int iMult=1;
   
    while(Head!=NULL)
    {
        while(Head->Data!=0)
        {
            iDigit=Head->Data % 10;  
            iMult=iMult * iDigit; 
            Head->Data=Head->Data /10;
        }
        printf("%d\t",iMult);
        Head=Head->Next;
    }
   
}
////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE First=NULL;
   
    InsertFirst(&First,41);
    InsertFirst(&First,32);
    InsertFirst(&First,20);
    InsertFirst(&First,11);

    Display(First);

    DisplayProduct(First);

    return 0;
}