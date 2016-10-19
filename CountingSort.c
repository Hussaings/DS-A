#include<stdlib.h>
#include<stdio.h>

int MaxFq(int a[])
{
int max=0,max1=-1,i,*k,m;
for(i=0;i<8;i++)
{
if(a[i]>max)
max=a[i];
}
k=(int*)malloc(max*sizeof(int));
for(i=0;i<8;i++)
{
k[a[i]-1]++;
}
for(i=0;i<6;i++)
{
if(k[i]>max1)
{
max1=k[i];
m=i+1;
}
}
return m;
}
int main()
{
int a[]={3,6,4,1,3,3,1,4};
printf("%d",MaxFq(a));
}
