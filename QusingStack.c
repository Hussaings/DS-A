#include<stdio.h>
#include<stdlib.h>
struct stack
{
int key;
struct stack *next;
};

struct queue
{
struct stack *s1,*s2;

};

void push(struct stack** top,int k)
{
struct stack* newnode=(struct stack*)malloc(sizeof(struct stack));
if(newnode==NULL)
{
printf("stack overflow");
return;
}
newnode->key=k;
newnode->next=*top;
*top=newnode;
}

int pop(struct stack** top)
{
  int res;
  struct stack *t;

  /*If stack is empty then error */
  if(*top == NULL)
  {
     printf("Stack overflow \n");
     getchar();
     exit(0);
  }
  else
  {
     t = *top;
     res = t->key;
     *top = t->next;
     free(t);
     return res;
  }
}
void enq(struct queue *q,int key)
{
push(&q->s1,key);
}

int deq(struct queue *q)
{int x;
if(q->s1==NULL && q->s2==NULL)
{
printf("/nQueue is empty/n");
return;
}
if(q->s2==NULL)
{
while(q->s1 != NULL)
     {
        x = pop(&q->s1);
        push(&q->s2, x);
     }
}
x=pop(&q->s2);
return x;
}

int main()
{
   /* Create a queue with items 1 2 3*/
   struct queue *q = (struct queue*)malloc(sizeof(struct queue));
   q->s1 = NULL;
   q->s2 = NULL;
   enq(q, 1);
   enq(q, 2);
   enq(q, 3);

   /* Dequeue items */
   printf("%d  ", deq(q));
   printf("%d  ", deq(q));
   printf("%d  ", deq(q));

   getchar();
}
