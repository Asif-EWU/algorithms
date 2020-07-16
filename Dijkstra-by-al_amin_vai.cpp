#include<bits/stdc++.h>
#define ll long long int
#define max 20001
#define INF 100100
using namespace std;

vector<ll>G[max];
vector<ll>cost[max];
ll d[max];

struct data
{
    ll city,dist;
    data(ll a,ll b)
    {
        city = a;
        dist = b;
    }
    bool operator < (const data& p) const
    {
        return dist>p.dist;
    }
};

ll Dijkstra(ll start,ll dest,ll node)
{
    ll i,j,u,v;
    for(i=0; i<=node; i++)
        d[i]=INF;
    priority_queue<data>Q;

    d[start] =0;
    Q.push(data(start,0));

    while(!Q.empty())
    {
        data top = Q.top();
        Q.pop();

        u = top.city;

        for(i=0; i<G[u].size(); i++)
        {
            v = G[u][i];
            if(d[u]+cost[u][i]<d[v])
            {
                d[v] = d[u]+cost[u][i];
                Q.push(data(v,d[v]));
            }
        }
    }
    return d[dest];
}


int main()
{
    ll node,edge,i,j,k,l,m,x,y,z,start,end,cas;
    scanf("%lld",&cas);
    for(k=1; k<=cas; k++)
    {
        scanf("%lld%lld%lld%lld",&node,&edge,&start,&end);
        for(i=0; i<edge; i++)
        {
            cin>>x>>y>>z;
            G[x].push_back(y);
            G[y].push_back(x);

            cost[x].push_back(z);
            cost[y].push_back(z);
        }

        cout<<  Dijkstra(start,end,node)<<endl;

        if(d[end]==INF)
            printf("Case #%lld: unreachable\n",k);
        else
            printf("Case #%lld: %lld\n",k,d[end]);

        for(l =0; l<max; l++)
        {
            G[l].clear();
            cost[l].clear();
        }
    }
    return 0;
}
