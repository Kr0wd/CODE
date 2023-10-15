#include<stdio.h>
void main()
{
    int a[20][20],b[20][20],t1[20][20],t2[20][20],c[20][20];
    int r1,c1,r2,c2,i,j,nz1=0,nz2=0,k=0;
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
            nz1++;
            t1[nz1][0]=i;
            t1[nz1][1]=j;
            t1[nz1][2]=a[i][j];
            }
        }
    }
    t1[0][0]=r1;
    t1[0][1]=c1;
    t1[0][2]=nz1;
    printf("the triplet representation of first matrix is:\n");
    for(i=0;i<=nz1;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",t1[i][j]);
        }
    printf("\n");
    }
    for(i=0;i<r2;i++){
        for (j=0;j<c2;j++){
            if (b[i][j]!=0){
            nz2++;
            t2[nz2][0]=i;
            t2[nz2][1]=j;
            t2[nz2][2]=b[i][j];
            }
        }
    }
    t2[0][0]=r2;
    t2[0][1]=c2;
    t2[0][2]=nz2;
    printf("the triplet representation of second matrix is:\n");
    for(i=0;i<=nz2;i++)
    {
        for(j=0;j<3;j++)
        {
           printf("%d\t",t2[i][j]);
        }
    printf("\n");
    }
    if(r1==r2 && c1==c2){
        i=1,j=1;
        while(i<=nz1 && j<=nz2){
            if(t1[i][0]==t2[j][0]&&t1[i][1]==t2[j][1]){
                k++;
                c[k][0]=t1[i][0];
                c[k][1]=t1[i][1];
                c[k][2]=t1[i][2]+t2[j][2];
                i++;
                j++;
                }
            else if(t1[i][0]==t2[j][0]){
                if (t1[i][1]<t2[j][1]){
                    k++;
                    c[k][0]=t1[i][0];
                    c[k][1]=t1[i][1];
                    c[k][2]=t1[i][2];
                    i++;
                    }
                else{
                    k++;
                    c[k][0]=t2[j][0];
                    c[k][1]=t2[j][1];
                    c[k][2]=t2[j][2];
                    j++;
                    }  
                }
            else{
                if (t1[i][0]<t2[j][0]){
                    k++;
                    c[k][0]=t1[i][0];
                    c[k][1]=t1[i][1];
                    c[k][2]=t1[i][2];
                    i++;
                    }
                else{
                    k++;
                    c[k][0]=t2[j][0];
                    c[k][1]=t2[j][1];
                    c[k][2]=t2[j][2];
                    j++;
                    }  
                }
        }
    while(i<=nz1){
        k++;
        c[k][0]=t1[i][0];
        c[k][1]=t1[i][1];
        c[k][2]=t1[i][2];
        i++;
        }
    while(j<=nz2){
        k++;
        c[k][0]=t2[j][0];
        c[k][1]=t2[j][1];
        c[k][2]=t2[j][2];
        j++;
        }
    c[0][0]=r1;
    c[0][1]=c1;
    c[0][2]=k;
    printf("the resultant matrix is :\n");
    for(i=0;i<=k;i++)
    {
        for(j=0;j<3;j++)
        {
           printf("%d\t",c[i][j]);
        }
    printf("\n");
    }
    }
    else{
        printf("addition not possible !\n");
    }
}