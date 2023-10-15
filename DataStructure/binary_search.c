#include<stdio.h>
void main()
{
    int n,a[20],s;
    printf("enter the number of elements:");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("element to be searched :");
    scanf("%d",&s);
    int low=0;
    int high =(n-1);
    int f=0,pos,mid;
    while (low<=high)
    {
        mid = ((low+high)/2);
        if(a[mid]==s)
        {
            pos=mid;
            f=1;
            break;
        }
        else if (a[mid]<s)
            low = mid+1;
        else
            high = mid -1;
    }
    if (f)
    {
        printf("element is found at position %d \n", pos);
    }
    else
    {
        printf("element is not found \n");
    }
}      