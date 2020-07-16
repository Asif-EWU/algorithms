#include<bits/stdc++.h>
using namespace std;

int parent[50];
int rnk[50];
int member[50];

void initializeSet(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
        rnk[i]=0;
        member[i]=1;
    }
}

int findParent(int x)
{
    if(x==parent[x]) return x;
    else return parent[x]=findParent(parent[x]);
}

void unionSet(int x, int y)
{
    int px=findParent(x);
    int py=findParent(y);

    if(px==py) return;
    else if(rnk[px]>rnk[py])
    {
        parent[py]=px;
        member[px]+=member[py];
    }
    else if(rnk[px]<rnk[py])
    {
        parent[px]=py;
        member[py]+=member[px];
    }
    else
    {
        parent[py]=px;
        rnk[px]++;
        member[px]+=member[py];
    }
}

void print(int n)
{
    for(int i=0; i<n; i++) printf("Node: %d    Parent: %d    Rank: %d    Member: %d\n",i,findParent(i),rnk[i],member[i]);
    cout << endl;
}

int main()
{
    int n=5;
    initializeSet(n);

    unionSet(0,0);
    unionSet(0,2);
    unionSet(1,3);
    unionSet(4,0);
    unionSet(2,3);
    unionSet(1,2);

    print(n);
    return 0;
}
