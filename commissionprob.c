#include<stdio.h>
#include<stdlib.h>
void comm(int ,int ,int );
int lock=0,stock=0,barrel=0;
void main()
{
int i,lo,st,br;
while(1)
{
printf("enter the number of locks\n");
scanf("%d",&lo);
if(lo==-1)
{break;}
printf("enter the number of stocks\n");
scanf("%d",&st);
printf("enter the number of barrels\n");
scanf("%d",&br);
if(lo>=1 && lo<=70 && st>=1 && st<=80 && br>=1 && br<=90)
{
lock+=lo;
stock+=st;
barrel+=br;
}
else
{
printf("invalid input\n");
}
}
comm(lock,stock,barrel);
}

void comm(int l,int s,int b)
{
	int i,calc,com;
	calc=l*45+s*30+b*25;//}
	if(calc<1000)
	{
		com=0.1*calc;
	}
	else if(calc<=1800 && calc>=1000)
	{
		com=0.1*1000 + (calc-1000)*0.15;	
	}
	else if(calc>1800)
	{
		com=0.1*1000+800*0.15+(calc-1800)*0.2;
	}
	printf("the sales is %d\n",calc);
	printf("the commission is %d\n",com);
}

