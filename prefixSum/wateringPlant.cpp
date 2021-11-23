#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int steps = 0, cap = capacity;
        int i = 0;
        while (i < plants.size())
        {
            steps++;
            cap -= plants[i];
            i++;
            if (i < plants.size() && cap < plants[i])
            {
                steps += i << 1;
                cap = capacity;
            }
        }
        return steps;
    }
};