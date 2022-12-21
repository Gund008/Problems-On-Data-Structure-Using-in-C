
//Write a Program Which display all elements which are pallindrome from singly linear linked list.
//Output: 11 6 414

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

int pallindrome(int iNo)
{
    int iRev=0;
    int iDigit=0;
    int iTemp=iNo;

        while(iNo!=0)
          {
            iDigit=iNo % 10;
            iRev=(iRev * 10)+iDigit;
            iNo=iNo/ 10;
          }
        return(iTemp==iRev);
}

void DisplayPallindrom(PNODE Head)
{
    while(Head!=NULL)
    {
        int iRet=0;
        iRet=pallindrome(Head->Data);
        if(iRet==1)  
        {
            printf("%d\t",Head->Data);
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
    InsertFirst(&First,414);
    InsertFirst(&First,17);
    InsertFirst(&First,28);
    InsertFirst(&First,11);

    Display(First);

    DisplayPallindrom(First);   //call by value

    return 0;
}