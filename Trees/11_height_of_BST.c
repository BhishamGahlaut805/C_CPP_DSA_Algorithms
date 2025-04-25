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

// Function to insert a new node in BST
void insert(tree **root, int val)
{
    tree *new = createNode(val);
    tree *prev = NULL;
    tree *current = *root;

    if (*root == NULL)
    {
        *root = new; // If the tree is empty, make the new node the root
        return;
    }

    // Traverse the tree to find the correct insertion point
    while (current != NULL)
    {
        prev = current;
        if (current->data == val)
        {
            printf("\nValue already exists in Tree\n");
            return;
        }
        else if (current->data < val)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    // Insert the new node at the correct position
    if (prev->data < val)
    {
        prev->right = new;
    }
    else
    {
        prev->left = new;
    }
}
//Find the Height of A BST

// Function to find the height of a BST
int height(tree *root)
{
    // Base case: If the tree is empty, the height is 0
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        // Recursive case: Calculate the height of left and right subtrees
        int leftheight = height(root->left);
        int rightheight = height(root->right);

        // Return the larger height of the two, plus one to include the current node
        if (leftheight > rightheight)
        {
            return leftheight + 1;
        }
        else
        {
            return rightheight + 1;
        }
    }
}
//Total Nodes in a BST

int totalnodes(tree*root){
    if(root==NULL){
        return 0;
    }
    else{
        return totalnodes(root->left) + totalnodes(root->right) + 1;
    }
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

    inorder(p); // Display the tree using inorder traversal
    printf("\nHeight of BST is : %d ", height(p));
    printf("\nTotal Number of Nodes in BST : %d ", totalnodes(p));
    return 0;
}
