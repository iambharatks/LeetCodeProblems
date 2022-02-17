#include <bits/stdc++.h>

using namespace std;

class TopVotedCandidate
{
public:
    vector<int> order;
    vector<int> times;
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        vector<int> count(persons.size());
        this->times = times;
        int leading = persons[0];
        for (int i = 0; i < persons.size(); i++)
        {
            count[persons[i]]++;
            if (count[persons[i]] >= count[leading])
            {
                leading = persons[i];
            }
            order.push_back(leading);
        }
    }

    int q(int t)
    {
        int idx = upper_bound(times.begin(), times.end(), t) - times.begin();
        return order[idx - 1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */