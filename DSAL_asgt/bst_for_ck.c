#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
    int count;
    char *s;
    struct Node *left;
    struct Node *right;
}node;
typedef struct vector_str{
char *s;
}vector ;
node *root=NULL;
void create_node_str(node **ver,char str[]){
    *ver=(node*)(malloc(sizeof(node)));
    if((*ver)==NULL){
        printf("memory allocation is failed\n");
        exit(1);
    }
    (*ver)->count=1;
    (*ver)->s=(char *)(malloc(sizeof(char)*(strlen(str)+1)));
    (*ver)->left=NULL;
    (*ver)->right=NULL;
}
void insert(char str[]){
    if(root==NULL){
        node *new;
        create_node_str(&new,str);
        root=new;
        return;
    }
    node *cptr=root;
    int val=0;
    while(1){
        val=strcmp(cptr->s,str);
        if(val==0){
            (cptr->count)++;
            return;
        }
        else if(val==-1){
            if(cptr->left!=NULL)cptr=cptr->left;
            else break;
        }
        else {
            if(cptr->right!=NULL)cptr=cptr->right;
            else break;
        }
    }
    node *new;
    create_node_str(&new,str);
    if(val==-1)cptr->left=new;
    else cptr->right=new;
    
}


int main() {
    
}

    /*
    #include <stdio.h>
#include <stdlib.h>

int main() {
    char *s;
    s = (char *)malloc(sizeof(char) * 100);  // Allocate memory for the string

    // Read input using scanf and check for EOF
    while (scanf("%s", s) != EOF) {
        printf("%s\n", s);  // Print the entered word
    }

    free(s);  // Free the allocated memory

    return 0;
}

    */