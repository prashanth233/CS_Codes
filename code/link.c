//
//  link.c
//  
//
//  Created by DLRL on 28/10/19.
//

#include "link.h"
#include<stdio.h>
#include<stdlib.h>
struct listNode
{
    char name[20];
    char organisation[20];
    unsigned long int number;
    char address[30];
    unsigned int pincode[10];
    char state[20];
    struct listNode *nextPtr;
};
struct List
{
    struct listNode start=NULL;
};
typedef struct listNode ListNode;
typedef struct listNode *ListNodePtr;
void insert(ListNodePtr *sPtr, struct listNode value );
void delete(ListNodePtr *sPtr, struct listNode value);
void updatenode(ListNodePtr *sPtr, struct listNode value);
void insert_bottom(ListNodePtr *sPtr, struct listNode value);
void findList(ListNodePtr *sPtr, struct listNode value);
void printList(ListNodePtr currentPtr);
void instructions(void);
int main(void)
{
    ListNodePtr startPtr=NULL;
    unsigned long int choice;
    char item;
    instructions();
    printf("%s","?");
    scanf("%lu",&choice);
    while (choice<=7) {
        switch (choice) {
            case 1:
                printf("%s","enter a character:");
                scanf("\n%c",&struct listNode);
                insert(&startPtr);
                printList(startPtr);
                break;
            case 2:
                if(!isempty(startPtr))
                {
                    printf("%s","Enter the character to be deleted:");
                    scanf("\n%c",&item);
                    if(delete(&startPtr, struct listNode))
                    {
                        printf("%c deleted.\n", struct listNode);
                        printList(startPtr);
                    }
                    else{
                        printf("%c not found.\n\n",struct listNode);
                    }
                }
                else
                {
                    puts("list is empty.\n");
                }
                break;
            case 3:
                if(!isempty(startPtr))
                {
                    printf("%s","Entered the character to be updated:");
                    scanf("\n%c",&struct listNode);
                    if (!isempty(startPtr))
                    {
                        printf("%c update.\n", struct listNode);
                        printList(startPtr);
                    }
                    else
                    {
                        printf("%c not found.\n\n",struct listNode);
                    }
                }
                break;
            case 4:
                printf("%lu","enter a number:");
                    scanf("\n%lu",&struct listNode);
                    insert(&startPtr);
                    printList(startPtr);
                    break;
            case 5:
                if(!isempty(startPtr))
                    {
                            printf("%lu","Enter the character to be deleted:");
                            scanf("\n%lu",&struct ListNode);
                            if(delete(&startPtr, struct ListNode)
                            {
                                printf("%lu deleted.\n", struct ListNode);
                                printList(startPtr);
                            }
                            else{
                                printf("%hhd not found.\n\n",struct ListNode);
                            }
                        }
                        else
                        {
                            puts("list is empty.\n");
                        }
                        break;
                    case 6:
                        if(!isempty(startPtr))
                        {
                            printf("%hhd"," to updatenode:");
                            scanf("\n%hhd",&struct listNode);
                            if (!isempty(startPtr))
                            {
                                printf("%hhd updatenode.\n", struct listNode);
                                printList(startPtr);
                            }
                            else
                            {
                                printf("%hhd not found.\n\n",struct listNode);
                            }
                        }
                        break;
            default:
                puts("Invalid choice.\n");
                instructions();
                break;
        }
        printf("%s","?");
        scanf("%lu",&choice);
    }
    puts("End of run.");
}
void instructions(void)
{
    puts("Enter your choice:\n"
         " 1 to insert an element into the list.\n"
         " 2 to delete an element from the list.\n"
         " 3 to update an element from the list.\n"
         " 4 to insert numbers into the list.\n"
         " 5 to delete numbers from the list.\n"
         " 6 to updatenode from the list.\n"
         " 7 to End.");
}
void insert(ListNodePtr *sPtr, struct listNode value )
         {
        ListNodePtr newPtr;
        ListNodePtr previousPtr;
        ListNodePtr currentPtr;
        newPtr= malloc(sizeof(ListNode));
        if (newPtr!=NULL)
        {
            newPtr->ListNode=value;
            newPtr->nextPtr=NULL;
            previousPtr=NULL;
            currentPtr=*sPtr;
            while(currentPtr!=NULL && value>currentPtr->ListNode)
            {
                previousPtr=currentPtr;
                currentPtr=currentPtr->nextPtr;
            }
            if (previousPtr==NULL)
            {
                newPtr->nextPtr=*sPtr;
                *sPtr=newPtr;
            }
            else
            {
                previousPtr->nextPtr=newPtr;
                newPtr->nextPtr=currentPtr;
            }
            }
        else
        {
            printf("%c%lu not inserted. No memory available.\n",ListNode);
        }
    }
                   if
                   void delete(ListNodePtr *sPtr, struct listNode value);
                   {
                ListNodePtr previousPtr;
                ListNodePtr currentPtr;
                ListNodePtr tempPtr;
                if (value==(*sPtr)->ListNode)
                {
                    tempPtr=*sPtr;
                    *sPtr=(*sPtr)->nextPtr;
                    free(tempPtr);
                    return value;
                }
                else
                {
                    previousPtr=*sPtr;
                    currentPtr=(*sPtr)->nextPtr;
                    while ( currentPtr!=NULL && currentPtr->ListNode!=value)
                    {
                        previousPtr=currentPtr;
                        currentPtr=currentPtr->nextPtr;
                    }
                    if(currentPtr!=NULL)
                    {
                        tempPtr=currentPtr;
                        previousPtr->nextPtr=currentPtr->nextPtr;
                        free(tempPtr);
                        return value;
                    }
                }
                return '\0';
            }
               void insert_bottom(ListNodePtr *sPtr,struct listNode value);
                      {
                      currentPtr=*sPtr;
                      nwPtr;
                      while(currentPtr!=NULL && currentPtr->nextPtr!=NULL)
                      {
                currentPtr=currentPtr->nextPtr;
            }
                      newPtr= malloc(sizeof(ListNode));
                      newPtr->ListNode=value;
                      newPtr->nextPtr=NULL;
                      if(currentPtr!=NULL)
                      currentPtr->nextPtr=newPtr;
                      else
                      head=newPtr;
                      return *sPtr;
                      }
                void findList(ListNode* first,ListNode* second)
                {
                ListNode* Ptr1=first, *Ptr2=second;
                if(first==NULL && second==NULL)
                    return true;
                if(first==NULL || first!=NULL && second==NULL)
                    return false;
                while(second!=NULL)
                {
                    Ptr2=second;
                    while(Ptr!=NULL)
                    {
                        if(Ptr2==NULL)
                            return false;
                        else if(Ptr1->ListNode==ptr2->ListNode)
                        {
                            Ptr1=Ptr1->next;
                            Ptr2=Ptr2->next;
                        }
                        else break;
                    }
                    if(Ptr1==NULL)
                        return true;
                    Ptr1=first;
                    second=second->next;
                }
                return false;
                }
                      void printlist(ListNodePtr currentPtr)
                      {
                if(isEmpty(currentPtr))
                {
                    puts("The list is empty.\n");
                }
                else
                {
                    puts("Th list is:");
                    while(currentPtr!=NULL)
                    {
                        printf(%c%Lu-->",currentPtr->ListNode);
                               currentPtr=currentPtr->nextPtr;
                    }
                               puts("NULL\n");
                }
            }
