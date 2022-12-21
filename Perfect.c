//Write a Program Which display all elements which are perfect from singly linear linked list.
//Output: 6 28

#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<stdbool.h>


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

bool CheckPerfect(int iNo)
{
    int iCnt=0,iSum=0;
    int iTemp=iNo;

            for(iCnt=1;iCnt<=(iNo/2);iCnt++)    
            {
              if((iNo % iCnt)==0)
               {
                  iSum=iSum + iCnt;
               }
            }
           return(iTemp==iSum);
}

void DisplayPerfect(PNODE Head)
{
    while(Head!=NULL)
    {
        if(CheckPerfect(Head->Data)==true)   
        {
            printf("%d is a Perfect  Number:\n",Head->Data);
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

    DisplayPerfect(First);   //call by value

    return 0;
}