/*
Modified BFS - Disconnected Graph
*/


#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void BFS_util(int v, bool visited[]);
public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int src,int dest) { adj[src].push_back(dest); }
    void BFS();
};

void Graph::BFS_util(int v,bool visited[])
{
    list <int> :: iterator itr;
    list <int> q;
    visited[v] = true;
    q.push_back(v);
    while(!q.empty())
    {
        v = q.front();
        cout << v << " ";
        q.pop_front();
        for(itr = adj[v].begin();itr!=adj[v].end();itr++)
        {
            if(!visited[*itr])
            {
                q.push_back(*itr);
                visited[*itr]=true;
            }
        }
    }

}

void Graph :: BFS()
{
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;

   for(int i=0;i<V;i++)
   {
       if(!visited[i])
        BFS_util(i,visited);
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
//    g.addEdge(5, 2);     Making the graph disconnected
    g.addEdge(2, 7);

    cout << "Following is Breadth First Traversal\n";
    g.BFS();

    return 0;
}


