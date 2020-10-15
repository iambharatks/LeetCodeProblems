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
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> ans(10000, 0);
        stack<pair<int, int>> s;
        int i = 0;
        while (head)
        {
            while (!s.empty() && s.top().first < head->val)
            {
                ans[s.top().second] = head->val;
                s.pop();
            }
            s.push({head->val, i});
            i++;
            head = head->next;
        }
        ans.erase(ans.begin() + 1, ans.end());
        return ans;
    }
};