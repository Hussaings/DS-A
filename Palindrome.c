#include<stdio.h>
#include<stdlib.h>
int prime(int n)
{
int flag=1,i;
if(n==1)
return 0;

for(i=2;i<=n-1;i++)
{
if(n%i==0)
{
flag=0;
break;
}
}
return flag;
}
int palindrome(int n)
{
int r,original=n,reverse=0;
while( n!=0 )
    {
        r = n%10;
        reverse = reverse*10 + r;
        n /= 10;
    }
return (original==reverse);
}



int main()
{
int no=131;

if(prime(no))
printf("%d",palindrome(no));
else
printf("Number is not prime");

}
