#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
} node;
int max(int a, int b)
{
    return a > b ? a : b;
}
// Function to get height of tree
int getHeight(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}
// Create node Utility Function
node *create(int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->key = val;
    n->left = NULL;
    n->right = NULL;
    n->height = 1; // Height will be 1 for leaf node because every inserted node will be a leaf node in AVL tree
    return n;
}

// GET balance factor
int getBalanceFactor(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return getHeight(n->left) - getHeight(n->right);
    }
}

// Left Rotation(IN CASE OF RR)
// Right Rotation(IN CASE OF LL)

//      y                                x
//     / \                              / \
//    x   T3    ==>(RIGHT ROTATION)    T1  y
//   / \        (LEFT ROTATION)<==        / \
//  T1  T2                                T2  T3

node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    // Changed nodes
    x->right = y;
    y->left = T2;

    // Updated Heights
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    // return updated root
    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    // Updated Heights
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    // return updated root
    return y;
}

// Insertion in AVL
node *insert(node *n, int key)
{
    if (n == NULL)
    {
        return create(key);
    }

    if (key < n->key)
    {
        n->left = insert(n->left, key);
    }
    else if (key > n->key)
    {
        n->right = insert(n->right, key);
        return n;
    }

    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    int bf = getBalanceFactor(n);

    // left-left case
    if (bf > 1 && key < n->left->key)
    {
        return rightRotate(n);
    }

    // right-right case
    if (bf < -1 && key > n->right->key)
    {
        return leftRotate(n);
    }

    // left-right case
    if (bf > 1 && key > n->left->key)
    {
        n->left = leftRotate(n->left); // Firstly left rotate child node (left) of First Inbalance node(FIB)
        return rightRotate(n);         // Then Right Rotate FIB
    }

    // right-left case
    if (bf < -1 && key < n->right->key)
    {
        n->right = rightRotate(n->right); // Firstly right rotate child node (right) of First Inbalance node(FIB)
        return leftRotate(n);             // Then left Rotate FIB
    }

    // returning n as it is not changed
    return n;
}

// Insertion in AVL
node *insert1(node *n, int key)
{
    if (n == NULL)
    {
        return create(key);
    }

    if (key < n->key)
    {
        n->left = insert(n->left, key);
    }
    else if (key > n->key)
    {
        n->right = insert(n->right, key);
    }
    else
    {
        // Duplicate keys not allowed
        return n;
    }

    // Update height of this node
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));

    // Get the balance factor of this node
    int bf = getBalanceFactor(n);

    // Left-Left Case
    if (bf > 1 && key < n->left->key)
    {
        return rightRotate(n);
    }

    // Right-Right Case
    if (bf < -1 && key > n->right->key)
    {
        return leftRotate(n);
    }

    // Left-Right Case
    if (bf > 1 && key > n->left->key)
    {
        n->left = leftRotate(n->left); // Firstly left rotate child node (left) of First Imbalance node(FIB)
        return rightRotate(n);         // Then Right Rotate FIB
    }

    // Right-Left Case
    if (bf < -1 && key < n->right->key)
    {
        n->right = rightRotate(n->right); // Firstly right rotate child node (right) of First Imbalance node(FIB)
        return leftRotate(n);             // Then Left Rotate FIB
    }

    // returning n as it is not changed
    return n;
}

// Function for InOrder Traversal

void inorder(struct node *root)
{
    if (root != NULL)
    { // Inorder-> left->root->right
        inorder(root->left);
        printf("%d ", root->key);
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
        printf("%d ", root->key);
    }
}

// Function for preOrder Traversal

void preorder(struct node *root)
{
    // preorder->root->left->right
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    node *root = NULL;
    root = insert(root, 11);
    root = insert(root, 2);
    root = insert(root, 42);
    root = insert(root, 52);
    root = insert(root, 6);
    root = insert(root, 30);

    printf("\nPreorder : ");
    preorder(root);
    printf("\ninorder : ");
    inorder(root);
    printf("\n");
    postorder(root);

    //       11
    //      /  \
    //     2    42
    //      \  /  \
    //       6 30  42
}
