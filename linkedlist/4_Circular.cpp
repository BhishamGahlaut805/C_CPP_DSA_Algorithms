#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next=NULL;
    }
};

void print(node *ptr)

{
    node*head=ptr;
    do
    {
        cout << head->data << " ";
        head= head->next;
    } while (head != ptr);
}

//Insertion at head of a circular linked list

node*insertatHead(node* head,int data){
    node*ptr= (node*)malloc(sizeof(node));
    ptr->data=data;
    node*p=head->next;
    while (p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
    
};
//Insert at tail of a Circular Linked List
node*insertatTail(node* head,int data){
    node*ptr= (node*)malloc(sizeof(node));
    ptr->data=data;
    node*p=head->next;
    while (p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    
    return head;
    
};

int main()
{
    // Allocate memory for linked list in heap
     node *head = ( node *)malloc(sizeof( node));
     node *second = ( node *)malloc(sizeof( node));
     node *third = ( node *)malloc(sizeof( node));
     node *fourth = ( node *)malloc(sizeof( node));

     cout << "Circular Linked list before insertion \n";
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
    fourth->next = head;
    print(head);
    cout<<"\nCircular Linked List after insertion at head"<<endl;
    node*newlist=insertatHead(head,100);
    print(newlist);
    cout<<"\nCircular Linked List after insertion at Tail"<<endl;
    node*newlist1=insertatHead(head,100);
    print(newlist1);
}