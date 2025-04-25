//Inorder traversal of a binary search tree is in ascending order
#include <stdio.h>
#include <malloc.h>
#include<stdbool.h>

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

// Function for preOrder Traversal

void inorder(struct node *root)
{
    if (root != NULL)
    { // Inorder-> left->root->right
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function for preOrder Traversal

void postorder(struct node *root)
{ // postorder->left->right->root
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function for preOrder Traversal

void preorder(struct node *root)
{
    // preorder->root->left->right
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//Check is A BT is A BST or Not
//Same as Inorder traversal
//Modified Version of inorder traversal

bool is_bst(struct node*root){
    static struct node *prev = NULL;

    if(root!=NULL){
        if(!is_bst(root->left)){    //Traversing to left subtree
            return false;
        }
        if(prev!=NULL && root->data<= prev->data){  //For root node
            return false;
        }

        prev = root;
        return is_bst(root->right);
        //Traversing to right subtree
    }
    else{
        return true;
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

    printf("Inorder   Traversal : ");
    inorder(p);
    printf("\nPreorder  Traversal : ");
    preorder(p);
    printf("\nPostorder Traversal : ");
    postorder(p);

    // if(is_bst(p)){
    //     printf("\nYes it's a BST\n");
    // }
    // else{
    //     printf("\nNOT BST \n");
    // }

    return 0;
}
