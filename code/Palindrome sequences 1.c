//
//  Palindrome sequences 1.c
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    int count=0;
    char c[101];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",c);
        int l, r;  /* Left and Right end of the string */
        l=0;
        r=strlen(c)-1;
        int flag=0; /* We are assigning a boolean value */
        while(l<(strlen(c)/2)){ /* To check if 1st half matches second */
            if(c[l++]!=c[r--]){ printf("NO\n"); flag=1;break;} /* if the string are not equal we are printing as "NO" */
        }                                                      /* And we are breaking out of the loop */
        if(flag==0) { printf("YES\n"); count++;}
    }
    printf("Number of Palindromes: %d",count);
    return 0;
}
