#include <bits/stdc++.h>

using namespace std;

//  Queries on Number of Points Inside a Circle

class Solution
{
public:
    bool isInside(int x, int y, int a, int b, int c)
    {
        return (pow(x - a, 2) + pow(y - b, 2) <= c * c);
    }
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
    {
        int cnt = 0, i = 0;
        vector<int> res(queries.size());
        for (vector<int> q : queries)
        {
            cnt = 0;
            for (vector<int> p : points)
            {
                if (isInside(p[0], p[1], q[0], q[1], q[2]))
                    cnt++;
            }
            res[i++] = cnt;
        }
        return res;
    }
};
