#include <bits/stdc++.h>

using namespace std;
int tree[4000040];
class Solution
{
public:
    int get_mid(int a, int b)
    {
        return a + (b - a) / 2;
    }

    // Fn to get sum between range s to e
    int query(int index, int s, int e, int qs, int qe)
    {
        // 1. Base Case - Complete Overlapp
        if (s >= qs and e <= qe)
            return tree[index];

        // 2. Base Case - No overlapp
        if (e < qs or s > qe)
            return 0;

        // 3. Partial Overlapp
        int mid = get_mid(s, e);

        int leftAns = query(2 * index + 1, s, mid, qs, qe);
        int rightAns = query(2 * index + 2, mid + 1, e, qs, qe);

        return leftAns + rightAns;
    }

    void update(int index, int s, int e, int pos)
    {

        // 1. Base Case - Reached the node where update is required
        if (s == e)
        {
            tree[index]++;
            return;
        }

        // 2. Intermidiate Node
        int mid = get_mid(s, e);

        if (pos <= mid)
            update(2 * index + 1, s, mid, pos);
        else
            update(2 * index + 2, mid + 1, e, pos);

        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

    int createSortedArray(vector<int> &instructions)
    {

        int cost = 0;
        const int MAXN = 1e5 + 1;
        const int MOD = 1e9 + 7;

        for (auto x : instructions)
        {
            // Get number of elements that are less than current element
            int less_count = query(0, 0, MAXN, 0, x - 1);

            // Get number of elements which are greater than current element
            int greater_count = query(0, 0, MAXN, x + 1, MAXN);

            update(0, 0, MAXN, x);

            cost = (cost + min(less_count, greater_count)) % MOD;
        }

        return cost;
    }
};
class SolutionNaive
{
public:
    int createSortedArray(vector<int> &instructions)
    {
        int n = instructions.size();
        multiset<int> ms;
        int ans = 0;
        for (int i : instructions)
        {
            auto low = ms.lower_bound(i);
            auto high = ms.upper_bound(i);
            int fromEnd = distance(high, ms.end());
            int fromStart = distance(ms.begin(), low);
            ans += min(fromStart, fromEnd);
            ms.insert(i);
        }
        return ans;
    }
};
class Solution2
{
public:
    vector<int> seg;

    int query(int index, int low, int high, int l, int r)
    {
        if (low >= l && high <= r)
        {
            return seg[index];
        }
        if (high < l || low > r)
            return 0;

        int mid = (low + high) / 2;
        int left = query(2 * index + 1, low, mid, l, r);
        int right = query(2 * index + 2, mid + 1, high, l, r);
        return right + left;
    }

    void update(int index, int low, int high, int pos)
    {
        if (low == high)
        {
            seg[index]++;
            return;
        }
        else
        {
            int mid = (low + high) / 2;
            if (pos <= mid)
            {
                update(2 * index + 1, low, mid, pos);
            }
            else
            {
                update(2 * index + 2, mid + 1, high, pos);
            }
            seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
        }
    }

    int createSortedArray(vector<int> &instructions)
    {

        // using 100001 as 1e5 is the max element value
        seg.resize(4 * 100001, 0);
        int mod = 1e9 + 7;
        int ans = 0;
        for (int i = 0; i < instructions.size(); i++)
        {
            int mi = query(0, 0, 100001, 0, instructions[i] - 1);      //number of elements smaller than instruction[i]
            int mx = query(0, 0, 100001, instructions[i] + 1, 100001); // number of elements greater than instruction[i]
            update(0, 0, 100001, instructions[i]);
            ans = (ans + min(mi, mx)) % mod;
        }
        return ans;

        /*TLE approch using STL
         // 50/65 cases passed
        int m=instructions.size();
        vector<int>a;
        int mod=1e9+7;
        int ans=0;
        int mxe=INT_MIN;
        unordered_map<int,int>um;
        for(auto x:instructions)
        {
            int xx=lower_bound(a.begin(),a.end(),x)-a.begin();
            int n=a.size();
            um[x]++;
            mxe=max(mxe,x);
            if(n==0)
            {
                a.push_back(x);
            
            }
            else
            {
                a.insert(a.begin()+xx,x);
                
                int mi=xx;
                int m=a.size();
                ans=(ans+min(mi,m-mi-um[x]))%mod;
               
            }
        }
        
        return ans;*/
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> instructions(n);
    for (int &i : instructions)
        cin >> i;
    cout << Solution2().createSortedArray(instructions) << " ";
}
