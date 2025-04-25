#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}

//Recursive Binary Search in a Binary Search Tree
//Same as in Binary search
struct node* search_BST(struct node*root,int value){
    struct node *p = root;
    if(p==NULL){
        return NULL;
    }
    else if(p->data==value){
        return p;
    }
    else if(p->data<value){
        search_BST(p->right, value);
    }
    else {
        search_BST(p->left, value);
    }

}
int main()
{

    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

   struct node*n= search_BST(p, 1);
   if(n!=NULL){
       printf("Value found");

   }
   else{
       printf("Value not found");
   }

}