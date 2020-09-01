
//
//  students.c
//  
//
//  Created by DLRL on 01/12/19.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct listnode{
    char data[100];
    struct listnode *nextptr;
};
typedef struct listnode Listnode;
typedef Listnode *Listnodeptr;
void insert(Listnodeptr *sptr,char *value)
{
    Listnodeptr newptr;
    Listnodeptr previousptr;
    Listnodeptr currentptr;
    newptr = malloc(sizeof(Listnode));
    if(newptr!=NULL){
        strcpy(newptr->data,value);
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
        printf("%s not inserted. No memory available\n",value);
    }
}
void printList( Listnodeptr currentPtr )
{
 puts( "<Name>\t       <Hostel>\t        <Rollno>\t" );
 while ( currentPtr != NULL ) {
 printf( "%s --> ", currentPtr->data );
     printf("\n");
 currentPtr = currentPtr->nextptr;
 }
 puts( "NULL\n" );
 }
int main(void)
{
    Listnodeptr start=NULL;
    FILE *cfptr;
    char ch[100];
    ch[0]='\0';
    char temp;
    if((cfptr = fopen("data.txt","r"))==NULL)
                      {
                      puts("File could not be opened");
}
        while (!feof(cfptr))
           {
               if(fscanf(cfptr,"%c",&temp)){
               if(temp!='\n')
               {
                   strncat(ch,&temp,1);
                   
               }
               else{
                   if(!feof(cfptr)) insert(&start,ch);
                   ch[0]='\0';
                   
               }
               }
               
           }
           fclose(cfptr);
         printList(start);
    }
