#include<bits/stdc++.h>
#define MX 100
using namespace std;

struct Edge
{
    int to, cost;
    Edge(int _to, int _cost)
    {
        to=_to;
        cost=_cost;
    }
};
bool operator<(Edge a, Edge b)
{
    return a.cost>b.cost;
}

vector<Edge>arr[MX];

int prim(int from, int node)
{
    priority_queue<Edge>pq;
    bool taken[MX];
    int cost[MX];
    int x, y, sum=0;

    for(int i=0; i<node; i++)
    {
        cost[i]=INT_MAX;
        taken[i]=false;
    }

    cost[from]=0;
    pq.push(Edge(from,cost[from]));

    while(!pq.empty())
    {
        Edge top=pq.top();
        pq.pop();

        if(taken[top.to])
            continue;
        taken[top.to]=true;
        sum+=top.cost;

        for(int i=0; i<arr[top.to].size(); i++)
        {
            x=arr[top.to][i].to;
            y=arr[top.to][i].cost;

            if(taken[x])
                continue;
            if(cost[x]>y)
            {
                cost[x]=y;
                pq.push(Edge(x,cost[x]));
            }
        }
    }

    return sum;
}

void printGraph(int node)
{
    for(int i=0; i<node; i++)
    {
        cout << i << " -- ";
        for(int j=0; j<arr[i].size(); j++)
            cout << arr[i][j].to << "-" << arr[i][j].cost << "  ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    freopen("prim.txt", "r", stdin);

    int node, edge, a, b, cost;
    cin >> node >> edge;

    for(int i=0; i<node; i++)
        arr[i].clear();

    for(int i=0; i<edge; i++)
    {
        cin >> a >> b >> cost;
        arr[a].push_back(Edge(b,cost));
        arr[b].push_back(Edge(a,cost));
    }

    printGraph(node);
    printf("MST: %d\n",prim(0,node));

    return 0;
}
