#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    typedef long long ll;
    ll sq(ll a) { return a * a; }
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        int n = points.size();
        vector<ll> d(n);
        ll l = 0, r = 0;
        vector<int> remaining;
        vector<int> closest;
        for (int i = 0; i < n; i++)
        {
            d[i] = sq(points[i][0]) + sq(points[i][1]);
            r = max(r, d[i]);
            remaining.push_back(i);
        }
        vector<vector<int>> res;
        while (k && l <= r)
        {
            vector<int> closer, farther;
            ll mid = l + (r - l) / 2;
            for (int i : remaining)
            {
                if (d[i] <= mid)
                    closer.push_back(i);
                else
                    farther.push_back(i);
            }
            if (closer.size() > k)
            {
                remaining = closer;
                r = mid - 1;
            }
            else
            {
                k -= closer.size();
                remaining = farther;
                closest.insert(closest.end(), closer.begin(), closer.end());
                l = mid + 1;
            }
        }
        for (int i : closest)
        {
            res.push_back(points[i]);
        }
        return res;
    }
};
// TODO
//  class Solution
//  {
//  public:
//      typedef long long ll;
//      ll euclidsDist(vector<int> &p) { return p[0] * p[0] + p[1] * p[1]; }

//     int partition(vector<vector<int>> &points, int l, int r)
//     {
//         vector<int> pivot = points[l + (r - l) / 2];
//         int pivotD = euclidsDist(pivot);
//         while (l <= r)
//         {
//             if (euclidsDist(points[l]) > pivotD)
//             {
//                 swap(points[l], points[r]);
//                 r--;
//             }
//             else
//             {
//                 l++;
//             }
//         }
//         // if(euclidsDist(points[l]) < pivotD)
//         // l++;
//         return l;
//     }

//     vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
//     {
//         ll l = 0, r = points.size() - 1, pivotIndex = r;
//         while (pivotIndex != k)
//         {
//             pivotIndex = partition(points, l, r);
//             if (pivotIndex < k)
//                 l = pivotIndex + 1;
//             else
//                 r = pivotIndex - 1;
//         }
//         return vector<vector<int>>(points.begin(), points.begin() + k);
//     }
// };