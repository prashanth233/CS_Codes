//
//  main.c
//  euilertotient
//
//  Created by DLRL on 30/08/20.
//  Copyright © 2020 DLRL. All rights reserved.
//

#include <stdio.h>
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int phi(unsigned int n)
{
    unsigned int result = 1;
    for (int i = 2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int i=0;i<t;i++)
    {
        int n,i;
        scanf("%d",&n);
        while((i=2)){
        printf("%d\n",phi(n));
        i++;
        break;}

    }
    
    return 0;
}


