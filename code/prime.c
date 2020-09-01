//
//  prime.c
//  
//
//  Created by DLRL on 01/12/19.
//
#include <stdio.h>
#include <math.h>
int prime(int a)
{
    for(int i = 2; i < sqrt(a); i++)
    {
        if(a % i == 0)
        {
            if(a % 2 == 0)
                return prime(a + 1);
            else
                return prime(a + 2);
        }
    }
    return a;
}
int nextprime(int a)
{
    return prime(a + 1);
}
int main(){
    int a;
    scanf("%d", &a);
    printf("%d", nextprime(a));
    return 0;
}
