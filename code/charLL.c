//
//  charLL.c
//  
//
//  Created by DLRL on 30/11/19.
//

#include<stdio.h>
#include<stdlib.h>
struct listnode{
    char data;
    struct listnode *nextptr;
};
typedef struct listnode Listnode;
typedef Listnode *Listnodeptr;
void insert(Listnodeptr *sptr,char value)
{
    Listnodeptr newptr;
    Listnodeptr previousptr;
    Listnodeptr currentptr;
    newptr = malloc(sizeof(Listnode));
    if(newptr!=NULL){
        newptr->data = value;
        newptr->nextptr = NULL;
        previousptr = NULL;
        currentptr = *sptr;
        while (currentptr!=NULL) {
            previousptr = currentptr;
            currentptr = currentptr->nextptr;
        }
        if(previousptr==NULL){
            newptr->nextptr = *sptr;
            *sptr=newptr;
        }
        else{
            previousptr->nextptr=newptr;
            newptr->nextptr=currentptr;
        }
    }
    else{
        printf("%c not inserted. No memory available\n",value);
    }
}
void printList( Listnodeptr currentPtr )
{
 puts( "The list is:" );
 while ( currentPtr != NULL ) {
 printf( "%c --> ", currentPtr->data );
 currentPtr = currentPtr->nextptr;
 }
 puts( "NULL\n" );
 }
int main(void)
{
    Listnodeptr start=NULL;
    FILE *cfptr;
    char ch;
    if((cfptr = fopen("sentence.txt", "r"))==NULL)
                      {
                      puts("File could not be opened");
}
        while (!feof(cfptr))
           {
               ch = fgetc(cfptr);
               if(!feof(cfptr)) insert(&start,ch);
           }
           fclose(cfptr);
           printList(start);
    }
