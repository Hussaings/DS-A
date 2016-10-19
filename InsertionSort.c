#include<stdio.h>
#include<stdlib.h>

void InsertionSort(int a[],int n)
{
int i,key,j;

for(i=1;i<n;i++)
{
key=a[i];
j=i-1;

while(j>=0 && a[j]>key)
{
a[j+1]=a[j];
j=j-1;
}

a[j+1]=key;
}
}

void print(int a[],int n)
{
int i;
for(i=0;i<n;i++)
printf("%d ",a[i]);
}


int main()
{
int arr[]={12,11,13,5,6};
int length=sizeof(arr)/sizeof(arr[0]);
InsertionSort(arr,length);
print(arr,length);
}
