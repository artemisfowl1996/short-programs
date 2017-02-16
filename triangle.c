#include<stdio.h>
#include <stdlib.h>
void checktri(int,int,int);

void main()
{
    int a,b,c;
    while(1){
    printf("Enter the sides of the triangle\n");
    scanf("%d%d%d",&a,&b,&c);
    if(a+b>c || a+c>b || b+c>a)
    {
        printf("this is a valid triangle\n");
        checktri(a,b,c);
    }
    else
    {
        printf("this is not a triangle\n");
    }
}
}

void checktri(int x,int y,int z)
{
    if (x==y && x==z && y==z) {
        /* code */printf("Equilateral triangle\n");
    }
    else if(x==y || y==z || z==x )
    {
        printf("isosceles triangle");
    }
    else if(x!=y && y!=z && z!=x)
    {
        printf("scalene triangle");
    }
}
