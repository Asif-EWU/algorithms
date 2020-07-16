#include<bits/stdc++.h>
using namespace std;

struct st
{
    int a, b, c;
};

vector<st> G;
int d[100], parent[100], node, edge;

bool Bellman_ford(int source)
{
    int a, b, c;
    bool chk;

    for(int i=1; i<=node; i++) d[i] = INT_MAX, parent[i] = 0;
    d[source] = 0;

    for(int i=0; i<node-1; i++)
    {
        chk = false;
        for(int j=0; j<edge; j++)
        {
            a = G[j].a;
            b = G[j].b;
            c = G[j].c;

            if(d[a] != INT_MAX && d[a] + c < d[b])
            {
                d[b] = d[a] + c;
                parent[b] = a;
                chk = true;
            }
        }
        if(!chk) return true;
    }

    for(int i=0; i<edge; i++)
    {
        a = G[i].a;
        b = G[i].b;
        c = G[i].c;
        if(d[a] != INT_MAX && d[a] + c < d[b]) return false;
    }
    return true;
}

int main()
{
    freopen("_bellman_ford.txt", "r", stdin);
    int a, b, c;
    bool chk;

    cin >> node >> edge;
    for(int i=0; i<edge; i++)
    {
        cin >> a >> b >> c;
        G.push_back({a, b, c});
    }

    chk = Bellman_ford(1);
    if(!chk) cout << "Negative cycle found !!" << endl;
    else cout << "Negative cycle not found !!" << endl;

    cout << endl << "Distance: " << endl;
    for(int i=1; i<=node; i++) cout << i << " -> " << d[i] << endl;
    cout << endl;

    return 0;
}
