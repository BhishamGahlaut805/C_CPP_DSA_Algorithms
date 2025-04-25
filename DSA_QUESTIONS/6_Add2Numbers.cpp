// You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order, and each of their nodes contains a single digit.Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero,
// except the number 0 itself.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// //  Definition for singly-linked list.
typedef  struct ListNode {
    int val;
    struct ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  }ListNode;

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
      ListNode *ans = nullptr;
      string list1 = "";
      string list2 = "";

      while (l1 != nullptr)
      {
          list1 += to_string(l1->val);
          l1 = l1->next;
      }

      while (l2 != nullptr)
      {
          list2 += to_string(l2->val);
          l2 = l2->next;
      }

      reverse(list1.begin(), list1.end());
      reverse(list2.begin(), list2.end());

      int sum = stoi(list1) + stoi(list2);
      string final_ans = to_string(sum);

      for (int i = final_ans.length() - 1; i >= 0; i--)
      {
          ListNode *ptr = new ListNode(final_ans[i] - '0');
          if (ans == nullptr)
          {
              ans = ptr;
          }
          else
          {
              ListNode *p = ans;
              while (p->next != nullptr)
              {
                  p = p->next;
              }
              p->next = ptr;
          }
      }

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
    //   ListNode *q2 = new ListNode(3);
      q->next = q1;
      q1->next = NULL;
    //   q2->next = NULL;

      ListNode*ans=addTwoNumbers(p,q);
      while(ans!=NULL){
          cout << ans->val;
          ans = ans->next;
      }
}
