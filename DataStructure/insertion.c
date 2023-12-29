#include<stdio.h>
void inserts(int a[],int n)
{
	int temp,i,j;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0&&temp<a[j];j--)
			a[j+1]=a[j];
		a[j+1]=temp;
	}
	printf("Sorted array : ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}		
void main()
{
	int a[20],n,i;
	printf("Enter the size of array :");
	scanf("%d",&n);
	printf("Enter the array elements :\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	inserts(a,n);
}