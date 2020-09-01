#include<stdio.h>
void mergeArrays(int arr1[],int arr2[],int n1,int n2)
{ 
	int i=0,j=0,k=0,arr3[n1+n2];
while(i<n1&&j<n2)
{
	if(arr1[i]<arr2[j])
	arr3[k++]=arr1[i++];
	else
	arr3[k++]=arr2[j++];
}

while(i<=n2-1)
arr3[k++]=arr1[i++];
while(j<=n1-1)
arr3[k++]=arr2[j++];
printf("Array after merging\n"); 
	
for (int i=0; i < n1+n2; i++)
		printf(" %d ", arr3[i]); 
}
int main()
{
	int arr1[]={1,6,9,12,14,14,23,32,34,44,45,56};
	int n1= sizeof(arr1)/sizeof(arr1[0]);
	int arr2[] = {11,24,40,42,60}; 
	int n2 = sizeof(arr2) / sizeof(arr2[0]); 
	int *arr3; 
	mergeArrays(arr1, arr2, n1, n2); 
	
	return 0; 
} 
