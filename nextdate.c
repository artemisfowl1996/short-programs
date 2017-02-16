#include<stdio.h>
#include<stdlib.h>
void next(int ,int ,int );

int main(int argc, char const *argv[]) {
    /* code */
    int day,mon,year;
printf("enter the day month and year\n");
scanf("%d %d %d",&day,&mon,&year);
if(day>=1 && day<=31 && mon<=12 && mon>=1 && year<=2012 && year>=1812)
{
    printf("valid date\n");
    next(day,mon,year);
}
else
{
    printf("invalid date");
}
    return 0;
}

void next(int d,int m,int y)
{
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
    {
        printf("this month has 31 days\n");
        if(d==31)
        {
            if(m==12)
            {
                y++;
                m=1;
                d=1;
            }
            else{
            d++;
            m++;}
        }
    }
    else if(m==4 || m==6 || m==9 || m==11)
    {   printf("this month has 30 days\n");
        if(d<30)
        {
            d++;
        }
        else if(d==30)
        {
            m++;
            d=1;
        }
    }
    else if(m==2)
    {
        if(y%4==0 && y%100!=0|| y%400==0)
        {
                printf("this is a leap year and century year\n");
                if(d==29)
                {
                    d=1;
                    m++;
                }
                else if(d<=28)
                {
                    d++;
                }
        }
        else if(d<=28)
        {
            printf("this is not a leap year\n");
            d=1;
            m++;
        }
    }
    printf("the next date is \n %d\t%d\t%d\n",d,m,y);
}
