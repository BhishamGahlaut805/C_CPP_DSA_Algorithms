#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

// Structure of a Binary Tree
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

struct node *tree = NULL;

// 1. Create a Binary Search Tree
struct node *create_BST(int key)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = key;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

// 2. Insert an Element in a BST
struct node *insert_BST(struct node *root, int key)
{
    struct node *ptr = root;
    struct node *prev = NULL;
    struct node *newNode = create_BST(key);

    if (ptr == NULL)
    {
        return newNode;
    }

    while (ptr != NULL)
    {
        prev = ptr;
        if (ptr->data == key)
        {
            printf("\nValue Already exists in BST");
            return root;
        }
        else if (ptr->data < key)
        {
            ptr = ptr->right;
        }
        else
        {
            ptr = ptr->left;
        }
    }

    if (prev->data < key)
    {
        prev->right = newNode;
    }
    else
    {
        prev->left = newNode;
    }
    return root;
}

// 3. PreOrder Traversal
void preorder_BST(struct node *root)
{
    if (root != NULL)
    {
        printf("%d => ", root->data);
        preorder_BST(root->left);
        preorder_BST(root->right);
    }
}

// 4. InOrder Traversal
void inorder_BST(struct node *root)
{
    if (root != NULL)
    {
        inorder_BST(root->left);
        printf("%d => ", root->data);
        inorder_BST(root->right);
    }
}

// 5. PostOrder Traversal
void postorder_BST(struct node *root)
{
    if (root != NULL)
    {
        postorder_BST(root->left);
        postorder_BST(root->right);
        printf("%d => ", root->data);
    }
}

// 6.Iterative PreOrder-Traversal
node *stack[10];
int top = -1;

void push_st(node *val)
{
    if (top < 9)
    { // Check to avoid overflow
        stack[++top] = val;
    }
    else
    {
        cout << "Stack overflow" << endl;
    }
}

void pop_st()
{
    if (top >= 0)
    { // Check to avoid underflow
        top--;
    }
    else
    {
        cout << "Stack underflow" << endl;
    }
}

node *top_st()
{
    if (top >= 0)
    {
        return stack[top];
    }
    else
    {
        return NULL; // Return nullptr if stack is empty
    }
}

bool isempty()
{
    return top == -1;
}

void PreOrder_iterative(node *root)
{
    // Base Case
    if (root == NULL)
    {
        printf("\nNo Elements in Tree");
        return;
    }

    else
    {
        push_st(root);
        while (!isempty())
        {
            node *n = top_st();
            printf("%d => ", n->data);
            pop_st();

            // We are pushing right first because we want to access left first(Stack LIFO)
            if (n->right)
            {
                push_st(n->right);
            }
            if (n->left)
            {
                push_st(n->left);
            }
        }
    }
}

// 6.Iterative Inorder-Traversal
node *stack1[10];
int top1 = -1;

void push_st1(node *val)
{
    if (top1 < 9)
    { // Check to avoid overflow
        stack1[++top1] = val;
    }
    else
    {
        cout << "Stack overflow" << endl;
    }
}

void pop_st1()
{
    if (top1 >= 0)
    { // Check to avoid underflow
        top1--;
    }
    else
    {
        cout << "Stack underflow" << endl;
    }
}

node *top_st1()
{
    if (top1 >= 0)
    {
        return stack1[top1];
    }
    else
    {
        return NULL; // Return nullptr if stack is empty
    }
}

bool isempty1()
{
    return top1 == -1;
}

void InOrder_iterative(node *root)
{
    // Base Case
    if (root == NULL)
    {
        printf("\nNo Elements in Tree");
        return;
    }

    node *current = root;
    while (current != NULL || !isempty1())
    {
        while (current != NULL)
        {
            push_st1(current);
            current = current->left;
        }

        current = top_st1();
        pop_st1();
        printf("%d => ", current->data);

        current = current->right;
    }
}

int main()
{
    int option;
    int val;

    do
    {
        printf("\n****All Operations of a Binary Search Tree****\n");
        printf("\n 1. Create a Binary Search Tree");
        printf("\n 2. Insert an Element in Binary Search Tree");
        printf("\n 3. PreOrder Traversal of a Binary Search Tree");
        printf("\n 4. InOrder Traversal of a Binary Search Tree");
        printf("\n 5. PostOrder Traversal of a Binary Search Tree");
        printf("\n 6. Find the Smallest Element in a Binary Search Tree");
        printf("\n 7. Find the Largest Element in a Binary Search Tree");
        printf("\n 8. Delete a element in a Binary Search Tree");
        printf("\n 9. Count the Total number of nodes in a Binary Search Tree");
        printf("\n 10. Count the Total number of external nodes in a Binary Search Tree");
        printf("\n 11. Count the Total number of internal nodes in a Binary Search Tree");
        printf("\n 12. Determine the Height of a Binary Search Tree");
        printf("\n 13. Find the Mirror image of a Binary Search Tree");
        printf("\n 14. Delete the Binary Search Tree");
        printf("\n 15. Iterative Search in Binary Search Tree");
        printf("\n 16. Recursive Search in Binary Search Tree");
        printf("\n 17. Exit");
        printf("\n Enter an option as per your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\n Enter the value of a node to create a BST: ");
            scanf("%d", &val);
            tree = create_BST(val);
            printf("\n Tree created successfully");
            break;
        case 2:
            printf("\n Enter the value to be inserted in BST: ");
            scanf("%d", &val);
            tree = insert_BST(tree, val);
            break;
        case 3:
            printf("\n PreOrder Traversal\n");
            printf("Recursive : ");
            preorder_BST(tree);
            printf("\nIterative : ");
            PreOrder_iterative(tree);
            break;
        case 4:
            printf("\n InOrder Traversal\n");
            printf("Recursive : ");
            inorder_BST(tree);
            printf("\nIterative : ");
            InOrder_iterative(tree);
            break;
        case 5:
            printf("\n PostOrder Traversal\n");
            postorder_BST(tree);
            break;
        }
    } while (option != 17);

    return 0;
}
