/*
Modified DFS - Disconnected Graph
*/


#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void DFS_util(int v, bool visited[]);
public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int src,int dest) { adj[src].push_back(dest); }
    void DFS();
};

void Graph::DFS_util(int v,bool visited[])
{
    visited[v]=true;
    cout << v << " ";

    list <int> :: iterator itr;
    for(itr=adj[v].begin();itr!=adj[v].end();itr++)
    {
        if(!visited[*itr])
        {
            DFS_util(*itr,visited);
        }
    }

}

void Graph :: DFS()
{
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;

   for(int i=0;i<V;i++)
   {
       if(!visited[i])
        DFS_util(i,visited);
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

    cout << "Following is Depth First Traversal\n";
    g.DFS();

    return 0;
}


