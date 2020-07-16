#include<bits/stdc++.h>
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
    return a.cost > b.cost;
}

map<int,vector<Edge> >arr;

int dijkstra(int node, int from, int to)
{
    priority_queue<Edge>pq;
    map<int,int>dist;

    for(int i=0; i<=node; i++) dist[i]=INT_MAX;

    dist[from]=0;
    pq.push(Edge(from,0));  // farmgate - 0

    while(!pq.empty())
    {
        Edge top=pq.top();  // tsc - 10
        pq.pop();

        if(dist[top.to]!=top.cost) continue;

        for(int i=0; i<arr[top.to].size(); i++)
        {
            Edge x=arr[top.to][i];              // karjon - 7

            if(dist[top.to]+x.cost<dist[x.to])  // 10+7<25
            {
                dist[x.to]=dist[top.to]+x.cost;
                pq.push(Edge(x.to,dist[x.to]));
            }
        }
    }
    return dist[to];
}

int main()
{
    freopen("_dijkstra.txt", "r", stdin);
    int cas, node, edge, from, to;
    int st, ed, cost, ans;

    cin >> cas;
    for(int i=1; i<=cas; i++)
    {
        arr.clear();

        cin >> node >> edge >> from >> to;

        for(int j=0; j<edge; j++)
        {
            cin >> st >> ed >> cost;
            arr[st].push_back(Edge(ed,cost));
        }

        ans=dijkstra(node,from,to);
        printf("From %d to %d = ",from,to);

        if(ans!=INT_MAX)
            cout << ans << endl;
        else
            cout << "Impossible" << endl;
    }

    return 0;
}

// ans: 2 3 6 4 1 3
