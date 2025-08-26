#include <iostream>
using namespace std;
typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

} ListNode;

// Function to reorder the linked list
// in the required order
//The working logic of this code is as follows:
// 1. Find the middle of the linked list using the slow and fast pointer technique.
// 2. Reverse the second half of the linked list.
// 3. Merge the first half and the reversed second half of the linked list.
// 4. The final result is a reordered linked list where the nodes are arranged in the required order.
// 5. The time complexity of this algorithm is O(n), where n is the number of nodes in the linked list.
// 6. The space complexity is O(1) since we are not using any extra space for storing nodes.
// 7. The algorithm modifies the original linked list in place, so no additional memory is used for creating new nodes.
// 8. The algorithm is efficient and works well for large linked lists.
// 9. The function takes a pointer to the head of the linked list as input and modifies the linked list in place.
// 10. The function does not return anything, as it modifies the linked list directly.

void reorderList(ListNode *head)
{
    if (!head)
    {
        return;
    }
    // 1.Find Middle Element
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // 2.Reverse 2nd Half of Linked list
    ListNode *second = slow->next;
    slow->next = nullptr;
    ListNode *node = NULL;
    while (second)
    {
        ListNode *temp = second->next;
        second->next = node;
        node = second;
        second = temp;
    }
    // Now, 'node' points to the head of the reversed second half of the linked list.
    // 3.Merge the two halves
    ListNode *first = head;
    second = node;

    while (second)
    {
        ListNode *temp1 = first->next;
        ListNode *temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
}
int main()
{
    ListNode *p = new ListNode(1);
    ListNode *p1 = new ListNode(2);
    ListNode *p2 = new ListNode(3);
    ListNode *p3 = new ListNode(4);
    ListNode *p4 = new ListNode(5);

    p->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = NULL;
    ListNode *n = p;
    cout << "Orginal ";
    while (n != NULL)
    {
        cout << n->val << " ";
        n = n->next;
    }
    reorderList(p);
    cout << "\nReordered ";
    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
}