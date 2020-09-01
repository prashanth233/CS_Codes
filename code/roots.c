//
//  roots.c
//  
//
//  Created by DLRL on 26/11/19.
//

#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    int b;
    int c;
    int d;
    int r1;
    int r2;
    int i;
    int r;
    printf("Enter the values to find the roots\n");
    scanf("%d%d%d",&a,&b,&c);
    d = b*b-4*a*c;
    if(d>0)
    {
        r1 = (-b+sqrt(b*b-4*a*c))/(2*a);
        r2 = (-b-sqrt(b*b-4*a*c))/(2*a);
        printf("r1=%d and r2=%d\n",r1,r2);
    }
    else if(d==0)
    {
        r1 = r2 = -b/(2*a);
        printf("r1=%d r2=%d\n",r1,r2);
    }
    else
    {
        r = -b/(2*a);
        i = sqrt(-d)/(2*a);
        printf("r1=%d+%di and r2=%d-%di\n",r,i,r,i);
    }
    return 0;
}
