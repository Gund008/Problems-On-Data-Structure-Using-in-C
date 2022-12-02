//Write a Program Which display all elements which are perfect from singly linear linked list.
//Output: 6 28

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

void DisplayPerfect(PNODE Head)
{
    int iCnt=0,iSum=0;
  
    while(Head!=NULL)       //To travel linked list
    {
            for(iCnt=1;iCnt<=Head->Data;iCnt++)     //perfect check
            {
              if((Head->Data % iCnt)==0)
               {
                iSum=iSum + iCnt;
               }
            }
            if(iSum==Head->Data)
              {
                printf("%d\t",iSum);
              }
            Head=Head->Next;         
    }
}
////////////////////////////////////////////////////////////////////////////////////////
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

    DisplayPerfect(First);

    return 0;
}