#include <bits/stdc++.h>

using namespace std;
// Course Schedule
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto courses : prerequisites)
        {
            indegree[courses[0]]++;
            graph[courses[1]].push_back(courses[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        if (q.empty())
            return false;
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            for (int nextCourse : graph[course])
            {
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0)
                    q.push(nextCourse);
            }
        }
        for (auto i : indegree)
            if (i != 0)
                return false;
        return true;
    }
};
class Solution
{
public:
    bool dfsUtil(int course, vector<vector<int>> &graph, vector<int> &visited, vector<int> &reStack)
    {
        visited[course] = true;
        reStack[course] = true;
        for (int nextCourse : graph[course])
        {
            if (!visited[nextCourse] && dfsUtil(nextCourse, graph, visited, reStack))
                return true;
            if (reStack[nextCourse])
                return true;
        }
        reStack[course] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> visited(numCourses, 0);
        vector<int> reStack(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto courses : prerequisites)
            graph[courses[0]].push_back(courses[1]);
        for (int course = 0; course < numCourses; course++)
        {
            if (!visited[course] && dfsUtil(course, graph, visited, reStack))
                return false;
        }
        return true;
    }
};
int main()
{
    int numCourses;
    cin >> numCourses;
    vector<vector<int>> prequisites;
    int dependencies;
    cin >> dependencies;
    while (dependencies--)
    {
        int u, v;
        cin >> u >> v;
        prequisites.push_back({u, v});
    }
    cout << Solution().canFinish(numCourses, prequisites);
}