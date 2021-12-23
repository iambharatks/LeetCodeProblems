#include <bits/stdc++.h>

using namespace std;

class SolutionDFS
{
public:
    vector<vector<int>> adj;
    vector<int> res;
    vector<int> vis;
    bool cycleFound = false;
    void dfs(int src)
    {
        if (cycleFound)
            return;
        vis[src] = 1;
        for (int &nbr : adj[src])
        {
            if (vis[nbr] == 0)
            {
                dfs(nbr);
            }
            if (vis[nbr] == 1)
            {
                cycleFound = true;
                return;
            }
        }
        res.push_back(src);
        vis[src] = 2;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        adj.resize(numCourses);
        vis.resize(numCourses);
        for (vector<int> &v : prerequisites)
        {
            adj[v[0]].push_back(v[1]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (vis[i] == 0)
                dfs(i);
        }
        return cycleFound ? vector<int>() : res;
    }
};
class SolutionBFS
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> dependencies(numCourses);
        vector<vector<int>> adj(numCourses);
        vector<int> res;
        for (vector<int> &v : prerequisites)
        {
            dependencies[v[0]]++;
            adj[v[1]].push_back(v[0]);
        }
        queue<int> courses;
        for (int i = 0; i < numCourses; i++)
        {
            if (dependencies[i] == 0)
                courses.push(i);
        }
        while (!courses.empty())
        {
            int course = courses.front();
            res.push_back(course);
            courses.pop();
            for (int &i : adj[course])
            {
                if (dependencies[i] == 1)
                {
                    courses.push(i);
                }
                dependencies[i]--;
            }
        }
        return (res.size() == numCourses) ? res : vector<int>();
    }
};