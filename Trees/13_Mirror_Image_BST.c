#include <stdio.h>
#include <stdlib.h>

// Define the tree structure
typedef struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
} tree;

// Function for inorder traversal -> left -> root -> right
void inorder(tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);       // Traverse the left subtree
        printf("%d ", root->data); // Print the root's data
        inorder(root->right);      // Traverse the right subtree
    }
}

// Function to create a new node
tree *createNode(int data)
{
    tree *n = (tree *)malloc(sizeof(tree)); // Allocate memory for a new node
    n->data = data;                         // Set the data for the new node
    n->left = NULL;                         // Initialize left child as NULL
    n->right = NULL;                        // Initialize right child as NULL
    return n;                               // Return the created node
}

//Find the Mirror Image of a BST
tree *mirror(tree *root)
{
    if (root != NULL)
    {
        // Recursively call mirror on left and right subtrees
        mirror(root->left);
        mirror(root->right);

        // Swap the left and right children
        tree *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
}

int main()
{
    tree *t = NULL; // Initialize tree root to NULL
    // insert(&t, 3);  // Pass the address of the root
    // insert(&t, 6);
    // insert(&t, 1);
    // insert(&t, 4);
    // insert(&t, 5);

    tree *p = createNode(5);
    tree *p1 = createNode(3);
    tree *p2 = createNode(6);
    tree *p3 = createNode(1);
    tree *p4 = createNode(4);
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
 // Display the tree using inorder traversal
    p = mirror(p);
    printf("\n");
    inorder(p);
    return 0;
}
