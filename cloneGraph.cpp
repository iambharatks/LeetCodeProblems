#include <bits/stdc++.h>

using namespace std;
// Definition for a Node.
// Clone Graph
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
    unordered_map<Node *, Node *> visited;

public:
    //dfs
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return node;
        Node *newNode = new Node();
        newNode->val = node->val;
        visited[node] = newNode;
        for (Node *i : node->neighbors)
        {
            if (!visited[i])
            {
                Node *tmp = cloneGraph(i);
                newNode->neighbors.push_back(tmp);
            }
            else
                newNode->neighbors.push_back(visited[i]);
        }
        return newNode;
    }
    //bfs
    Node *cloneGraphBFS(Node *node)
    {
        queue<Node *> q;
        Node *newNode = new Node(node->val);
        q.push(node);
        visited[node] = newNode;
        while (!q.empty())
        {
            Node *src = q.front();
            q.pop();
            for (Node *i : src->neighbors)
            {
                if (!visited[i])
                {
                    newNode = new Node(i->val);
                    visited[i] = newNode;
                    q.push(i);
                }
                else
                    visited[src]->neighbors.push_back(visited[i]);
            }
        }
        return visited[node];
    }
};