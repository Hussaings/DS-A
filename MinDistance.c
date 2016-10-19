#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int MinDis(int m[],int a,int b)
{
int c,d,diff=1000,i=0,k=-1;
while(i<9)
{
if(m[i]==a)
{
c=i;
k++;
}
else
if(m[i]==b)
{
d=i;
k++;
}
diff=min(diff,abs(c-d));
i++;
}
return diff-1;
}


int min(a,b)
{
return (a<b?a:b);
}


int main()
{
int a[]={1,2,3,8,5,5,7,8,5};
printf("%d",MinDis(a,1,8));

}
