#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    static bool comp(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, decltype(&comp)> pq(comp);

        for (auto l : lists)
        {
            if (l)
            {
                pq.push(l);
            }
        }

        ListNode *temp = new ListNode(0);
        ListNode *current = temp;

        while (!pq.empty())
        {
            ListNode *top = pq.top();
            pq.pop();
            current->next = top;
            current = current->next;

            if (top->next)
            {
                pq.push(top->next);
            }
        }

        return temp->next;
    }
};
// Helper function to create a linked list from a vector
ListNode *createLinkedList(vector<int> vals)
{
    if (vals.empty())
        return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *curr = head;
    for (int i = 1; i < vals.size(); i++)
    {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    vector<ListNode *> lists;
    lists.push_back(createLinkedList({1, 4, 5}));
    lists.push_back(createLinkedList({1, 3, 4}));
    lists.push_back(createLinkedList({2, 6}));

    Solution sol1;
    ListNode *mergedHead = sol1.mergeKLists(lists);
    while (mergedHead)
    {
        cout << mergedHead->val << " -> ";
        mergedHead = mergedHead->next;
    }
    cout << "NULL" << endl;
    printList(mergedHead);

    return 0;
}

//Time Complexity:O(n*log(k))
//where n->number of Linked lists
//k->Number of elements in each Linked list

