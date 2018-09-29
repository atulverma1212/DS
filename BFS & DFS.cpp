#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void BFS(int s);
    void DFS(int s);
    void DFSutil(int v, bool *visited);
};

void Graph :: BFS(int s)
{
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;

    list<int> q;

    visited[s]=true;
    q.push_back(s);

    while(!q.empty())
    {
        s = q.front();
        cout << s << " ";
        q.pop_front();

        list<int> :: iterator i;
        for(i = adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                q.push_back(*i);
            }
        }
    }
}

void Graph :: DFSutil(int v, bool *visited)
{
    cout << v << " ";
    visited[v]=true;
    list<int> :: iterator itr;

    for(itr = adj[v].begin();itr!=adj[v].end();itr++)
    {
        if(!visited[*itr])
            DFSutil(*itr,visited);
    }
}

void Graph :: DFS(int s)
{
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
            DFSutil(i,visited);
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    cout << "\nFollowing is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}
