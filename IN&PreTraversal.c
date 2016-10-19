#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node* left;
struct node* right;
};

struct node* newNode(int k)
{
struct node*temp=(struct node*)malloc(sizeof(struct node));
temp->data=k;
temp->left=temp->right=NULL;
return node;
}

struct node* search(int in[],int start,int end,int value)
{
int i;
for(i=start;i<end;i++)
{
if(in[i]==value)
return i;
}
}

struct node* buildTree(int in[],int pre[],int istart,int iend)
{
static int preindex=0;

if(istart>iend)
return NULL;

struct node* tnode=newNode(pre[preindex++]);

if(istart==iend)
return tnode;

/* Else find the index of this node in Inorder traversal */
  int inIndex = search(in, istart,iend tnode->data);

  /* Using index in Inorder traversal, construct left and
     right subtress */
  tnode->left = buildTree(in, pre, istart, inIndex-1);
  tnode->right = buildTree(in, pre, inIndex+1, iend);

  return tnode;
}

void printInorder(struct node* node)
{
  if (node == NULL)
     return;

  printInorder(node->left);

  printf("%c ", node->data);

  printInorder(node->right);
}


int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  struct node *root = buildTree(in, pre, 0, len - 1);
  printf("Inorder traversal of the constructed tree is \n");
  printInorder(root);
  return 0;
}

