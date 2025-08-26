// You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order, and each of their nodes contains a single digit.Add the two numbers and return the sum as a linked list.You may assume the two numbers do not contain any leading zero,
// except the number 0 itself.

// KEY Point->The numbers are stored in reverse order .So we can perform forward carry division from starting of number

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

class ListNode1{
public:
    int val;
    ListNode1 *next;
    ListNode1() : val(0), next(nullptr) {}
    ListNode1(int x) : val(x), next(nullptr) {}
    ListNode1(int x, ListNode1 *next) : val(x), next(next) {}
};
ListNode1*head_Testing=new ListNode1();
ListNode1*tail_Testing=new ListNode1(100);
ListNode1*temp_Testing12=new ListNode1(100,head_Testing);
ListNode1*temp_Testing122=new ListNode1(100,tail_Testing);
//ListNode:1->100

ListNode*temp_Testing1=(ListNode*)malloc( sizeof(ListNode));

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *temp = new ListNode(0);
    ListNode *t1 = temp;
    int carry = 0;

    while (l1 != NULL or l2 != NULL or carry != 0)
    {
        int d1 = (l1 != NULL) ? l1->val : 0;
        int d2 = (l2 != NULL) ? l2->val : 0;
        int sum = d1 + d2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ListNode *newNode = new ListNode(digit);
        t1->next = newNode;
        t1 = t1->next;

        l1 = (l1 != nullptr) ? l1->next : nullptr;
        l2 = (l2 != nullptr) ? l2->next : nullptr;
    }
    ListNode *ans = temp->next;
    delete temp;
    return ans;
}

int main()
{

    ListNode *p = new ListNode(2);
    ListNode *p1 = new ListNode(4);
    ListNode *p2 = new ListNode(3);
    p->next = p1;
    p1->next = p2;
    p2->next = NULL;

    ListNode *q = new ListNode(2);
    ListNode *q1 = new ListNode(4);
    q->next = q1;
    q1->next = NULL;
    ListNode *ans = addTwoNumbers(p, q);
    cout << "Addition of 342 and 42 (=384 in reversed form in Linked list : ) => ";
    while (ans != NULL)
    {
        cout << ans->val;
        ans = ans->next;
    }
}

// l1=sizeof(l1) and l2=sizeof(l2)
// Time Complexity:O(max(l1,l2))

