#include <stdio.h>
#include <stdlib.h>

// Define the tree structure
typedef struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
} tree;

// Function to perform inorder traversal
//Inorder Traversal of a Binary Search Tree is in ascending Order
void inorder(tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to create a new node
tree *createNode(int data)
{
    tree *n = (tree *)malloc(sizeof(tree));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function to find the smallest node in a BST
tree *smallest(tree *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// Function to find the largest node in a BST
tree *largest(tree *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

int main()
{
    // Creating nodes manually
    tree *p = createNode(5);
    tree *p1 = createNode(3);
    tree *p2 = createNode(6);
    tree *p3 = createNode(1);
    tree *p4 = createNode(4);

    // Constructing the tree
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // Display the tree using inorder traversal
    printf("Inorder traversal: ");
    inorder(p);
    printf("\n");

    // Find and display the largest and smallest nodes
    tree *l = largest(p);
    tree *s = smallest(p);
    printf("Largest element is: %d\n", l->data);
    printf("Smallest element is: %d\n", s->data);

    return 0;
}
