#include<stdio.h>
#include<string.h>

struct node
{
int value;
char key[30];
struct node *next;
};

struct node* insert(char a[],int n,struct node* head)
{
  if(compare(a,head))
   {
   printf("Key is not Unique\n");
   return NULL;
   }
   else
   {
   struct node *link1 = (struct node*) malloc(sizeof(struct node));
   link1->value = n;
   strcpy(link1->key,a);
   link1->next=NULL;
   printf("ADDED\n");
   return link1;
   }

}

int compare(char *a,struct node* head)
{
int k,flag=0;
struct node *ptr = head;
   while(ptr != NULL)
	{
	k=strcmp(a,ptr->key);

     if(!k){
     flag=1;
     break;
     }

     ptr = ptr->next;
    }
return flag;
}

void printList(struct node* head)
{
   struct node *ptr = head;
   printf("\n");

   while(ptr != NULL)
	{
      printf("(%s)-> %3d\n",ptr->key,ptr->value);
      ptr = ptr->next;
   }
}

int main()
{
struct node *head=NULL;
head=insert("hgs",81,head);
head->next=insert("kama",80,head);
head->next->next=insert("Kamesh Dashora",36,head);
head->next->next->next=insert("kama",36,head);
head->next->next->next=insert("k",36,head);
printList(head);
}
