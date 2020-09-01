#include<stdio.h>
void f(int *arr[],int n)
{
	int i;
	int k;
	int j;
	for(i=0;i<=n;i++)
	{
		k=arr[i];
		j=j-1;
		while(j>=0 && arr[j]>k)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=k;
	}
}
void printarray(int arr[],int n)
{
	int i;
	for(i=0;i<=n;i++)
	printf("%d\n",arr[i]);
}
int main()
{
	FILE *myfp=fopen("input_num.csv","r"), *myfp1=fopen("output2.txt", "w");
	if(myfp==NULL || myfp1==NULL)
	{
	printf("ERROR:cannot open the file\n");
	return 1;
	}
	char c=',';
	while(c!=EOF)
	{
	c=getc(myfp);
	putchar(c);
	getc(myfp);
	int p,result;
	fscanf(myfp,"%d",&p);
	printf("%d",p);
	if(c == 'f')
		result=f(p);
	fprintf(myfp1,"%d\n",result);
	printf("%d\n",result);
	}
	fclose(myfp);
	return 0;

}
