#include <stdio.h>
#include <stdlib.h>

// Making a struct node for Circular Linked list
struct node
{
    int player_id;
    struct node *next;
};

int main()
{
    int n, k;
    printf("\n Enter the number of players : ");
    scanf("%d", &n);
    printf("\n Enter the value of k (every kth player gets eliminated) : ");
    scanf("%d", &k);

    // Creating Circular Linked list containing all the players
    struct node *start = (struct node *)malloc(sizeof(struct node));
    start->player_id = 1; // First player id = 1

    struct node *ptr = start;

    // Inserting all elements in circular Linked list
    for (int i = 2; i <= n; i++)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        ptr->next = new_node;
        new_node->player_id = i;
        new_node->next = start;
        ptr = new_node;
    }

    // Traversing and eliminating players
    for (int j = 2; j <= n; j++)
    {
        for (int i = 0; i < k - 1; ++i)
        {
            ptr = ptr->next; // Move ptr to next player
        }
        ptr->next = ptr->next->next; // Remove the eliminated player
    }

    // Only one player will be left who is the winner
    printf("\n The Winner is Player %d", ptr->player_id);
    return 0;
}
