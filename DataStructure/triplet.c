#include<stdio.h>
void main()
{
	int a[10][10],triplet[10][10],r,c,i,j,nz=0;
	printf("Enter the number of rows\n");
	scanf("%d",&r);
	printf("Enter the number of columns\n");
	scanf("%d",&c);
	printf("Enter the sparse matrix\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			scanf("%d",&a[i][j]);
	}
	printf("The sparse matrix is\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(a[i][j]!=0)
			{
				nz++;
				triplet[nz][0]=i;
				triplet[nz][1]=j;
				triplet[nz][2]=a[i][j];
			}
		}
	}
	triplet[0][0]=r;
	triplet[0][1]=c;
	triplet[0][2]=nz;
	
	printf("The triplet representation is\n");
	for(i=0;i<=nz;i++)
	{
		for(j=0;j<3;j++)
		    printf("%d\t",triplet[i][j]);
		printf("\n");
	}
}
	
		
	