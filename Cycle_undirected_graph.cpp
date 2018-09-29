#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    bool isCyclic_util(int v,bool visited[],int parent);
public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int src,int dest) { adj[src].push_back(dest); adj[dest].push_back(src); }
    void DFS(int s);
    bool isCyclic();
};

bool Graph :: isCyclic_util(int v,bool visited[],int parent)
{
    visited[v]=true;
   // cout << v << " ";
    list <int> :: iterator itr;
    for(itr = adj[v].begin();itr!=adj[v].end();itr++)
    {
        if(!visited[*itr])
        {
            if(isCyclic_util(*itr,visited,v))
                return true;
        }


        else if(*itr != parent)
            return true;
    }
    return false;
}

bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;

    int cycle=0;

    for(int i=0;i<V;i++)
    {
            if(!visited[i])
            {
                if(isCyclic_util(i,visited,-1))
                return true;
            }

    }
    return false;
}





int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";

    return 0;
}


