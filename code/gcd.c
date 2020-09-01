//
//  gcd.c
//  
//
//  Created by DLRL on 01/12/19.
//

#include<stdio.h>

int gcd(int a, int b){
    if(a == 0)
        return b;
    else
        return gcd(b%a, a);
}

int main(){
    int a, b;
    printf("enter two numbers\n");
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
    return 0;
}
