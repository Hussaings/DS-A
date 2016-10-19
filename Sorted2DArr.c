#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

bool checkSorted(int a)
{
int i,j;
for(i = 0; i < 3; i ++)
{
for(j = 0; j < 3; j ++)
{
        if (a[i][j] < a[i][j+1])
            return true;
        else
            return false;
}
}
for(j = 0; j < 3; j ++)
{
for(i = 0; i < 3; i ++)
{
        if (a[j][i] < a[j][i+1])
            return true;
        else
            return false;
}
}
}
int main()
{
int arr[][]={{10,11,12},{13,14,15},{16,17,18}};
int i,j;
for(i = 0; i < 3; i ++)
{
for(j = 0; j < 3; j ++)
{
printf("%d ",arr[i][j]);
}
printf("\n")
}
}
