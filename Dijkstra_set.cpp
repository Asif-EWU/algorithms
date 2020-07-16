#include<bits/stdc++.h>
#define fl(n)           for(int i=0; i<n; i++)
#define loop(i, a, n)   for(int i=a; i<n; i++)
#define pb              push_back
#define pp              pop_back
#define ll              long long int
#define ld              long double
#define inf             5e18
#define sf              scanf
#define Sf(a)           scanf("%lf",&a)
#define pf              printf
#define Pfc(a)          printf("Case %d: ",a)
#define Pfl(a)          printf("%lld",a)
#define Pfi(a)          printf("%d",a)
#define nl              printf("\n")
#define Vl              vector<ll>
#define Vi              vector<int>
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("outut.txt", "w", stdout)
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define BM              bool mark[M+10]
#define MOD             1000000007
#define M               1000000000

using namespace std;

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

/*-------------------------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------*/

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
    set<Edge>pq;
    set<Edge>::iterator it;
    map<int,int>dist;

    for(int i=0; i<=node; i++)
        dist[i]=M;

    dist[from]=0;
    pq.insert(Edge(from,0));  // farmgate - 0

    while(!pq.empty())
    {
        it=pq.begin();
        Edge top=*it;  // tsc - 10
        pq.erase(it);;

        if(dist[top.to]!=top.cost)
            continue;

        for(int i=0; i<arr[top.to].size(); i++)
        {
            Edge x=arr[top.to][i];              // karjon - 7

            if(dist[top.to]+x.cost<dist[x.to])  // 10+7<25
            {
                dist[x.to]=dist[top.to]+x.cost;
                pq.insert(Edge(x.to,dist[x.to]));
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

    fs(cas);
    for(int i=1; i<=cas; i++)
    {
        arr.clear();

        fs(node);
        fs(edge);
        fs(from);
        fs(to);

        for(int j=0; j<edge; j++)
        {
            fs(st);
            fs(ed);
            fs(cost);

            arr[st].pb(Edge(ed,cost));
        }

        ans=dijkstra(node,from,to);
        printf("From %d to %d = ",from,to);

        if(ans!=M)
            cout << ans << endl;
        else
            cout << "Impossible" << endl;
    }

    return 0;
}

// ans: 2 3 6 4 1 3
