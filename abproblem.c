/*Input:
An input contains 2 integers A and B.

Output:
Print a wrong answer of A-B. Your answer must be a positive integer containing the same number of digits as the correct answer, and exactly one digit must differ from the correct answer. Leading zeros are not allowed. If there are multiple answers satisfying the above conditions, anyone will do.
Constraints*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b,dif,i;
    scanf("%d %d",&a,&b);
    dif=(a-b);
    i=dif%10;
    if(i<9)
    {dif++;}
    else
    {dif--;}
    printf("%d\n",dif);
    return 0;
}
