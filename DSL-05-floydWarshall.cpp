#include <iostream>
#include <vector>
using namespace std;

const int INF = 100;

void Floyd_Warshall(vector<vector<int>> graph, int V)
{
    vector<vector<int>> dist = graph;

    //Applying Floyd Warshall Algorithm
    for(int k = 0; k < V; k++)
    {
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                if(dist[i][k] < INF && dist[k][j] < INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                } 
            }
        }
    }

    //Print Shortest Path
    cout << "Shortest distances between every pair of vertices:\n";
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(dist[i][j] == INF)
            {
                cout << "INF";
            }
            else{
                cout << dist[i][j] << " ";
            }
        }

        cout << endl;
    }
}


int main()
{
    int v;
    cout << "Enter Number of Vertices : ";
    cin >> v;

    vector<vector<int>> graph(v, vector<int>(v));
    
    cout << "Enter the adjacency matrix (use 100 for INF):\n";
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cin>>graph[i][j];
        }
    }

    Floyd_Warshall(graph, v);

    return 0;
}