#include <iostream>
using namespace std;

class node
{
private:
    /* data */
public:
    int data;
    node *next;
    node *pre;
    node(int value)
    {
        data = value;
        pre = NULL;
        next = NULL;
    }
};

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
};

void insertAtBegin(node *&head, int value)
{
    node *n = new node(value);
    n->next = head;
    if (head != NULL)
    {
        head->pre = n;
    }
    head = n;
}
void insertAtEnd(node *&head, int value)
{
    if (head == NULL)
    {
        insertAtBegin(head, value);
        return;
    }
    node *n = new node(value);
    node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = n;
    n->pre = ptr;
    // n->next=NULL;//Self Understood
}

void deleteAtHead(node *&head)
{
    node *ptr = head;
    head = head->next;
    head->pre = NULL;
    delete ptr;
}
void deleteAtTail(node *&head, int pos)
{

    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    node *ptr = head;
    int count = 1;
    while (ptr != NULL && count != pos)
    {
        ptr = ptr->next;
        count++;
    }

    ptr->pre->next = ptr->next;
    if (ptr->next != NULL)
    {
        ptr->next->pre = ptr->pre;
    }
    delete ptr;
}

int main()
{
    node *list = NULL;

    insertAtEnd(list, 5);
    insertAtEnd(list, 2);
    insertAtEnd(list, 3);
    insertAtEnd(list, 4);
    insertAtEnd(list, 6);
    print(list);

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 5; i++)
    {
        insertAtEnd(list, arr[i]);
    }
    print(list);
    deleteAtTail(list, 2);
    print(list);
    deleteAtTail(list, 1);
    print(list);

    //Inputing a linked list

    // int n;
    // int array[n];
    // node*list1=NULL;
    // int pos;
    // int arr1[100];

    // cout<<"Enter size of linked list\n";
    // cin>>n;
    // cout<<"Enter Linked list elements\n";
    // for(int i=0;i<n;i++){
    //     cin>>array[i];
    //     array[i]=arr1[i];
       
    // }
    // for(int i=0;i<n;i++){
    //     insertAtEnd(list1,arr1[i]);
    // }
    // cout<<"Your Linked List is:\n";
    // print(list1);

    // cout<<"Enter position to delete\n";
    // cin>>pos;

    // deleteAtTail(list1,pos);
    // cout<<"Your new Linked list is:\n";
    // print(list1);

    return 0;
}
