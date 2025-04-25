#include <stdio.h>
#include <stdlib.h>

// Define the tree node structure
typedef struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
    int lthread; // 1 if left pointer is a thread
    int rthread; // 1 if right pointer is a thread
} tree;

// Function to create a new node
tree *createNode(int data)
{
    tree *n = (tree *)malloc(sizeof(tree));
    n->data = data;
    n->left = n->right = NULL;
    n->lthread = n->rthread = 1; // Initially, left and right are threads pointing to NULL
    return n;
}

// Inserting a node into a fully threaded binary tree
tree *insert(tree *root, int key)
{
    tree *ptr = root;
    tree *par = NULL; // Parent of key to be inserted

    while (ptr != NULL)
    {
        // If key already exists, return
        if (key == ptr->data)
        {
            return root;
        }

        par = ptr; // Update parent pointer

        if (key < ptr->data)
        {
            if (ptr->lthread == 0)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (ptr->rthread == 0)
                ptr = ptr->right;
            else
                break;
        }
    }

    tree *tmp = createNode(key);

    if (par == NULL)
    {
        root = tmp;
    }
    else if (key < par->data)
    {
        tmp->left = par->left;
        tmp->right = par;
        par->lthread = 0;
        par->left = tmp;
    }
    else
    {
        tmp->left = par;
        tmp->right = par->right;
        par->rthread = 0;
        par->right = tmp;
    }

    return root;
}

// Inorder traversal of a fully threaded binary tree
void inorder(tree *root)
{
    tree *ptr = root;
    if (root == NULL)
        return;

    // Go to the leftmost node
    while (ptr->lthread == 0)
    {
        ptr = ptr->left;
    }

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);

        if (ptr->rthread == 1)
        {
            ptr = ptr->right;
        }
        else
        {
            ptr = ptr->right;
            while (ptr != NULL && ptr->lthread == 0)
            {
                ptr = ptr->left;
            }
        }
    }
}

int main()
{
    tree *root = NULL;

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 14);
    root = insert(root, 17);
    root = insert(root, 13);

    printf("Inorder Traversal of Fully Threaded Binary Tree:\n");
    inorder(root);

    return 0;
}
