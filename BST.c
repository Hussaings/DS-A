#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

struct node* insert(struct node* root,int key)
{
if (root==NULL)
return newNode(key);

if(key<root->key)
root->left=insert(root->left,key);
else
root->right=insert(root->right,key);

return root;
}

//search in BST
void search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root==NULL || root->key == key){
       printf("Value Found");
       return;
       }

    if (key < root->key)
       search(root->left, key);
    else
       search(root->right, key);
}

//min value
int minValue(struct node* node) {
  struct node* current = node;

  /* loop down to find the leftmost leaf */
  while (current->left != NULL) {
    current = current->left;
  }
  return (current->key);
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);


    inorder(root);
    search(root,40);
    printf("\nMIN VALUE: %d",minValue(root));
}
