#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
     struct node* node = (struct node*)
                                  malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;

     return(node);
}

void Inorder(struct node* node)
{
if(node==NULL)
return;

Inorder(node->left);
printf("--%d--",node->data);
Inorder(node->right);
}

void Preorder(struct node* node)
{
if(node==NULL)
return;
printf("--%d--",node->data);
Preorder(node->left);
Preorder(node->right);
}

void Postorder(struct node* node)
{
if(node==NULL)
return;

Postorder(node->left);
Postorder(node->right);
printf("--%d--",node->data);
}

int height(struct node* node)
{
if(node==NULL)
return 0;
else
{
int lHgt=height(node->left);
int rHgt=height(node->right);
if(lHgt>rHgt)
return (lHgt+1);
else
return (rHgt+1);
}
}

/* Function to print level order traversal a tree*/
void printLevelOrder(struct node* root,int height)
{
    int h = height;
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
int max(int a,int b)
{
if(a>b)
return a;
else
return b;
}
// compute tree diameter recursively
int getDiameter(struct node *root) {
   if (root == NULL)
      return 0;

   // get height of each subtree
   int lh = height(root->left);
   int rh = height(root->right);
   //printf("\n%d $ %d\n",lh,rh);

   // compute diameters of each subtree
   int ld = getDiameter(root->left);
   int rd = getDiameter(root->right);

   return max(lh+rh+1,max(ld,rd));
}

//Printf ancestors

int printAncestors(struct node *root, int target)
{
  /* base cases */
  if (root == NULL)
     return 0;

  if (root->data == target)
     return 1;

  if ( printAncestors(root->left, target) ||
       printAncestors(root->right, target) )
  {
    printf("%d ",root->data);
    return 1;
  }

  return 0;
}

//chk two trees are identical
int identicalTrees(struct node* a, struct node* b)
{
    /*1. both empty */
    if (a==NULL && b==NULL)
        return 1;

    /* 2. both non-empty -> compare them */
    if (a!=NULL && b!=NULL)
    {
        return
        (
            a->data == b->data &&
            identicalTrees(a->left, b->left) &&
            identicalTrees(a->right, b->right)
        );
    }

    /* 3. one empty, one not -> false */
    return 0;
}
//subtree
int subtree(struct node* t, struct node* s)
{
if(s==NULL)
return 1;

if(t==NULL)
return 1;

if(identicalTrees(t,s))
return 1;

return (identicalTrees(t->left,s) || identicalTrees(t->right,s));
}

//mirror images
int MirrorTrees(struct node* a, struct node* b)
{
    /*1. both empty */
    if (a==NULL && b==NULL)
        return 1;

    /* 2. both non-empty -> compare them */
    if (a!=NULL && b!=NULL)
    {
        return
        (
            a->data == b->data &&
            MirrorTrees(a->left, b->right) &&
            MirrorTrees(a->right, b->left)
        );
    }

    /* 3. one empty, one not -> false */
    return 0;
}

//child sum property
int ChildsumProperty(struct node* root)
{
if(root == NULL || (root->left==NULL && root->right==NULL))
return 1;
else
{
if(root->data == root->left->data+root->right->data &&
 ChildsumProperty(root->left) &&
 ChildsumProperty(root->right))
return 1;
else
return 0;
}
}
int main()
{
struct node* root=newNode(14);
root->left=newNode(8);
root->right=newNode(6);
root->left->left=newNode(3);
root->left->right=newNode(5);
root->right->left=newNode(4);
root->right->right=newNode(2);

struct node* root1=newNode(1);
root1->left=newNode(3);
root1->right=newNode(2);
root1->left->left=newNode(7);
root1->left->right=newNode(6);
root1->right->left=newNode(5);
root1->right->right=newNode(4);

/*printf("Inorder:");
Inorder(root);
printf("\nPreorder:");
Preorder(root);
printf("\nPostorder:");
Postorder(root);
printf("\n");
printf("Height:%d",height(root));
printf("\nBFS:");
printLevelOrder(root,height(root));
printf("\nDiameter: %d",getDiameter(root));
printf("\n");
printf("\n%d",printAncestors(root,7));
*/
//printf("\n%d",MirrorTrees(root,root1));
printf("\n%d",ChildsumProperty(root));
}
