/*
Simple BFS - Connected Graph
*/


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
    void addEdge(int src,int dest) { adj[src].push_back(dest); adj[dest].push_back(src); }
    void BFS(int s);
};

void Graph :: BFS(int s)
{
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;

    list <int> q;
    list <int> :: iterator itr;
    visited[s] = true;
    q.push_back(s);
    while(!q.empty())
    {
        s = q.front();
        cout << s << " ";
        q.pop_front();

        for(itr = adj[s].begin();itr!=adj[s].end();itr++)
        {
            if(!visited[*itr])
            {
                q.push_back(*itr);
                visited[*itr]=true;
            }
        }
    }
}



int main()
{
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 6);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 2);
    g.addEdge(2, 7);

    cout << "Following is Breadth First Traversal\n";
    g.BFS(2);

    return 0;
}

