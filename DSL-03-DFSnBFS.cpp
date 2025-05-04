#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph 
{
    int n;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;

    public :
    Graph(int vertices) {
        n = vertices;
        adjMatrix.resize(n, vector<int>(n, 0));
        adjList.resize(n);
    }

    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = adjMatrix[v][u] = 1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void displayMatrix()
    {
        cout<< "Adjacency Matrix : \n";
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void DFS(int start)
    {
        vector<bool> visited(n, false);
        cout<<"DFS traversal : ";
        dfsHelper(start, visited);

        cout << "\n";
    }

    void dfsHelper(int v, vector<bool>& visited)
    {
        visited[v] = true;
        cout << v << " ";
        for(int i = 0; i < n ; i++)
        {
            if(adjMatrix[v][i] == 1 && !visited[i])
            {
                dfsHelper(i, visited);
            }
        }
    }

    void BFS(int start)
    {
        vector<bool> visited(n, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS Traversal(using List) : ";

        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for(int neighbor : adjList[v])
            {
                if(!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << "\n";
    }
};

int main()
{
    int n , m;
    cout << "Enter number of landmarks (vertices) : ";
    cin >> n;

    Graph g(n);

    cout << "Enter number of paths (edges) :";
    cin >> m;

    cout << "Enter the edges (eg 0 1): \n";
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.displayMatrix();

    int start;
    cout << "Enter the starting vertex for BFS and DFS: ";
    cin >> start;
    g.DFS(start);
    g.BFS(start);

    return 0;
}