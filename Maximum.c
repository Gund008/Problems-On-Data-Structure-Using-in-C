//Write a Program which returns Largest element from singly liear linked list.
//Output-320

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

int Maximum(PNODE Head)
{
    int iMax=Head->Data;
    while(Head!=NULL)
    {
       if(Head->Data > iMax) 
       {
          iMax=Head->Data;
       } 
        Head=Head->Next;
    }
    return iMax;

}
/////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE First=NULL;
    int iRet=0;
   
    InsertFirst(&First,240);  //Call by Address
    InsertFirst(&First,320);
    InsertFirst(&First,230);
    InsertFirst(&First,110);
  
    Display(First);
    
    iRet=Maximum(First);  //call by value
    printf("Largest element is:%d\n",iRet);

    return 0;
}
