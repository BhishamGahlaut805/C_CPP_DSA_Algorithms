#include <iostream>
#include <string>
#include <algorithm>
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
};

void display(ListNode *start)
{
    ListNode *ptr = start;
    cout << "Linked list: ";
    while (ptr != nullptr)
    {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *k1 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution solution;
    ListNode *ans = solution.addTwoNumbers(l1, k1);

    display(l1);
    display(k1);
    display(ans);

    return 0;
}
