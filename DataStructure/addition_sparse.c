#include<stdio.h>
void main()
{
    int a[20][20],b[20][20],triplet1[20][20],triplet2[20][20],sum[20][20];
    int r1,c1,r2,c2,i,j,k=0,q=0,nz=0;
    printf("enter the first matrix details\n");
    printf("enter the number of rows and colums\n");
    scanf("%d%d",&r1,&c1);
    printf("enter the elements:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
            scanf("%d",&a[i][j]);
    }
    printf("enter the second matrix details\n");
    printf("enter the number of rows and colums\n");
    scanf("%d%d",&r2,&c2);
    printf("enter the elements:\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
            scanf("%d",&b[i][j]);
    }
    printf("the entered first matrix is:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d\t",a[i][j]);
        }
    printf("\n");
    }
    printf("\n");
    printf("the entered second matrix is:\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<r1;i++){
        for (j=0;j<c1;j++){
            if (a[i][j]!=0){
            k++;
            triplet1[k][0]=i;
            triplet1[k][1]=j;
            triplet1[k][2]=a[i][j];
            }
        }
    }
    triplet1[0][0]=r1;
    triplet1[0][1]=c1;
    triplet1[0][2]=k;
    printf("the triplet representation of first matrix is:\n");
    for(i=0;i<=k;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",triplet1[i][j]);
        }
    printf("\n");
    }
    for(i=0;i<r2;i++){
        for (j=0;j<c2;j++){
            if (b[i][j]!=0){
            q++;
            triplet2[q][0]=i;
            triplet2[q][1]=j;
            triplet2[q][2]=b[i][j];
            }
        }
    }
    triplet2[0][0]=r2;
    triplet2[0][1]=c2;
    triplet2[0][2]=q;
    printf("the triplet representation of second matrix is:\n");
    for(i=0;i<=q;i++)
    {
        for(j=0;j<3;j++)
        {
           printf("%d\t",triplet2[i][j]);
        }
    printf("\n");
    }
    if(r1==r2 && c1==c2){
        i=1,j=1;
        while(i<=k && j<=q){
            if(triplet1[i][0]==triplet2[j][0]&&triplet1[i][1]==triplet2[j][1]){
                nz++;
                sum[nz][0]=triplet1[i][0];
                sum[nz][1]=triplet1[i][1];
                sum[nz][2]=triplet1[i][2]+triplet2[j][2];
                i++;
                j++;
                }
            else if(triplet1[i][0]==triplet2[j][0]){
                if (triplet1[i][1]<triplet2[j][1]){
                    nz++;
                    sum[nz][0]=triplet1[i][0];
                    sum[nz][1]=triplet1[i][1];
                    sum[nz][2]=triplet1[i][2];
                    i++;
                    }
                else{
                    nz++;
                    sum[nz][0]=triplet2[j][0];
                    sum[nz][1]=triplet2[j][1];
                    sum[nz][2]=triplet2[j][2];
                    j++;
                    }  
                }
            else{
                if (triplet1[i][0]<triplet2[j][0]){
                    nz++;
                    sum[nz][0]=triplet1[i][0];
                    sum[nz][1]=triplet1[i][1];
                    sum[nz][2]=triplet1[i][2];
                    i++;
                    }
                else{
                    nz++;
                    sum[nz][0]=triplet2[j][0];
                    sum[nz][1]=triplet2[j][1];
                    sum[nz][2]=triplet2[j][2];
                    j++;
                    }  
                }
        }
    while(i<=k){
        nz++;
        sum[nz][0]=triplet1[i][0];
        sum[nz][1]=triplet1[i][1];
        sum[nz][2]=triplet1[i][2];
        i++;
        }
    while(j<=q){
        nz++;
        sum[nz][0]=triplet2[j][0];
        sum[nz][1]=triplet2[j][1];
        sum[nz][2]=triplet2[j][2];
        j++;
        }
    sum[0][0]=r1;
    sum[0][1]=c1;
    sum[0][2]=nz;
    printf("the resultant matrix is :\n");
    for(i=0;i<=nz;i++)
    {
        for(j=0;j<3;j++)
        {
           printf("%d\t",sum[i][j]);
        }
    printf("\n");
    }
    }
    else{
        printf("addition not possible !\n");
    }
}