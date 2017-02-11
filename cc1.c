#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i,n,a[10];
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the sequence of numbers\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    i=0;
    printf("the output is \n");
    while(a[i]!=42)
    {
        printf("%d\n",a[i]);
        ++i;
    }
}
