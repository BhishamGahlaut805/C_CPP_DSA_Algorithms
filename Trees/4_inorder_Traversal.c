#include <stdio.h>
#include <malloc.h>

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
    {   //Inorder-> left->root->right
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
int main()
{

    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2
    // inorder traversal
    // left root right
    // 5,1,2,4,6 ->Inorder
    // 4,1,5,2,6->Preorder
    // 5,2,1,6,4->postoder

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

    //Original tree
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2
    // Inorder   Traversal : 5 1 2 4 6
    // Preorder  Traversal : 4 1 5 2 6
    // Postorder Traversal : 5 2 1 6 4

    return 0;
}
