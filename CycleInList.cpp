/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            head = head->next;
            if (head == fast)
            {
                return true;
            }
        }
        return false;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_map<ListNode *, bool> f;
        while (head)
        {
            if (f[head] == true)
            {
                return true;
            }
            else
            {
                f[head] = true;
            }
            head = head->next;
        }
        return false;
    }
};