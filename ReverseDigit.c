//Write a Program which reverse each element of singly linked list.
//Output-11 82 71 14 6 98

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

int ChkDigit(int iNo)
{
    int iDigit=0;
    int iRev=0;

    while(iNo!=0)
    {
        iDigit=iNo % 10;
        iRev=(iRev * 10)+iDigit;
        iNo=iNo/ 10;
    }
    return iRev;
}

void Reverse(PNODE Head)
{
    PNODE temp=Head;
    while(temp!=NULL)
    {
        int iRet=0;
        iRet=ChkDigit(Head->Data);
        printf("%d\t",iRet);
        Head=Head->Next;
    }
}

//////////////////////////////////////////////////////////////////////////////////////
int main()
{
    PNODE First=NULL;
   
    InsertFirst(&First,89);
    InsertFirst(&First,6);
    InsertFirst(&First,41);
    InsertFirst(&First,17);
    InsertFirst(&First,28);
    InsertFirst(&First,11);
    
    Display(First);
    Reverse(First);  //call by value    
     
    return 0;
}