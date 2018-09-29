#include<iostream>
#include<limits.h>
#define V 9
using namespace std;

int min_dist(bool set[V],int dist[V])
{
    int min_index,min=INT_MAX;
    for(int i=0;i<V;i++)
    {
        if(!set[i] && dist[i]<min)
            min=dist[i], min_index = i;
    }
    return min_index;
}

void dijkstra(int graph[V][V],int src)
{
    bool set[V];
    int dist[V];

    for(int i=0;i<V;i++)
        dist[i]=INT_MAX, set[i]=false;

    dist[src]=0;

    for(int count=0;count<V-1;count++)
    {
        int u = min_dist(set,dist);
        set[u]=true;

        for(int v=0;v<V;v++)
        {
            if(!set[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
                dist[v] = dist[u]+graph[u][v];
        }
    }

    cout << "Vertex \t\t Minimum distance from src\n";
    for(int i=0;i<V;i++)
        cout << i << "\t\t" << dist[i] << endl;
}





int main()
{
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph, 0);

    return 0;
}

