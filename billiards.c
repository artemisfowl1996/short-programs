/*Input:
5
140 82
89 134
90 110
112 106
88 90
Output:
1 58*/

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i,n,lead1=0,lead2=0,lead,player,pl,gr=0,a,b;
    scanf("%d",&n); //get input of the number of rounds
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        lead1=lead1+a;
        lead2=lead2+b;
        if(lead1>lead2)
        {
            lead=lead1-lead2;
            pl=1;
        }
        else
        {
            lead=lead2-lead1;
            pl=2;
        }
        if(lead>gr)
        {
            if(pl==1)
            {
                gr=lead;
                player=1;
            }
            else
            {
                gr=lead;
                player=2;
            }
        }
    }
    printf("%d %d\n",player,gr);
}
