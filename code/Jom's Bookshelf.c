//
//  Jom's Bookshelf.c
//  
//
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int x=0;        /* Here x is the count, we have initialised it zero */
int n;          /* n is the length */
int a[1005];    /* We have initialised the array */

void bubble(int l,int r){           /* Birectional Bubble sort function */
    int i,j,temp;
    int swap=0;                     /* Swap is a boolean function */
    for(i=l;i<r;i++){               /* We are moving from left to right */
         if(a[i+1]<a[i]){           /* Comparing the elements */
             x++;                   /* Incrementing the count */
             temp=a[i+1];
             a[i+1]=a[i];
             a[i]=temp;             /* We are swapping the elements */
         }
    }
    for(j=r;j>l;j--){               /* We are moving from right to left */
        if(a[j-1]>a[j]){            /* We are following the same procedure, as I mentioned above */
             x++;                   /* Incrementing the count */
             temp=a[j-1];
             a[j-1]=a[j];
             a[j]=temp;
             swap=1;
         }
    }
    printf("bIndex = %d eIndex = %d first elem = %d last elem %d\n",l,r,a[l],a[r]);     /* We are printing the output */
    if(swap==1){
    bubble(l+1,r-1);}       /* Swap happens (if it's true), we are calling the function */
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bubble(0,n-1);          /* Calling the function */
    printf("numExchanges=%d\n",x);      /* Printing the number of exchanges,were as x gets incremented for every swap */
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
