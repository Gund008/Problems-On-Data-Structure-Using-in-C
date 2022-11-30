//Write a Program which returns addtion of all even elements from singly linear linked list.
//Output-52


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

int AddtionEven(PNODE Head)
{
    int iEvenSum=0;
    while(Head->Next!=NULL)
    {
        if((Head->Data % 2)==0)
        {
            iEvenSum=iEvenSum + Head->Data;
        }
        Head=Head->Next;
    }
    return iEvenSum;
}
///////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE First=NULL;
    int iRet=0;

   
    InsertFirst(&First,41);
    InsertFirst(&First,32);
    InsertFirst(&First,20);
    InsertFirst(&First,11);

    Display(First);

    iRet=AddtionEven(First);
    printf("Addition is:%d\n",iRet);

    return 0;
}