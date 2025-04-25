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
void inorder(struct node *root)
{
    if (root != NULL)
    {                                               // Inorder-> left->root->right
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Insertion in a Tree

void insert_BST(struct node *root, int value)
{
    struct node *prev = NULL;                       // Holding 1 pointer behind the root node
    struct node *new = createNode(value);           // To be inserted node
    if (root == NULL)                               // If root is NULL
    {
        root = new;                                 // Make root the value itself
    }
    while (root != NULL)
    {
        prev = root;
        if (root->data == value)
        {
            printf("\nValue already exits in Tree\n");
            return;
        }
        else if (root->data < value)
        {
            root = root->right;                     // Making right node the root node to procede further
        }
        else
        {
            root = root->left;                      // Making left node the root node to procede further
        }
    // Now the prev pointer is pointing to the last value (to be inserted location)
    // Linking nodes
    if (prev->data < value)
    {
        prev->right = new;                          // value inserted at right
    }
    else
    {
        prev->left = new;                           // Value inserted at left
    }
}
}

// Deletion in a BST
struct node *inOrderPredecessor(struct node *root)
{
    // inorderpredecessor is rightmost child of left subtree

    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
// Deletion strategy is to replace node by its inorder predecessor/postdecessor

struct node *delete_BST(struct node *root, int value)
{
    struct node *ipre;                                  // making node for inorder predecesssor
    if (root == NULL)
    {
        return NULL; // BASE condition1
    }
    if (root->left == NULL && root->right == NULL)      // Means there is only root node
    {                                                   // Base Condition2 to terminate recursive calls
        free(root);                                     // delete root node
        return NULL;
    }

    // Searching for node to be deleted
    if (value < root->data)
    {
        root->left = delete_BST(root->left, value);      // Value is at left subtree
    }
    else if (value > root->data)
    {
        root->right = delete_BST(root->right, value);     // Value is at right subtree
    }

    // Deletion strategy when node is found
    else
    {
        ipre = inOrderPredecessor(root);
        root->data = ipre->data;                            // replacing root by ipre
        root->left = delete_BST(root->left, ipre->data);    // now to be deleted value is ipre
    }
    return root;
}

//Delete a Complete BST
struct node*delete(struct node*root){
    if(root!=NULL){
        delete (root->left);
        delete (root->right);
        free(root);
    }
    root = NULL;    //Making root=NULL to avoid being dangling
    return root;
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
    inorder(p);
    printf("\nDeleting 5 from BST...");
    delete_BST(p, 5);
    inorder(p);
    p=delete (p);
    printf("\nBST after deleting all node is\n");
    inorder(p);
    printf("Now Creating root again\n");
    p = createNode(5);
    printf("Inorder Traversal : ");
    inorder(p);
}
