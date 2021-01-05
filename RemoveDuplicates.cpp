#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void insert(ListNode **head, int data)
{
    ListNode *newNode = new ListNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    ListNode *current = *head;
    while (current->next)
        current = current->next;
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
    cout << endl;
}
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return head;
        unordered_map<int, int> mp;
        ListNode *current = head, *prev = NULL;
        while (current)
        {
            mp[current->val]++;
            current = current->next;
        }
        current = head;
        while (current)
        {
            if (mp[current->val] == 1)
            {
                if (prev)
                {
                    prev->next = current;
                    prev = current;
                }
                else
                {
                    head = current;
                    prev = current;
                }
            }
            current = current->next;
        }
        if (prev == NULL)
            return NULL;
        prev->next = NULL;
        return head;
    }
};
int main()
{
    int n, data;
    cin >> n;
    ListNode *head = NULL;
    while (n--)
    {
        cin >> data;
        insert(&head, data);
    }
    print(head);
    head = Solution().deleteDuplicates(head);
    print(head);
}