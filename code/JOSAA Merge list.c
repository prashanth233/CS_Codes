//
//  JOSAA Merge list.c
//  
//
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef long long int ll;

int main() {
    ll a[200010],b[200010],c[200010],d[600010];
    ll x=0,y=0,z=0,temp;
    ll i=0,j=0,k=0,l=0,m=2;  /* We have initialise m=2 to implement (1) */
    char ignore;            /* Read till we encounter a new line --> (1) */
    for(;;x++) {
        if(x==0)
        {
            scanf("%lld",&temp);
            a[0]=temp;
        }
        else{
        m=scanf("%lld%1[^\n]s",&a[x],&ignore);
        }
        if(m!=2)
        break;
    }
    
    for(;;y++) {
        m=scanf("%lld%1[^\n]s",&b[y],&ignore);
        if(m!=2)
        break;
    }
    
    for(;;z++) {
        m=scanf("%lld%1[^\n]s",&c[z],&ignore);
        if(m!=2)
        break;
    }
    if(x==1 && y==0 && z==0)
    {
        if(a[1]<a[0])
    {
        temp=a[1];
        a[1]=a[0];
        a[0]=temp;
    }
    goto special;       /* A special case */
   }
    for(;(i<=x)&&(j<=y)&&(k<=z);l++) {
        if(a[i]<b[j]) {
            if(a[i]<c[k]){
                d[l]=a[i];
                i++;
            }
            else {
                d[l]=c[k];
                k++;
            }
        }
        else {
            if(b[j]<c[k]){
                d[l]=b[j];
                j++;
            }
            else {
                d[l]=c[k];
                k++;
            }
        }
       printf("%lld ",d[l]);
    }
    if(i>x){                        /* We are comparing the elements and sorting it */
        for(;(j<=y)&&(k<=z);l++)
        {
            if(b[j]<c[k]){
                d[l]=b[j];
                j++;
            }
            else {
                d[l]=c[k];
                k++;
            }
            printf("%lld ",d[l]);
        }
        if(j>y) {
            for(;k<=z;l++,k++){
                d[l]=c[k];
                printf("%lld ",d[l]);
            }
        }
        else {
            for(;j<=y;l++,j++) {
                d[l]=b[j];
                printf("%lld ",d[l]);
            }
        }
        return 0;
    }
    if(j>y){
        for(;(i<=x)&&(k<=z);l++)
        {
            if(a[i]<c[k]){
                d[l]=a[i];
                i++;
            }
            else {
                d[l]=c[k];
                k++;
            }
            printf("%lld ",d[l]);
        }
        if(i>x) {
            for(;k<=z;l++,k++){
                d[l]=c[k];
                printf("%lld ",d[l]);
            }
        }
        else {
            for(;i<=x;l++,i++){
                d[l]=a[i];
                printf("%lld ",d[l]);
            }
        }
        return 0;
    }
    if(k>z){
        special:
        for(;(i<=x)&&(j<=y);l++)
        {
            if(a[i]<b[j]){
                d[l]=a[i];
                i++;
            }
            else {
                d[l]=b[j];
                j++;
            }
            printf("%lld ",d[l]);
        }
        if(i>x) {
            for(;j<=y;l++,j++){
                d[l]=b[j];
                printf("%lld ",d[l]);
            }
        }
        else {
            for(;i<=x;l++,i++){
                d[l]=a[i];
                printf("%lld ",d[l]);
            }
        }
    }
    return 0;
}
