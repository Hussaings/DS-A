#include<stdio.h>
#include<stdlib.h>
int length(char *s)
{
int cnt=0;
while(*s!='\0')
{
s++;
cnt++;
}
return cnt;
}

int lapindrome(char *s)
{
char *begin=s,*middle;
int mid=length(s)/2+1;
*middle=s+mid;
if(compare(begin,middle))
printf("Lapindrome");
else printf("Not Lapindrome");
}

int compare(char *b,char *m)
{
int flag=0,k;
while(*m!='\0')
{
k=strcmp(*b,*m);
if(k==0)
flag=1;
else
flag=0;
*b++;*m++;
}
}
int main()
{
char str[]="adcda";
printf("%d",length(str)/2);
}
