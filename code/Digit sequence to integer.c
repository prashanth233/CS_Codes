//
//  Digit sequence to integer.c
//  
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char str[14]={0}; /* We need an empty string to store a number */
    int len=strlen(str);
    long int n=0; /* An integer number initialised to zero */
    scanf("%ld",&n);
    for(int i=0;i<len;i++) /* i(iteration) goes from zero to maximum length */
    {
        n=n+((str[len - (i + 1)] - '0') * pow(10, i));
    }
    printf("%ld",n);
    return 0;
}
