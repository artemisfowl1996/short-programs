#include<stdio.h>
#include<stdlib.h>
void checkbal(int ,float);
int main()
{
    float bal;
    int dr;
    printf("enter the current bank balance\n");
    scanf("%f",&bal);
    printf("enter the amount to withdraw\n");
    scanf("%d",&dr);
    if(dr%5==0)
    {
    checkbal(dr,bal);}
    else
    {
        printf("invalid input\n");
    }
    return 0;
}

void checkbal(int withdraw,float balance)
{
    if(withdraw>balance)
    {
        printf("error\n");
        exit(0);
    }
    else
    {
        printf("suceesful withdrawal\n");
        balance=(balance-withdraw);
        printf("%f\n",balance-0.50);}
}
