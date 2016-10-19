#include<stdio.h>
#include<stdlib.h>

void denomination(int amt)
{
int copy=amt,totalnotes=0,count=0,i;
int den[]={1000,500,100,50,20,10,5,2,1};
for(i=0;i<9;i++)
{
count=amt/den[i];
if(count!=0)
{
printf("%4d X %2d = %d\n",den[i],count,den[i]*count);
}
totalnotes+=count;
amt=amt%den[i];
}
}
int main()
{
denomination(3600000);
}
