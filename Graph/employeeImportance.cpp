#include <bits/stdc++.h>

using namespace std;

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    int dfs(vector<Employee *> &employees, int &id, vector<bool> &vis, vector<int> &indexOfId)
    {
        vis[indexOfId[id]] = true;
        int sum = employees[indexOfId[id]]->importance;
        for (auto &emp : employees[indexOfId[id]]->subordinates)
        {
            if (!vis[indexOfId[emp]])
            {
                sum += dfs(employees, emp, vis, indexOfId);
            }
        }
        return sum;
    }
    int getImportance(vector<Employee *> employees, int id)
    {
        vector<bool> vis(employees.size(), false);
        vector<int> indexOfId(2001, -1);
        int i = 0;
        for (auto &emp : employees)
        {
            indexOfId[emp->id] = i++;
        }
        return dfs(employees, id, vis, indexOfId);
    }
};