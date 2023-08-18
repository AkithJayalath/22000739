#include <stdio.h>
#include <stdlib.h>

struct binarytree{
int data;
struct binarytree *left;
struct binarytree *right;
};
struct binarytree* createNode(int data);
struct binarytree* insert(struct binarytree* root,int data);
void deletemin(struct binarytree** root,int *array);

int main(void) {
  struct binarytree* root=NULL;

  root=insert(root,10);
  insert(root,5);
  insert(root,15);
  insert(root,8);
  insert(root,12);
  insert(root,20);
  insert(root,9);
  insert(root,14);
  insert(root,17);
  insert(root,25);
  insert(root,30);
  insert(root,22);
  
  int array[12];
  deletemin(&root,array);
  return 0;
}
struct binarytree* createNode(int data){
  struct binarytree* newnode=(struct binarytree*)malloc(sizeof(struct binarytree));
  newnode->data=data;
  newnode->left=NULL;
  newnode->right=NULL;
  return newnode;
}

struct binarytree* insert(struct binarytree* root,int data){
  if(root==NULL){
    return createNode(data);
  }
  if(root->data>data){
    root->left=insert(root->left,data);
  }else{
    root->right=insert(root->right,data);
  }
   return root; 
}

void deletemin(struct binarytree** root,int *array){
  int i=0;
// Deleting nodes in ascending order
while (*root!=NULL){
  struct binarytree* current=*root;
  struct binarytree* parent=NULL;

  while(current->left!=NULL){
    parent=current;
    current=current->left;
  }
  int min =current->data;
  if(parent!=NULL){
    parent->left=current->right;
  }else{
    *root=current->right;
  }
// Adding the deleting node->data to the array
  array[i]=min;
  i++;
  free(current);
}

// Printing the array
printf("Output Array :");
for(int j=0;j<i;j++){
    printf("\t%d",array[j]);
}
}