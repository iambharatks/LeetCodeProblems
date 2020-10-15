#include <bits/stdc++.h>

using namespace std;

class BruteForce // Time : O(n*n) || Space: O(1)
{
public:
    int majorityElement(vector<int> A)
    {
        int count = 0, majorityCount = 0;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A.size(); j++)
            {
                if (A[i] == A[j])
                {
                    count++;
                }
            }
            if (count > A.size() / 2)
                return A[i];
        }
        return -1;
    }
};

class Hashmap //Time : O(n) || Space : O(n)
{
public:
    int majorityElement(vector<int> A)
    {
        unordered_map<int, int> m;
        for (int i : A)
        {
            m[i]++;
            if (m[i] > (A.size() / 2))
            {
                return i;
            }
        }
        return -1;
    }
};

class Sort //Time : O(n*lgn) || Space : O(1)
{
public:
    int majorityElement(vector<int> A)
    {
        sort(A.begin(), A.end());
        return A[A.size() / 2];
    }
};

class DivideAndConquer // Time : O(n*lgn) || Space : O(lgn)
{
public:
    int countInRange(int A[], int num, int lo, int hi)
    {
        int c = 0;
        for (int i = lo; i <= hi; i++)
        {
            if (A[i] == num)
                c++;
        }
        return c;
    }
    int majorityElement(int A[], int lo, int hi)
    {
        if (lo == hi)
        {
            return A[lo];
        }
        int mid = lo + (hi - lo) / 2;
        int left = majorityElement(A, lo, mid);
        int right = majorityElement(A, mid + 1, hi);
        // cout << left << "  " << right << "\n";
        // cout << "----------------------\n";
        if (left == right)
        {
            return left;
        }
        int leftCount = countInRange(A, left, lo, mid);
        int rightCount = countInRange(A, right, mid + 1, right);

        return leftCount > rightCount ? left : right;
    }
    int majorityElement(int A[], int n)
    {

        return majorityElement(A, 0, n - 1);
    }
};

class MooresVotingAlgorithm //Time : O(n) || Space : O(1)
{
public:
    int majorityElement(int arr[], int n)
    {
        int maj_index = 0, cnt = 1;
        for (int i = 1; i < n; i++)
        {
            cout << arr[maj_index] << "  " << arr[i] << " count = " << cnt << "\n";
            if (arr[maj_index] == arr[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            if (cnt == 0)
            {
                maj_index = i;
                cnt = 1;
            }
        }
        if (count(arr, arr + n, arr[maj_index]) > n / 2)
            return arr[maj_index];
        return -1;
    }
};
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int &i : A)
    {
        cin >> i;
    }
    MooresVotingAlgorithm b;
    int ans = b.majorityElement(A, n);
    cout << ans << "  " << count(A, A + n, ans) << "\n";
    return 0;
}