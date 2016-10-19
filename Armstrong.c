#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int length(int no)
{
int l;
while(no>0)
{
no=no/10;
l++;
}
return l;
}

int Armstrong(int no)
{int m,sum=0,l=length(no);
while(no>0)
{
m=no%10;
sum+=(int)pow((int)m,(int)l);
no=no/10;
}
return sum;
}

int main()
{
int number=371;
if(number==Armstrong(number))
printf("Armstrong!");
else
printf("Not Armstrong!");
}
