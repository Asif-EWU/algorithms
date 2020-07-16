#include<bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define SIZE 100

int adj[SIZE][SIZE];
int colour[SIZE];
int parent[SIZE];
int dis[SIZE];
int fin[SIZE];
int tyme = 0;

void dfsVisit(int u , int vertex)
{
    colour[u] = GRAY;
    dis[u] = tyme++;
    for(int i = 0; i < vertex; i++)
    {
        if(adj[u][i] == 1)
        {
            int v = i;
            if(colour[v] == WHITE)
            {
                parent[v] = u;
                dfsVisit(v , vertex);
            }
        }
    }
    colour[u] = BLACK;
    fin[u] = tyme++;
    cout << u << " ";
}

void dfs(int vertex)
{
    for(int i = 0; i < vertex; i++) colour[i] = WHITE;
    tyme = 0;
    cout << "DFS is ";
    for(int i = 0; i<vertex; i++)
    {
        if(colour[i] == WHITE) dfsVisit(i, vertex);
    }
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int vertex;
    int edge;
    cin >> vertex >> edge;
    cout << "Vertex is : " << vertex <<endl;
    cout << "Edge is : " << edge <<endl;

    int node1,node2;
    for(int i = 0 ; i< edge ; i++)
    {
        //cout << "Enter 2 Nodes : ";
        cin >> node1 >> node2;
        adj[node1][node2] = 1;
        adj[node2][node1] = 1;

    }
    for(int i = 0 ; i < vertex ; i++)
    {
        for(int j = 0 ; j < vertex ; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    dfs(vertex);

    return 0;
}

// https://ideone.com/JnnJHC         maisha dfs/backtracking
