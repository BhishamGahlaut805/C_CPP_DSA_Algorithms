/***The Josephus Problem**

The Josephus problem involves n people standing in a circle waiting to be executed. The counting starts at some point in the circle and proceeds in a specific direction. In each step, a certain number of people are skipped, and the next person is executed (or eliminated). The elimination of people makes the circle smaller and smaller. At the last step, only one person remains, who is declared the ‘winner’.

Therefore, if there are n people and a number k which indicates that k-1 people are skipped and the kth person in the circle is eliminated, then the problem is to choose a position in the initial circle so that the given person becomes the winner.

**Example:**

- If there are 5 people and every second person is eliminated:
  - First, the person at position 2 is eliminated.
  - Followed by the person at position 4.
  - Followed by the person at position 1.
  - Finally, the person at position 5 is eliminated.
  - Therefore, the person at position 3 becomes the winner.*/

// Write a program which finds the solution of Josephus problem using a circular linked list.

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
    printf("\n Enter the value of k(every kth player gets eliminated) : ");
    scanf("%d", &k);

    // Creating Circular Linked list containing all the players

    struct node *start = (struct node *)malloc(sizeof(struct node));
    start->player_id = 1; // First player id=1

    struct node *ptr = start;
    ptr = start; // will work on ptr

    // Inserting(at head)all elements in circular Linked list
    //(at head)->no matter as list is circular
    for (int i = 2; i <= n; i++)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        ptr->next = new_node;
        new_node->player_id = i;
        new_node->next = start;
        ptr = new_node;
    }

    for (int j = 2; j <= n; j++)
    {                               // Traversing whole players
        for (int i = 0; i < k - 1; ++i)
        {                    // loop will execute the number pf times the (k) as kth person is to be eliminated
            ptr = ptr->next; // Till the number of times inner loop runs ->move ptr to next(player)
        }
        ptr->next = ptr->next->next; // Removing the eliminated player from the Circular Linked list
    }

    // After all this,Only one player will be left who is the winner
    printf("\n The Winner is Player %d", ptr->player_id);
    return 0;
}

