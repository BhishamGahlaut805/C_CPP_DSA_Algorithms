#include <iostream>
using namespace std;
class node
{
private:
    /* data */
public:
    int data;
    node *next;
    node(int value)
    {
       this->data = value;
        this->next = NULL;
    }
};
void print(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
// Append k nodes of a Singly linked list to beginning

int length(node *head)
{
    int count = 0;
    node*temp=head;
    while (temp != NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
node* append(node *&head, int index)
{

    node *newhead;
    node *newtail;
    node *tail = head;
    int l = length(head);
    index = index % l;

    int count = 1;
    while (tail->next != NULL)
    {
        if (count == l - index)
        {                   // Reaching to the location of appending
            newtail = tail; // new tail become the location before appending
        }
        // Now assiging new head
        if (count == l - index + 1)
        {
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }
    newtail->next = NULL;
    tail->next = head;
    return newhead;
}
 node *insertatEnd( node *head, int data)
{
     node *ptr = ( node *)malloc(sizeof( node));
    ptr->data = data;
     node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
};

 node *insertatbeginning( node *head, int data)
{
    node *ptr = ( node *)malloc(sizeof( node));
    ptr->data = data;
    ptr->next = head;
    return ptr; // ptr= updated head/linked list
};

int main()
{
    // Allocate memory for linked list in heap
    node *head = (node *)malloc(sizeof(node));
    node *second = (node *)malloc(sizeof(node));
    node *third = (node *)malloc(sizeof(node));
    node *fourth = (node *)malloc(sizeof(node));
    // link first and second nodes
    head->data = 7;
    head->next = second;
    // link second and third nodes
    second->data = 11;
    second->next = third;
    // link third and fourth nodes
    third->data = 66;
    third->next = fourth;
    // terminate the list at fourth node
    fourth->data = 71;
    fourth->next = NULL;
    // append(head,2);
    // print(head);
    
    
    node*list=(node*)malloc(sizeof(node));
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<10;i++){
        insertatbeginning(list,arr[i]);
    }
    
   //append(list, 5);
   print(list);

}