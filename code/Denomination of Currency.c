//
//  Denomination of Currency.c
//  
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long int N;  /* Here N is amount */
    long int n;  /* Here n is notes */
    /* Currency Denominations */
    int d[8]={500,100,50,20,10,5,2,1}; /* Array is 8 */
    scanf("%ld",&N);
    for(int i=0;i<8;i++)
    {
        n=N/d[i];  /* Dividing the amount with d[i] */
        if(n)
        {
            N=N-d[i]*n;
        }
        printf("Denomination is : %d and count is : %ld \n",d[i],n);
    }
    return 0;
}
