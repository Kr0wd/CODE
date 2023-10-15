#include<stdio.h>
void main()
{
	int x,n,e[50],i,o,p,ind,c,d,flag;
	do
	{
		printf("1.insertion\t2.deletion\n");
	    printf("enter your choice : ");
	    scanf("%d",&x);
	    switch(x)
	    {
	    	case 1: printf("enter the number of elements :");
	    			scanf("%d",&n);
	    			printf("enter the elements\n");
	    			for (i=0;i<n;i++)
	    			{
	    				scanf("%d",&e[i]);
	    			}
	    			printf("the entered elements are :");
	    			for (i=0;i<n;i++)
	    				printf("%d\t",e[i]);
	    			printf("\n");
	    			printf("enter the element to be inserted :");
	    			scanf("%d",&o);
	    			printf("enter the position of element to be inserted: ");
	    			scanf("%d",&p);
	    			ind=p-1;
	    			for(i=n;i<=ind;i--)
	    			{
	    				e[i+1]=e[i];
	    			}
	    			e[ind]=o;
	    			for (i=0;i<n;i++)
	    				printf("%d\n",e[i]);
	    			break;
	    	case 2: printf("enter the number of elements :");
	    			scanf("%d",&n);
	    			printf("enter the elements\n");
	    		
	    			for (i=0;i<n;i++)
	    			{
	    				scanf("%d",&e[i]);
	    			}
	    				printf("the entered elements are :");
	    			for (i=0;i<n;i++)
	    				printf("%d\t",e[i]);
	    			printf("\n");
	    			printf("enter the element to be deleted :");
	    			scanf("%d",&d);
	    			for(i=0;i<n;i++)
	    				if(e[i]==d)
	   							{
	   							flag=1;
	   							ind=i;
	   							}
	   				if (flag==1)
	   					{
	   					for (i=ind;i<n-1;i++)
	   						{
	   						e[i]=e[i+1];
	   						}
	   					n--;
	   					}
	   					
	   				else
	   		            printf("element not found\n");
	    			for (i=0;i<n;i++)
	    				printf("%d\n",e[i]);
	    			break;
	    }
	    printf("do you want to continue?\n1 for continuing");
		scanf("%d",&c);
	}
while (c==1);
}