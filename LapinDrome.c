#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void lapindrome(char arr[],int s)
{
int s1[27],s2[27],i,flag=1;
for(i=0;i<27;i++)
{
s1[i]=s2[i]=0;
}

for(i=0;i<s/2;i++)
{
s1[arr[i]-'a']++;
s2[arr[s-1-i]-'a']++;
}

for(i=0; i<27; i++)
   if(s1[i] != s2[i])
   {
   flag=0;
   break;
   }

 if(flag) puts("YES");
 else puts("NO");
}


int main()
{
char str[]="abcdbca";
lapindrome(str,strlen(str));
}
