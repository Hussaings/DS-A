#include<stdio.h>
#include<stdlib.h>

void reverseword(char *s)
{
char *begin=s;
char *temp=s;
while(*temp)
{
temp++;
if(*temp=='\0')
reverse(begin,temp-1);
else if(*temp==' ')
{
reverse(begin,temp-1);
begin=temp+1;
}
}
}
void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}

int main()
{
char str[]="MY NAME IS ABC";
puts(str);
reverseword(str);
puts(str);
}
