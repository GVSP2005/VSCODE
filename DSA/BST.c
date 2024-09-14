#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
int value;
int height;
struct Node* left;
struct Node*right;
struct Node*parent;

}node;
node *root;
void create_node(node **ptr){
    /*think in this way if you use *x you can change x
    if **x you can change *x;
    here i have to change some random value of *root to a memory 
    in main you use x=2;
    but in function u use *x=2 to change
    similarly in main u use ptr here u have to use *ptr so that change is stored;

    */
    *ptr=(node *)(malloc(sizeof(node)));
    //*ptr=NULL;we shouldn't do like this 
    // if malloc is failed then it returns null but here we are assigning it to null
    // so it may cause errors;
    if(*ptr==NULL){
        printf("Sorry failed to allocate\n"),exit(1);
    }
    else
    (*ptr)->left=NULL,(*ptr)->right=NULL,
    (*ptr)->parent=NULL;
    (*ptr)->height=0;    
}
int h_tree(node *root){
    if(root==NULL)return 0;
    else return root->height;
}
void insert(int value){
    node *new;
    create_node(&new);
    
    new->value=value;
    
node *currptr=root;
node *parent=NULL;

while(currptr!=NULL){parent=currptr;
    if(currptr->value>value)currptr=currptr->left;
    else currptr=currptr->right;
}
if(parent==NULL){
    root=new;
    return;
}
if(parent->value>value)parent->left=new;
else parent->right=new;
new->parent=parent;

}

node* mini(node *root){


    if(root==NULL)
    return root;
while(root->left!=NULL)root=root->left;
return root;


}
node *maxi(node*root){


    if(root!=NULL){
        while(root->right!=NULL)root=root->right;
        return root;
    }
    printf("Tree is empty\n");


}

node* suc(node *n){


if(n->right!=NULL){
    return mini(n->right);
}
else{
    node *parent=n->parent;
    while(parent!=NULL&&parent->right==n){
        n=n->parent;
        parent=parent->parent;
    }
    return parent;
}


}


node* pre(node *n){

if(n->left!=NULL)return maxi(n->left);
else{
    node *parent=n->parent;
    while(parent!=NULL&&parent->left==n){
    n=n->parent;
    parent=parent->parent;
    }
    return parent;
}

}

void inorder_walk(node*root){
if(root==NULL)return;
//printf("entered with value:%d ",root->value);
inorder_walk(root->left);
printf("%d ->",root->value);
inorder_walk(root->right);
}
//write delete
int main(){//create_node(&root);
int a[]={50,25,75,15,30,60,80,29,28};
for(int i=0;i<9;i++)insert(a[i]);
node *new=NULL;
new=maxi(root);
while(new!=NULL){
    printf("%d is predecessor of %d\n",pre(new)->value,new->value);
    new=pre(new);
}




}