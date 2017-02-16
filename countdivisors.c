/*You have been given 3 integers l, r and k
Find how many numbers between l and r (both inclusive) are divisible by k.
You do not need to print these numbers, you just have to find their count.*/
#include<stdio.h>
#include<stdlib.h>
void main() {
    int i,l,r,k,count=0;
    scanf("%d%d%d",&l,&r,&k);
    for(i=l;i<=r;i++)
    {
        if(i%k==0)
        {
            count++;
        }
    }
    printf("%d\n",count);
}
