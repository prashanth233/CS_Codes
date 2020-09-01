//
//  fun.c
//  
//
//  Created by DLRL on 01/12/19.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    int m , n;
    scanf("%d %d", &m, &n);
    int **arr;
    arr = (int **)malloc(m * sizeof(int *));
    for(int i = 0; i < m; i++){
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
