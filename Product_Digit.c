//Write a Program which display product of all digit of all element from singly linear linked list(Dont consider 0)
//Output: 1  2  6  4


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
//////////////////////////////////////////////////////////////////////////////////////


int product(int iNo)
{
    int iDigit=0;
    int iMult=1;
   
       if(iNo==0)     //filter
       {
          return 1;
       }
        while(iNo!=0)   //opration on Digit
        {
            iDigit=iNo % 10;  
            iMult=iMult * iDigit; 
            iNo=iNo/10;
        }
       return iMult;
}

void DisplayProduct(PNODE Head)
{
    while(Head!=NULL)   //opration on linked list
    {
        int iRet=0;
        iRet=product(Head->Data);
        printf("%d\t",iRet);
        Head=Head->Next;
    }
}
////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE First=NULL;
   
    InsertFirst(&First,41);
    InsertFirst(&First,32);
    InsertFirst(&First,20);
    InsertFirst(&First,11);

    Display(First);

    DisplayProduct(First);

    return 0;
}
