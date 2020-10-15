#include <bits/stdc++.h>

using namespace std;

int lowerBound(int arr[], int l, int r, int n, int key)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key)
        {
            if (mid > 0 && arr[mid - 1] == arr[mid])
            {
                r = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        else if (arr[mid] > key)
        {
            r = r - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}
int upperBound(int arr[], int l, int r, int n, int key)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key)
        {
            if (mid < n - 1 && arr[mid + 1] == arr[mid])
            {
                l = l + 1;
            }
            else
            {
                return mid + 1;
            }
        }
        else if (arr[mid] > key)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, key;
        cin >> n;
        int sorted_array[n];
        for (int i = 0; i < n; i++)
        {
            cin >> sorted_array[i];
        }
        cin >> key;
        int l = lowerBound(sorted_array, 0, n - 1, n, key);
        int u = upperBound(sorted_array, 0, n - 1, n, key);
        // cout << l << " " << u << "\n";

        cout << u - l << "\n";
    }
}