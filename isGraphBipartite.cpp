#include <bits/stdc++.h>

using namespace std;

//   Is Graph Bipartite?

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                q.push(i);
                color[i] = 0;
                while (!q.empty())
                {
                    int src = q.front();
                    q.pop();
                    for (int neigh : graph[src])
                    {
                        if (color[neigh] == -1)
                        {
                            color[neigh] = (color[src]) ? 0 : 1;
                            q.push(neigh);
                        }
                        else if (color[neigh] == color[src])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    int edges = 0;
    cin >> edges;
    while (edges--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << Solution().isBipartite(graph);
}