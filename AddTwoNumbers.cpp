#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum = 0;
        ListNode *l3 = NULL;
        //refernce to head node
        ListNode **node = &l3;
        while (l1 || l2 || sum)
        {
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            (*node) = new ListNode((sum > 9) ? sum - 10 : sum);
            node = &((*node)->next);
            sum = (sum > 9) ? 1 : 0;
        }
        return l3;
    }
};