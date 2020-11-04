//
//  Complex number operation.c
//  
//
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct complex{
    double real,img; /* we are defining a structure called complex */
};                   /* Which consists of real and img numbers */

struct complex addi(struct complex n1,struct complex n2);  /* We are declaring a function over here*/
struct complex subt(struct complex n1,struct complex n2);
struct complex mul(struct complex n1,struct complex n2);
struct complex divi(struct complex n1,struct complex n2);

int main(){
    int n;
    scanf("%d\n",&n);
    int i;
    for(i=0;i<n;i++){
     struct complex n2;
     struct complex n1;
     struct complex total;
    char x;
    scanf("%c\n",&x);
    scanf("%lf%lf%lf%lf\n",&(n1.real),&(n1.img),&(n2.real),&(n2.img));
       if(x=='+') total=addi(n1,n2);        /* If it is '+' we are calling addition function */
        else if(x=='-') total=subt(n1,n2);  /* If it is '-' we are calling subtraction function */
        else if(x=='*') total=mul(n1,n2);   /* If it is '*' we are calling multiplication function */
        else if(x=='/') total=divi(n1,n2);  /* If it is '/' we are calling division function */
        printf("%.2lf + %.2lfi\n",total.real,total.img);
    }
    return 0;
}
struct complex addi(struct complex n1,struct complex n2){       /* Here, we are defining functions */
    struct complex t;                                           /* We are declaring t */
    t.real=n1.real+n2.real;
    t.img=n1.img+n2.img;
    return t;
}
struct complex subt(struct complex n1, struct complex n2){      /* subtraction function */
    struct complex t;
    t.real=n1.real-n2.real;
    t.img=n1.img-n2.img;
    return t;
}
struct complex mul(struct complex n1, struct complex n2){       /* multiplication function */
    struct complex t;
    t.real=(n1.real*n2.real)-(n1.img*n2.img);
    t.img=(n1.real*n2.img)+(n1.img*n2.real);
    return t;
}
struct complex divi(struct complex n1, struct complex n2){      /* division function */
    struct complex t;
    t.real=((n1.real*n2.real)+(n1.img*n2.img))/((n2.real*n2.real)+(n2.img*n2.img));
    t.img=((n1.img*n2.real)-(n1.real*n2.img))/((n2.real*n2.real)+(n2.img*n2.img));
    return t;
}
