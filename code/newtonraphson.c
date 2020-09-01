//
//  newtonraphson.c
//  
//
//  Created by DLRL on 02/12/19.
//


#include<stdio.h>
int main()
{
    float b,c;
    int a;
    printf("Enter the number \n");
    scanf("%d",&a);
    b=e;
    while(1)
    {
        c=(b+(a/b))/2;
        if((c-b)*(c-b)<0.0001)
        {
            break;
        }
        b=c;
    }
    printf("The root is %0.2f: \n",c);
    return 1;
}
