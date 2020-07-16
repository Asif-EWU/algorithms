#include<bits/stdc++.h>
#define MX  102
using namespace std;

struct Edge
{
    int from, to, cost;
    Edge(int _from, int _to, int _cost)
    {
        from=_from;
        to=_to;
        cost=_cost;
    }
};
bool operator<(Edge x, Edge y)
{
    return x.cost<y.cost;
}

int parent[MX];
int rnk[MX];
vector<Edge>arr;

void initializeSet(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i]=i;
        rnk[i]=0;
    }
}

int findParent(int x)
{
    if(x==parent[x])
        return x;
    else
        return parent[x]=findParent(parent[x]);
}

void unionSet(int x, int y)
{
    int px = findParent(x);
    int py = findParent(y);

    if(rnk[px] < rnk[py])
        parent[px] = py;
    else if(rnk[px] > rnk[py])
        parent[py] = px;
    else
    {
        parent[py] = px;
        rnk[px]++;
    }
}

int kruskal(int n)
{
    int x, y, z, sz, sum=0;

    initializeSet(n);
    sort(arr.begin(),arr.end());
    sz=arr.size();

    for(int i=0; i<sz; i++)
    {
        x=arr[i].from;
        y=arr[i].to;
        z=arr[i].cost;

        if(findParent(x)!=findParent(y))
        {
            unionSet(parent[x],parent[y]);
            sum+=z;
        }
    }

    return sum;
}


int main()
{
    freopen("_kruskal.txt", "r", stdin);
    int node, edge, a, b, c;

    arr.clear();

    cin >> node >> edge;
    for(int i=0; i<edge; i++)
    {
        cin >> a >> b >> c;
        arr.push_back(Edge(a,b,c));
    }

    cout << "MST: " << kruskal(node) << endl;

    return 0;
}
