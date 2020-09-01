//
//  power.c
//  
//
//  Created by DLRL on 01/12/19.
//

#include<stdio.h>
#include<math.h>
int main()
{
    int x;
    int y;
    int result;
    printf("Enter the value of x\n");
    scanf("%d",&x);
    printf("Enter the value of y\n");
    scanf("%d",&y);
    result = pow(x,y);
    printf("result=%d\n",result);
    return 0;
}
