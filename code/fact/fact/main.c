//
//  main.c
//  fact
//
//  Created by DLRL on 31/08/20.
//  Copyright © 2020 DLRL. All rights reserved.
//

#include <stdio.h>
int multiply(int x,int a[],int size)
{
    int carry=0,i,p;
    
    for(i=0;i<size;++i)
    {
        p=a[i]*x+carry;
        a[i]=p%10;
        carry=p/10;
    }
        
    while(carry)
    {
        a[size]=carry%10;
        carry=carry/10;
        size++;
    }
        return size;
}
     
int main()
{
    int n,a[1000],i,size=1;
    a[0]=1;
    int t;
    scanf("%d",&t);
    for(int j=0;j<t;j++){
    scanf("%d",&n);
    for(i=2;i<=n;++i) {
        size=multiply(i,a,size);
    }
        
    for(i=size-1;i>=0;--i)
    {
        printf("%d",a[i]);
    }}
        
       return 0;
}
  

