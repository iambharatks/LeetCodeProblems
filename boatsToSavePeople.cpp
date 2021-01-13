#include <bits/stdc++.h>

using namespace std;
//   Boats to Save People
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int low = 0, high = people.size() - 1, numberOfBoats = 0;
        while (low <= high)
        {
            if (high == low)
            {
                numberOfBoats++;
                break;
            }
            else if (people[low] + people[high] <= limit)
            {
                low++, high--;
                numberOfBoats++;
            }
            else
            {
                high--;
                numberOfBoats++;
            }
        }
        return numberOfBoats;
    }
};
int main()
{
    int n, limit;
    cin >> n >> limit;
    vector<int> people(n);
    for (int &i : people)
        cin >> i;
    cout << Solution().numRescueBoats(people, limit);
}