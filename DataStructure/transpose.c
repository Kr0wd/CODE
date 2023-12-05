#include<stdio.h>
void main()
{
	int a[10][10],triplet[10][10],transpose[10][10],row,col,i,j,nz=0,k;
	printf("Enter the number of rows\n");
	scanf("%d",&row);
	printf("Enter the number of columns\n");
	scanf("%d",&col);
	printf("Enter the sparse matrix\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			scanf("%d",&a[i][j]);
	}
	printf("The sparse matrix is\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
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
	triplet[0][0]=row;
	triplet[0][1]=col;
	triplet[0][2]=nz;
	
	printf("The triplet representation is\n");
	for(i=0;i<=nz;i++)
	{
		for(j=0;j<3;j++)
			printf("%d\t",triplet[i][j]);
		printf("\n");
	}

	transpose[0][0]=triplet[0][1];
	transpose[0][1]=triplet[0][0];
	transpose[0][2]=triplet[0][2];
	k=0;
	for(i=0;i<col;i++)
	{
		for(j=0;j<=nz;j++)
		{
			if(triplet[j][1]==i)
			{
				k++;
				transpose[k][0]=triplet[j][1];
				transpose[k][1]=triplet[j][0];
				transpose[k][2]=triplet[j][2];
			}
		}
	}
	printf("The transpose matrix is\n");
	for(i=0;i<=k;i++)
	{
		for(j=0;j<3;j++)
			printf("%d\t",transpose[i][j]);
		printf("\n");
	}
} 

