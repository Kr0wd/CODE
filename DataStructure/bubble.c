#include<stdio.h>
void bubble(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j+1]<a[j])
			{
				a[j]+=a[j+1];
				a[j+1]=a[j]-a[j+1];
				a[j]-=a[j+1];
			}
		}
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
	bubble(a,n);
}	