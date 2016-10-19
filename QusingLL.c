#include<stdio.h>
#include<stdlib.h>
struct qnode
{
int key;
struct qnode *next;
};

struct Q
{
struct qnode *front,*rear;
};

//get new node
struct qnode* newnode(int k)
{
    struct qnode *temp = (struct qnode*)malloc(sizeof(struct qnode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}


//enqueue function to add node
void enq(struct Q *q, int k)
{
struct qnode *temp=newnode(k);

if(q->rear==NULL)
{
q->rear=q->front=temp;
return;
}

q->rear->next=temp;
q->rear=temp;
}

//dequeue function
int deq(struct Q *q)
{
if(q->front==NULL)
return -1;

int m=q->front->key;
q->front=q->front->next;

if(q->front==NULL)
q->rear=NULL;
return m;
}

int main()
{
struct Q *q=(struct Q*)malloc(sizeof(struct Q));
q->front=q->rear=NULL;
enq(q,4);
enq(q,2);
enq(q,1);
printf("%d  ",deq(q));
printf("%d  ",deq(q));
printf("%d  ",deq(q));
}
