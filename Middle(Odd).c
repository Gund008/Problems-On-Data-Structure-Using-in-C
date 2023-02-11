#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First,int no)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;

    if(*First==NULL)     //if linked list empty
    {
        *First=newn;
    }
    else
    {
         newn->next=*First;
        *First=newn;       
    }   
}

////////////////////////////////////////////////////////////////////////////////////////////


void Display(PNODE First)
{
    printf("Elements from the linked list are:\n");

    while(First!=NULL)
    {
        printf("| %d |->",First->data);
        First=First->next;
    }
    printf("NULL\n");
}

///////////////////////////////////////////////////////////////////////////////////////

int SearchLastOcc(PNODE First,int no)
{
    int iCnt=1;
    int iPos=-1;

    while(First!=NULL)
    {
        if(First->data==no)
        {
            iPos=iCnt;
        }
        First=First->next;
        iCnt++;
    }
    if(iPos==-1)
    {
        return -1;
    }
    else
    {
        return iPos;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////

int MiddleElement(PNODE First)
{
    PNODE Student=First;
    PNODE Teacher=First;

    while(Teacher->next!=NULL)   //odd
    {
        Teacher=Teacher->next->next;
        Student=Student->next;
    }
    return (Student->data);
}


///////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE Head=NULL;
    int iRet=0;

    InsertFirst(&Head,151);
    InsertFirst(&Head,121);
    InsertFirst(&Head,111);
    InsertFirst(&Head,101);
    InsertFirst(&Head,51);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);

    Display(Head);
    
    iRet=SearchLastOcc(Head,101);

    if(iRet==-1)
    {
        printf("there is no Such Elements inLL:\n");
    }
    else
    {
        printf("Elements is There at index:%d\n",iRet);
    }
  
    return 0;

}