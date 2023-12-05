    #include <stdio.h>
    #include<stdbool.h>
    struct poly
    {
        int coef;
        int exp;
    }result[20];
    int d=0;
    struct poly p[10], q[10];
    void add(int c,int e)
    {
        result[d].coef=c;
        result[d].exp=e;
        d++;
    }
    int readpoly(struct poly p1[10])
    {
        int i,j,k;
        printf("Enter the number of terms :");
        scanf("%d",&k);
        for(i=0;i<k;i++)
        {
            printf("Enter term %d coefficient :",i+1);
            scanf("%d",&p1[i].coef);
            printf("Enter term %d exponent :",i+1);
            scanf("%d",&p1[i].exp);
        }
        return k;
    }
    void display(struct poly z[20],int k)
    {
        int j,i;
        for(i=0;i<k-1;i++)
        {
            printf("%dx^%d+",z[i].coef,z[i].exp);
        }
        if(z[i].exp==0)
            printf("%d",z[i].coef);
        else
            printf("%dx^%d  ",z[i].coef,z[i].exp);
        printf("\n\n");
    }
    void addpoly(int k,int l)
    {
        int i=0,j=0;
        while(i<k&&j<l)
        {
            if(p[i].exp==q[j].exp)
            {
                add(p[i].coef+q[j].coef,p[i].exp);
                j++;
                i++;
            }
            else if (p[i].exp < q[j].exp)
            {
                    add(q[j].coef,q[j].exp);
                    j++;
            }
            else if (p[i].exp > q[j].exp)
            {
                add(p[i].coef,p[i].exp);
                i++;
            }
        }
        while (i <k)
        {
            add(p[i].coef,p[i].exp);
            i++;
        }
        while (j <l)
        {
            add(q[j].coef,q[j].exp);
            j++;
        }
    }
    int main()
    {
        int k,l;
        printf("Polynomial  1\n");
        k=readpoly(p);
        printf("Entered polynomial :");
        display(p,k);
        printf("Polynomial  2\n");
        l=readpoly(q);
        printf("Entered polynomial :");
        display(q,l);
        addpoly(k,l);
        printf("Sum :");
        display(result,d);
    }