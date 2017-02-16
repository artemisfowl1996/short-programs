#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n,a[10],i,prod;
    printf("enter the number of elements in the array\n");
    scanf("%d",&n);
    printf("enter the numbers\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    prod=a[0];
    for(i=0;i<n;i++)
    {
        prod=a[i]*prod;;
    }
        printf("%d",prod);
}
