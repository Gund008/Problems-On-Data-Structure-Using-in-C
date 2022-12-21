//Write a program which display smallest digits of all element from singly linear linked list.
//Output:1  0  2  1


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

int Small(int iNo)
{
    int iMin=9;
    int iDigit=0;

        while(iNo!=0)
        {
            iDigit=iNo % 10;
            if(iDigit < iMin)
            {
                iMin=iDigit;
            }  
            iNo=iNo / 10;
        }
        return iMin;
}

void DisplaySmall(PNODE Head)
{
    while(Head!=NULL)
    {
        int iRet=0;
        iRet=Small(Head->Data);
        printf("%d\t",iRet);
        Head=Head->Next;
    }

}
////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE First=NULL;

    InsertFirst(&First,415);
    InsertFirst(&First,532);
    InsertFirst(&First,250);
    InsertFirst(&First,11);

    Display(First);

    DisplaySmall(First);

    return 0;
}