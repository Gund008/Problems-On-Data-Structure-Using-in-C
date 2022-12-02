//Write a program which display largest Digit of all elements from singly linear linked list.
//Output:1  5  5  9


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

void DisplayLarge(PNODE Head)
{
    int iMax=0;
    int iDigit=0;

    while(Head!=NULL)   //travel linked list
    {
        while(Head->Data!=0)   //digit 
        {
            iDigit=Head->Data % 10;
            if(iDigit > iMax)
            {
                iMax=iDigit;
            }
            Head->Data=Head->Data / 10;
        }
        printf("%d\t",iMax);
        Head=Head->Next;
        
    }

}
////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE First=NULL;
   
    InsertFirst(&First,419);
    InsertFirst(&First,532);
    InsertFirst(&First,250);
    InsertFirst(&First,11);

    Display(First);

    DisplayLarge(First);  //Call by value

    return 0;
}