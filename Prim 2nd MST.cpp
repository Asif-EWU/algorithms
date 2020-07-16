#include<bits/stdc++.h>
#define MX  100
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
    int temp1=INT_MAX, temp2;

    for(int i=1; i<=node; i++)
    {
        taken[i]=false;
        cost[i]=INT_MAX;
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
                if(temp1>cost[x])           // for 2nd MST
                {                           // for 2nd MST
                    temp1=cost[x];          // for 2nd MST
                    temp2=y;                // for 2nd MST
                }                           // for 2nd MST

                cost[x]=y;
                pq.push(Edge(x,cost[x]));
            }
            else if(cost[x]<y)              // for 2nd MST
            {                               // for 2nd MST
                if(temp1>y)                 // for 2nd MST
                {                           // for 2nd MST
                    temp1=y;                // for 2nd MST
                    temp2=cost[x];          // for 2nd MST
                }                           // for 2nd MST
            }                               // for 2nd MST
        }
    }

    cout << "1st MST: " << sum << endl;
    cout << "2nd MST: " << sum-temp2+temp1 << endl;
}


int main()
{
    freopen("_prim.txt", "r", stdin);
    int node, edge, a, b, c;

    cin >> node >> edge;
    for(int i=0; i<edge; i++)
    {
        cin >> a >> b >> c;
        arr[a].push_back(Edge(b,c));
        arr[b].push_back(Edge(a,c));
    }
    prim(1,node);

    return 0;
}
