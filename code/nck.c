#include<stdio.h>
int c(int n, int k)
{
	if(k<0||n<0)
	return 0;
	if(k>n)
	return 0;
	if(k==0)
	return 1;
	else
	{
	return (c(n-1,k)+c(n-1,k-1));
	}
}
int main()
{
	int n,k,h;
	printf("enter the value of n\n");
	scanf("%d",&n);
	printf("enter the value of k\n");
	scanf("%d",&k);
	h=c(n,k);
	printf("selecting in n ways %d\n",h,n,k);
	return 0;
}

