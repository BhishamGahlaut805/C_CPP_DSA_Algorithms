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
    { // Inorder-> left->root->right
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
// Recursive Binary Search in a Binary Search Tree
// Same as in Binary search
struct node *search_iterative(struct node *root, int value)
{
    struct node *p = root;
    while (p != NULL)
    { // Loop run while root!=NULL
        if (p == NULL)
        {
            return NULL;
        }
        else if (p->data == value)
        {
            return p;
        }
        else if (p->data < value)
        {
            p = p->right; // Making right node the root node to procede further
        }
        else
        {
            p = p->left; // Making left node the root node to procede further
        }
    }
}

// Insertion in a Binary Search Tree

void insert_BST(struct node *root, int value)
{
    struct node *prev = NULL;           // Holding 1 pointer behind the root node
    struct node *new = createNode(value); // To be inserted node
    if (root == NULL)                   // If root is NULL
    {
        root = new; // Make root the value itself
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
            root = root->right; // Making right node the root node to procede further
        }
        else
        {
            root = root->left; // Making left node the root node to procede further
        }
    }
    // Now the prev pointer is pointing to the last value (to be inserted location)
    //Linking nodes
    if (prev->data < value)
    {
        prev->right = new; // value inserted at right
    }
    else
    {
        prev->left = new; // Value inserted at left
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
    printf("Original BST : ");
    inorder(p);

    insert_BST(p, 10);
    printf("\nAfter inserting 10 : ");
    inorder(p);

    printf("\nInserting 4 : ");
    insert_BST(p, 4);
    inorder(p);

    insert_BST(p, 7);
    printf("\nAfter inserting 7 : ");
    inorder(p);


}