//Write a program which display smallest digits of all element from singly linear linked list.
//Output:1  0  2  1


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

void DisplaySmall(PNODE Head)
{
    int iMin=9;
    int iDigit=0;

    while(Head!=NULL)
    {
        while(Head->Data!=0)
        {
            iDigit=Head->Data % 10;
            if(iDigit < iMin)
            {
                iMin=iDigit;
            }  
            Head->Data=Head->Data / 10;
        }
        printf("%d\t",iMin);
        Head=Head->Next;    
    }
}
////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE First=NULL;

    InsertFirst(&First,415);
    InsertFirst(&First,532);
    InsertFirst(&First,250);
    InsertFirst(&First,11);

    Display(First);

    DisplaySmall(First);

    return 0;
}