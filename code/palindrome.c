//
//  palindrome.c
//  
//
//  Created by DLRL on 25/11/19.
//

#include<stdio.h>
#include<string.h>
int main()
{
    char string1[30];
    int i;
    int length;
    int flag=0;
    printf("Enter the string\n");
    scanf("%s",string1);
    length=strlen(string1);
    printf( "%s%s\t\n","string ","result");
    for(i=0;i<length;i++)
    {
        if(string1[i] != string1[length-i-1]){
                    flag = 1;
                    break;
           }
        }
            
            if (flag) {
                printf("%s No\t\n   ", string1);
            }
            else {
                printf("%s Yes\t\n   ", string1);
            }
            return 0;
        }
    
