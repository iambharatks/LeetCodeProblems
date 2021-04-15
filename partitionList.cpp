#include <bits/stdc++.h>

using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void push_back(ListNode **head, int elem)
    {
        ListNode *current = *head, *newNode;
        newNode = new ListNode(elem);
        if (current == NULL)
        {
            *head = newNode;
            return;
        }
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    void print(ListNode *head)
    {
        ListNode *current = head;
        while (current)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << '\n';
    }
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *current = head, *prev = NULL, *newHead = NULL, *p = NULL;
        while (current->val != x)
        {
            prev = current;
            current = current->next;
        }
        p = current;
        current = current->next;

        while (current)
        {
            if (current->val < x)
            {
                p = current->next;
                current->next = p;
                if (prev != NULL)
                    prev->next = current;
                prev = current;
            }
            else
            {
                p = current;
            }
        }
        return head;
    }
};

int main()
{
    int n, x;
    ListNode *head = NULL;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        head->push_back(&head, x);
    }
    head->print(head);
    cin >> x;
    Solution().partition(head, x);
    head->print(head);
}