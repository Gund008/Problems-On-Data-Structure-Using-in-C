//Write a Program which returns Addtion of all element from singly liear linked list.
//Output-100

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
/////////////////////////////////////////////////////////////////////////////////////////

int Addtion(PNODE Head)
{
    PNODE temp=Head;
    int iSum=0;

    while(temp!=NULL)
    {
        iSum=iSum + (temp->Data);
        temp=temp->Next;
    }
    return iSum;
}

/////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE First=NULL;
    int iValue=0;
    int iRet=0;
   
    InsertFirst(&First,40);  //Call by Address
    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,10);
  
    Display(First);
    
    iRet=Addtion(First);  //call by value
    printf("Addtion is:%d\n",iRet);

    return 0;
}
