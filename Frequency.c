
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

//////////////////////////////////////////////////////////////////////////////////////////

int Frequency(PNODE Head,int iNo)
{
    int iCnt=0;

    while(Head!=NULL)
    {
        if(Head->Data==iNo)
        {
            iCnt=iCnt + 1;
        }
        Head=Head->Next;
    }
    return iCnt;
}

//////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    PNODE First=NULL;
    int iValue=0;
    int iRet=0,iNo=0;

    InsertFirst(&First,70);
    InsertFirst(&First,30);
    InsertFirst(&First,50);
    InsertFirst(&First,40);
    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,10);

    Display(First);
  
    printf("Please Enter the Number:\n");
    scanf("%d",&iNo);

    iRet=Frequency(First,iNo); 
    printf("Frequency Of Element:%d\n",iRet);

    return 0;
}
