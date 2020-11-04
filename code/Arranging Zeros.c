//
//  Arranging Zeros.c
//  
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    int t;
    scanf("%d",&n);
    int count=0; /* Counting the number of occurences, initially it is zero */
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        if(t==0) count++; /* if zero occurs, count is incremented by one */
        else printf("%d ",t);  /* If there are no zeros, we are printing the string as it is */
    }
    for(int i=0;i<count;i++){
        printf("0 "); /* Hence, we are printing the zeros at the end of the string */
    }
    return 0;
}
