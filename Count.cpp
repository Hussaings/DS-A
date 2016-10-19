#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

void cnt(int a[])
{
int i=0,q,count=0;
q=a[i];
while(i<=8)
{
if(q==a[i])
{
i++;
count++;
}
else
{
printf("item:%d count is:%d\n",a[i-1],count);
count=0;
q=a[i];
}
}
}
int main()
{
int a[]={14,12,69,25,69,14,17,1};
std::sort(a,a+8);
cnt(a);
}
