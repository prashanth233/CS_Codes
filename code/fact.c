#include<stdio.h>
unsigned long long int factorial(unsigned long long int number)
{
	if (number<=1)
	{
	return 1;
	}
	else 
	{
	return (number*factorial(number-1));
	}
}
int main()
{
	unsigned long long int i;
	for (i=0;i<=25;i++)
	{
	printf("%u!=%llu\n",i,factorial(i));
	}
}
