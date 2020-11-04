//
//  Median and Kth smallest number.c
//  
//
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long int n1,n2,k1,j,k;             /* Here we have initialised */
    scanf("%lld%lld%lld",&n1,&n2,&k1);
    long long int med,x,i;
    long long int a[100005],b[100005];
    for(i=0;i<n1;i++)
        scanf("%lld",&a[i]);
    for(i=0;i<n2;i++)
        scanf("%lld",&b[i]);
    for(i=0,j=0,k=0;i<(n1+n2);i++){         /* Here we are merging two sorted arrays */
        if(i==(k1-1)) {
        if(a[j]<b[k])     /* In k1-1 position We check if the elements in two sorted arrays.Hence,We print smallelement*/
                x=a[j];
            else
                x=b[k];
        }
        if(i==((n1+n2-1)/2)) {      /* Median of the two sorted arrays */
            if(a[j]<b[k])
                med=a[j];
            else
                med=b[k];
        }
        if(a[j]<b[k])               /* We are incrementing j */
            j++;
        else
            k++;                    /* We are incrementing k */
    }
    printf("Median is %lld\n",med);
    printf("Kth Smallest is %lld",x);
    return 0;
}
