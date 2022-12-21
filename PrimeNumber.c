//Write a Program which display all elements which are prime from singly linear linked list.
//Output- 11  17  41 89


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

int Prime(int iNo)
{
    int iCnt=0;
        for(iCnt=2;iCnt<=iNo;iCnt++)
        {
           if((iNo % iCnt)==0)
           {
               break;
           }
        }
       return iCnt;
}

void DisplayPrime(PNODE Head)
{
      while(Head!=NULL)
      {
          int iRet=0;
          iRet=Prime(Head->Data);
          if(iRet==Head->Data)
          {
            printf("%d\t",iRet);
          }
          Head=Head->Next;
      }
}
///////////////////////////////////////////////////////////////////////////////////////
int main()
{
    PNODE First=NULL;
    int iRet=0;
   
    InsertFirst(&First,89);
    InsertFirst(&First,22);
    InsertFirst(&First,41);
    InsertFirst(&First,17);
    InsertFirst(&First,20);
    InsertFirst(&First,11);

    Display(First);

    DisplayPrime(First);
   

    return 0;
}