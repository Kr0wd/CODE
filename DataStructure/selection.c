#include<stdio.h>
void selection(int a[],int n)
{
	int min,i,j,loc;
	for(i=0;i<n-1;i++)
	{
		min=a[i];
		loc=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<min)
			{
				min=a[j];
				loc=j;
			}
		}
		if(i!=loc)
		{
			a[i]+=a[loc];
			a[loc]=a[i]-a[loc];
			a[i]-=a[loc];
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
	selection(a,n);
}	