//
//  probofseq.c
//  
//
//  Created by DLRL on 03/12/19.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 50
char str1[MAX_SIZE];
char str2[MAX_SIZE];
int i,j,choice;
int m,n;
int freq1[70]={0},freq2[70]={0};


void isequivalent(){
    if(m!=n){ printf("different lengths\n"); return;}
    for(i=0;i<m;i++){
        freq1[str1[i]-'A']++;
    }
    for(j=0;j<n;j++){
        freq2[str2[j]-'A']++;
    }
    j=0;
    for(i=0;i<70;i++){
        if(freq1[i]!=freq2[i]){
            j++;
        }
    }
    if(j>2) printf("not equivalent \n");
    else printf("equivalent \n");
}

void issubstring(){
    int flag;
    for (i = 0; i <= m-n; i++)
    {
        for (j = i; j < i + n; j++)
        {
            flag = 1;
            if (str2[j] != str1[j - i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            printf("%s is a substring of %s \n",str2,str1);return;
        }
    }
    

      printf("%s is not a substring of %s \n",str2,str1);
}


void printcommonsubs()
{
    
    int LCSuff[m + 1][n + 1];
  
    
    int len = 0;
  
    
    int row, col;
  
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
  
            else if (str1[i - 1] == str2[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                if (len < LCSuff[i][j]) {
                    len = LCSuff[i][j];
                    row = i;
                    col = j;
                }
            }
            else
                LCSuff[i][j] = 0;
        }
    }
  
   
    if (len == 0) {
        printf("No Common Substring");
        return;
    }
  
    char* resultStr = (char*)malloc((len + 1) * sizeof(char));
  
    
    while (LCSuff[row][col] != 0) {
        resultStr[--len] = str1[row - 1];
  
       
        row--;
        col--;
    }
  
    
    printf("%s \ns",resultStr);
}
int main()
{
    
    printf("Enter the string1\n");
    scanf("%s",str1);
    printf("Enter the string2\n");
    scanf("%s",str2);
    m=strlen(str1);
    n=strlen(str2);
    printf("Enter option (1, 2 or 3): \n");
    scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                isequivalent();
                break;
            case 2:
                issubstring();
                break;
            case 3:
                printcommonsubs();
        }
    
   
  
   
        return 0;
}
