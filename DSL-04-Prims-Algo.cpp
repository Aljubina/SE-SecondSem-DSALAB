#include <iostream>
using namespace std;

#define INF 999
#define SIZE 10

int main()
{
    int n; //no of offices
    int cost[SIZE][SIZE];   //to store the cost of pairs of offices
    int visited[SIZE] = {0};  //to track whether office is visited in MST.
    int total_cost = 0;    // cost of  selected edges;
    int edgeUsed = 1; //how many edges have been added to MST so far (MST has n-1 edges).
    int start ;  // start for starting node
    int u = -1, v = -1;  //endpoints of currently selected edge
    int min;   // used to track the minimum edge cost.

    cout << "Enter Number of Offices : ";
    cin >> n;

    cout << "Enter cost of adjacency matrix (0 for no connection)" << endl;

    for(int i = 1 ; i <= n; i++)
    {
        for(int j = 1; j <=n; j++)
        {
            cin >> cost[i][j];
            if(cost[i][j] == 0)
            {
                cost[i][j] = INF;
            }
        }
    }

    cout << "Enter the starting edge : ";
    cin >> start;
    visited[start] = 1;

    cout << "\nEdges in the Minimum Spanning Tree:\n";

    //Main Loop to Build MST
    while(edgeUsed < n)
    {
        min = INF;
        for(int i = 1 ; i <= n; i++)
        {
            if(visited[i])
            {
                for(int j = 1; j <= n ; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(u != -1 && v != -1)
        {
            cout << u << " -> " << v << " : " << min << " \n ";
            total_cost += min;
            visited[v] = 1;
            edgeUsed++;
        }
    }

    cout << "\nMinimum Total cost to connect all offices : " << total_cost << endl;

    return 0;
}