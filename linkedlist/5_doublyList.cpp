#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *pre;
    node *next;
    node(int value)
    {
        data = value;
        pre = NULL;
        next = NULL;
    }
};
void traversal(node *head)
{
    // while(head!=NULL){
    //     cout<<"First Case Element:\n"<<head->data<<" "<<endl;
    //     head=head->next;
    // }

    // Doubly circular Linked list printing top and bottom
    node *ptr = (node *)malloc(sizeof(node));
    ptr = head;
    do
    { // cout<<"Second Case Element:\n"<<ptr->data<<" "<<endl;
        cout << ptr->data << " ";
        ptr = ptr->next;

    } while (ptr != head);

    node *ptr1 = (node *)malloc(sizeof(node));
    ptr1 = ptr;
    do
    {
        // cout<<"Third Case Element:\n"<<ptr1->data<<" "<<endl;
        ptr1 = ptr1->pre;
        cout << ptr1->data << " ";

    } while (ptr1 != ptr);
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
    head->pre = fourth;
    // link second and third nodes
    second->data = 11;
    second->next = third;
    second->pre = head;
    // link third and fourth nodes
    third->data = 66;
    third->next = fourth;
    third->pre = second;
    // terminate the list at fourth node
    fourth->data = 71;
    fourth->next = head;
    fourth->pre = third;

    traversal(head);
}