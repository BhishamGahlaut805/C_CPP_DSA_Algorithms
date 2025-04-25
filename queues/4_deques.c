#include <stdio.h>
#define max 10
// deques->insertions and deletions can be done from both the sides
// 1.Input restricted Deques->Insertion from one end and Deletion from both ends
// 2.Output restricted Deques->Insertion from both ends and Deletion from one end

int deque[max];
int back = -1, front = -1;

void output_deque(void);
void insert_left(void);
void insert_right(void);
void delete_left(void);
void delete_right(void);
void display(void);

// 1.Insertion in a deque->from right

void input_deque()
{
    int option;
    do
    {
        printf("\n INPUT RESTRICTED DEQUE");
        printf("\n 1.Insert at right");
        printf("\n 2.Delete from left");
        printf("\n 3.Delete from right");
        printf("\n 4.Display");
        printf("\n 5.Exit");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert_right();
            break;
        case 2:
            delete_left();
            break;
        case 3:
            delete_right();
            break;
        case 4:
            display();
            break;
        }
    } while (option != 5);
}

// 2.Output Restricted Deque

void output_deque()
{
    int option;
    do
    {
        printf(" \n OUTPUT RESTRICTED DEQUE");
        printf("\n 1.Insert at right");
        printf("\n 2.Insert at left");
        printf("\n 3.Delete from left");
        printf("\n 4.Display");
        printf("\n 5.Exit");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert_right();
            break;
        case 2:
            insert_left();
            break;
        case 3:
            delete_left();
            break;
        case 4:
            display();
            break;
        }
    } while (option != 5);
}

void insert_right()
{
    int val;
    printf("\n Enter the value to be added:");
    scanf("%d", &val);
    if ((back == 0 && front == max - 1) || (back == front + 1))
    {
        printf("\n Deque Overflow ");
        return;
    }
    if (back == -1)
    { // queue is empty initially
        back = 0;
        front = 0;
    }
    else
    {
        if (front == max - 1)
        { // front is at last position of queue
            front = 0;
        }
        else
        {
            front++;
        }
    }
    deque[front] = val;
}

// 2.Insert from left

void insert_left()
{
    int val;
    printf("\n Enter the value to be added:");
    scanf("%d", &val);
    if ((back == 0 && front == max - 1) || (back == front + 1))
    {
        printf("\n Deque Overflow ");
        return;
    }
    if (back == -1)
    { // queue is empty initially
        back = 0;
        front = 0;
    }
    else
    {
        if (back == 0)
        {                   // back is at starting position of queue
            back = max - 1; // shifting back to the last
        }
        else
        {
            back--;
        }
    }
    deque[back] = val;
}

// 3.delete_left

void delete_left()
{
    if (back == -1)
    {
        printf("\n Deque is empty ");
        return;
    }
    printf("\n The deleted Element is : %d \n ", deque[back]);
    if (back == front)
    { // Only one element in Queue
        back = -1;
        front = -1;
    }
    else
    {
        if (back == max - 1)
        {
            back = 0;
        }
        else
        {
            back++;
        }
    }
}

// 4.delete_right

void delete_right()
{
    if (back == -1)
    {
        printf("\n Deque is empty ");
        return;
    }
    printf("\n The deleted Element is : %d \n ", deque[front]);
    if (back == front)
    { // Only one element in Queue
        back = -1;
        front = -1;
    }
    else
    {
        if (front == 0)
        { // At starting
            front = max - 1;
        }
        else
        {
            front--;
        }
    }
}

// 5.Display
void display()
{

    int f = front;
    int r = back;
    if (f == -1)
    {
        printf("\n Deque is empty ");
        return;
    }
    printf("\n The Elements of the Deque are ");

    if (r <= f)
    {
        while (r <= f)
        {
            printf("%d ", deque[r]);
            r++;
        }
    }
    else
    {
        while (f <= max - 1)
        {
            printf("%d ", deque[f]);
            f++;
        }
        f = 0;
        // Check if any element is left then print it
        while (r <= f)
        {
            printf("%d ", deque[r]);
            r++;
        }
    }
    printf("\n");

    // Or

    // for(int i=f;i!=r;i=(i+1)%max){
    //     printf("%d ",deque[i]);
    // }
    //  printf("%d ",deque[back]);
}

int main()
{
    int option;

    printf("\n *****MAIN MENU*****\n");
    printf("\n 1.Input restricted deque");
    printf("\n 2.Output restricted deque\n");
    printf("Enter your option : ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        input_deque();
        break;
    case 2:
        output_deque();
        break;
    }
    return 0;
}
