//Write a Program which returns Smallest element from singly liear linked list.
//Output-20

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

int Minimum(PNODE Head)
{
    PNODE Temp=Head;
    int iMin=Temp->Data;
    while(Temp!=NULL)
    {
       if(Temp->Data < iMin) 
       {
          iMin=Temp->Data;
       } 
       Temp=Temp->Next;
    }
    return iMin;
    
}

/////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE First=NULL;
    int iValue=0;
    int iRet=0;
   
    InsertFirst(&First,640);
    InsertFirst(&First,240);  //Call by Address
    InsertFirst(&First,20);
    InsertFirst(&First,230);
    InsertFirst(&First,110);
  
    Display(First);
    
    iRet=Minimum(First);  //call by value
    printf("Smallest  element is:%d\n",iRet);

    return 0;
}
