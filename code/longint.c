//
//  longint.c
//  
//
//  Created by DLRL on 04/12/19.
//

#include <stdio.h>
#include <string.h>
char str1[50];
char str2[50];
char temp[50];
char result[100];
int k;
int len1,len2,i,j;
int enc,dec;


void substring(){
    
    for(i=0;i<=len1-k;i++){
        for(j=i;j<i+k;j++){
            printf("%c",str1[j]);
        }
        printf(" %s \n",str1);
    }
    for(i=0;i<=len2-k;i++){
        for(j=i;j<i+k;j++){
            printf("%c",str2[j]);
        }
        printf(" %s \n",str2);
    }
}

int chrtoint(char a){
    return a-'0';
}

void addition(){
    int cmax=len1,sum;
    if(len1<len2) cmax=len2;
    for(i=0;i<len1;i++){
        temp[i]=str1[len1-1-i];
    }
    for(i=0;i<len1;i++){
        str1[i]=temp[i];
    }
    for(i=0;i<len2;i++){
        temp[i]=str2[len1-1-i];
    }
    for(i=0;i<len2;i++){
        str2[i]=temp[i];
    }
     int mm=0;
    for(i=0; i< cmax; i++){
    if(len1==len2 || (i < len1 && i < len2)){
    sum = mm+chrtoint(str1[i])+chrtoint(str2[i]);
    }
    else if(i >=len1){
    sum = mm+chrtoint(str2[i]);
    }else if(i >=len2){
    sum = mm+chrtoint(str1[i]);
    }
    result[i] = sum%10;
    mm = sum/10;
    }

    if(mm){
    result[i]=mm;
    i++;
    }

    printf("Sum: ");
    for(j=0; j < i; j++){
    printf("%d", result[i-j-1]);
    }
    printf("\n");
}

void subtraction(){
    int cmax=len1,sum;
    if(len1<len2) cmax=len2;
    
   
     int mm=0;
    for(i=0; i< cmax; i++){
    if(len1==len2 || (i < len1 && i < len2)){
    sum = mm+chrtoint(str1[i])-chrtoint(str2[i]);
    }
    else if(i >=len1){
    sum = mm-chrtoint(str2[i]);
    }else if(i >=len2){
    sum = mm+chrtoint(str1[i]);
    }
    result[i] = (sum+30)%10;
        if(sum<0) mm=-1;
        else mm=0;
    }

    if(mm){
    result[i]=mm;
    i++;
    }

    printf("Difference: ");
    for(j=0; j < i; j++){
    printf("%d", result[i-j-1]);
    }
    printf("\n");
}

 
void encrypt(){
    for(i=0;i<len1;i++){
        printf("%d",(str1[i]-'0'+enc)%10);
    }
    printf("\n");
    for(i=0;i<len2;i++){
        printf("%d",(str2[i]-'0'+enc)%10);
    }
    printf("\n");
    
}

void decrypt(){
    for(i=0;i<len1;i++){
        printf("%d",(10+str1[i]-'0'-dec)%10);
    }
    printf("\n");
    for(i=0;i<len2;i++){
        printf("%d",(10+str2[i]-'0'-dec)%10);
    }
    printf("\n");
    
}



int main(){
    
    printf("Enter the two numbers \n");
    scanf("%s",str1);
    scanf("%s",str2);
    len1=strlen(str1);
    len2=strlen(str2);
    int choice;
    printf("Enter your choice 1-3 \n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the value of k \n");
            scanf("%d",&k);
            substring();
            break;
        case 2:
            addition();
            subtraction();
            break;
        case 3:
            printf("Enter the value of the encryptor \n");
            scanf("%d",&enc);
            printf("Enter the value of the decryptor \n");
                       scanf("%d",&dec);
            encrypt();
            decrypt();
    
            
            
    }
    
    return 0;
    
}
