#include <bits/stdc++.h>

using namespace std;

class Solution1
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int curCnt = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
                curCnt = 1;
            else if (nums[i] == nums[i - 1])
                continue;
            else if (nums[i] == nums[i - 1] + 1)
                curCnt++;
            else
            {
                res = max(res, curCnt);
                curCnt = 1;
            }
        }
        res = max(res, curCnt);
        return res;
    }
};
class Solution2
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, bool> hashSet;
        for (int i : nums)
            hashSet.insert({i, 1});
        int maxLength = 0, curLength = 0;
        int curNum = 0;
        for (int i : nums)
        {
            if (hashSet.find(i - 1) == hashSet.end())
            {
                curNum = i + 1;
                curLength = 1;
                while (hashSet.find(curNum) != hashSet.end())
                {
                    curLength++;
                    curNum += 1;
                }
                maxLength = max(maxLength, curLength);
            }
        }
        return maxLength;
    }
};
class Solution3
{
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;

    void make_set(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v)
    {
        if (parent[v] == v)
            return v;
        return parent[v] = find_set(parent[v]);
    }
    int union_sets(int u, int v)
    {
        u = find_set(u);
        v = find_set(v);
        if (u != v)
        {
            if (size[u] < size[v])
                swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
        return size[u];
    }
    int longestConsecutive(vector<int> &nums)
    {

        for (int i : nums)
        {
            make_set(i);
        }
        int ans = 0;
        for (int i : nums)
        {
            if (parent.find(i - 1) != parent.end())
            {
                ans = max(ans, union_sets(i, i - 1));
                // cout<<union_sets(i,i-1)<< " ";
            }
            else
            {
                ans = max(ans, size[i]);
            }
            // cout<<size[i]<<" ";
        }

        return ans;
    }
};