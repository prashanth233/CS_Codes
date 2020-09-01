//
//  detrank.c
//  
//
//  Created by DLRL on 02/12/19.
//

#include<stdio.h>
int main(){
    int n,i,j,k;
    float temp;
    printf("Enter the dimensions of the matrix: \n");
    scanf("%d",&n);
    printf("Enter the matrix: \n");
    float a[100][100];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%f",&a[i][j]);
        }
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            temp=a[j][i]/a[i][i];
            for(k=i;k<n;k++){
                a[j][k]-=(temp*a[i][k]);
            }
        }
    }
    float det=1,rank=0;
    for(i=0;i<n;i++) det*=a[i][i];
    for(i=0;i<n;i++){
        rank++;
        int flag=0;
        for(j=0;j<n;j++){
            if(a[i][j]!=0) {flag=1;break;}
        }
        if(flag==0) rank--;
    }
    printf("The determinant of the matrix is %f: \n",det);
    printf("The rank of the matrix is %f: \n",rank);
    return 1;
}
