#include <stdio.h>
#include <stdlib.h>

// Threaded Binary trees contain threads which point to its inorder predecessor or successor
// A threaded binary tree is a variation of the binary tree where NULL pointers are replaced with pointers to the in-order predecessor or successor.
// This technique makes in-order traversal faster and more memory-efficient without using a stack or recursion.

// Define the tree structure with an additional 'thread' indicator
typedef struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
    int thread; // 1 if the left pointer is a thread, else 0
} tree;

// Inserting in a left-in Threaded Binary Tree
tree *insert_node(tree *root, tree *ptr, tree *lft)
{
    // Base case: insert the node when the current root is NULL
    if (root == NULL)
    {
        root = ptr;
        if (lft != NULL)
        {
            root->left = lft;
            root->thread = 1; // 1 if the left pointer is a thread
        }
    }
    // If the value to be inserted is less, go to the left subtree
    else if (ptr->data < root->data)
    {
        root->left = insert_node(root->left, ptr, lft);
    }
    // If the value to be inserted is greater or equal, go to the right subtree
    else
    {
        if (root->thread == 1)
        {
            root->left = insert_node(NULL, ptr, root);
            root->thread = 0;
        }
        else
        {
            root->right = insert_node(root->right, ptr, lft);
        }
    }
    return root;
}

// Creating a Threaded Binary Tree by inserting elements
tree *create(tree *root)
{
    tree *ptr;
    int num;
    printf("\nEnter the elements, press -1 to terminate: ");
    scanf("%d", &num);
    while (num != -1)
    {
        ptr = (tree *)malloc(sizeof(tree));
        ptr->data = num;
        ptr->left = ptr->right = NULL;
        ptr->thread = 0;
        root = insert_node(root, ptr, NULL);
        printf("Enter the next element: ");
        scanf("%d", &num);
    }
    return root;
}

// Inorder Traversal of Left-in Threaded Binary Tree
void inorder_threaded(tree *root)
{
    tree *ptr = root;

    // Find the leftmost node
    while (ptr != NULL && ptr->left != NULL && ptr->thread == 0)
    {
        ptr = ptr->left;
    }

    while (ptr != NULL)
    {
        printf(" %d", ptr->data);

        // If the thread is present, follow the thread
        if (ptr->thread == 1)
        {
            ptr = ptr->left;
        }
        else
        {
            // Otherwise, move to the right child and find its leftmost child
            ptr = ptr->right;
            while (ptr != NULL && ptr->left != NULL && ptr->thread == 0)
            {
                ptr = ptr->left;
            }
        }
    }
}

int main()
{
    tree *root = NULL;
    root = create(root); // Pass root by reference to create the tree
    printf("\nThe In-Order Traversal of the Tree can be given as: ");
    inorder_threaded(root);
    return 0;
}
