//
//  Integer expression evaluation.c
//  
//
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long int Expression(char str[],long long int index){
    static long long int count=0; /* We have declared static variable count */
    long long int val=0;long long int prod=1;
    while(index>=0 && str[index]<='9'&& str[index]>='0'){ /* Checking string is an integer or not */
        val+=(str[index]-'0')*prod;
        prod*=10;
        index--;
    }
    count++; /* Counting no.of recurrence */
    if(index<=0){
        printf("count=%lld\n",count);
        if(index==0) {
            printf("%lld\n",-val);
            return -val;
        }
        printf("%lld\n",val);
        return val;
    }
    long long int prev=Expression(str,index-1);
    if(index>=0&&str[index]=='-'){
   printf("%lld-%lld\n",prev,val); /* we are sub the integers */
        }
   else printf("%lld+%lld\n",prev,val); /* We are adding the integers */
    if(index>=0&&str[index]=='-')
    return prev-val;
    return prev+val;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char str[10000]; /* String length 10000 */
    scanf("%s",str);
    printf("answer=%lld",Expression(str,strlen(str)-1)); /* We are calling a function */
    return 0;
}
