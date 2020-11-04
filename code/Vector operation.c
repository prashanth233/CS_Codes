//
//  Vector operation.c
//  
//
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void tran(int*arr,int n,int m); /* Transpose function */
void sym(int*arr,int n,int m);  /* Symmetric function */
void ort(int*arr,int n,int m);  /* Othogonal function */


void tran(int*arr,int n,int m){ /* We are printing the transpose matrix */
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",*(arr+j*m+i));}
            printf("\n");}
        }
void sym(int*arr,int n,int m){  /* Symmetric matrix if transpose of matrix is equal to original matrix */
    for(int i=0;i<n;i++)
     for(int j=i+1;j<m;j++)
      if(*(arr+i*m+j)==*(arr+j*m+i))
        continue;
        else{
          printf("Matrix is not symmetric\n");
          return;}
        printf("Matrix is symmetric\n");}
void ort(int*arr,int n,int m){  /* Checking if matrix is Orthogonal matrix or not */
    int sum=0;  /* We are initializing the sum which is equal to zero */
    for(int i=0;i<n;i++)
     for(int j=0;j<m;j++){
        for(int k=j+1;k<m;k++)
           sum=sum+(*(arr+i*m+j))*(*(arr+i*m+k));} /* The matrix is orthogonal, When original matrix is multiplied with                                                             transpose matrix */
    if(sum!=0)
        printf("Matrix is not orthogonal\n");
    else{
        printf("Matrix is orthogonal\n");
        return;}}
int main(){
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int r,c;    /* We are initializing rows and coloumns */
    scanf("%d%d",&r,&c);
    int*arr=(int*)malloc(r*c*sizeof(int)); /* creating a 2D array */
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            scanf("%d",(arr+i*c+j));
        }
    tran(arr,r,c); /* We are calling the transpose function */
    sym(arr,r,c);  /* We are calling the symmetric function */
    ort(arr,r,c);  /* We are calling the orthogonal function */
    return 0;}
    
