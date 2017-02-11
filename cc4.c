#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i,k,n,a[10],count=0;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    k=a[1];
    printf("the numbers are\n");
    for(i=0;i<=n;i++)
    {
        if(a[i]%k==0)
        {
            count++;
            printf("%d\n",a[i]);
        }
    }
    printf("%d\n",count);
}
