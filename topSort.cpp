

/// UVA 10305

#include<bits/stdc++.h>
#define fl(n)           for(int i=0; i<n; i++)
#define pb              push_back
#define ll              long long int
#define inf             1/0.0
#define sf              scanf
#define pf              printf
#define nl              printf("\n")
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("output.txt", "w", stdout)
#define sync            ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mem(a,b)        memset(a,b,sizeof(a))
#define err             cout << "OK" << endl;
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define MOD             100000007
#define M               100005
#define MX              505

using namespace std;

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')
            sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

///___________________________________________________________________________________________________________________
///                              CODE STARTS FROM HERE
///-------------------------------------------------------------------------------------------------------------------

vector<int>arr[105];
int indegree[105];
vector<int>v;

void topsort(int n)
{
    priority_queue<int, vector<int>, greater<int> >pq;  // normal queue can also be used
    for(int i=1; i<=n; i++)
    {
        if(!indegree[i])
            pq.push(i);
    }

    while(!pq.empty())
    {
        int a=pq.top();
        pq.pop();
        v.push_back(a);

        for(int i=0; i<arr[a].size(); i++)
        {
            int b=arr[a][i];
            indegree[b]--;
            if(!indegree[b]) pq.push(b);
        }
    }
}


int main()
{
    int n, m, a, b;

    while(cin >> n >> m && n+m)
    {
        for(int i=1; i<=n; i++) arr[i].clear();
        memset(indegree,0,sizeof(indegree));
        v.clear();

        for(int i=0; i<m; i++)
        {
            cin >> a >> b;
            indegree[b]++;
            arr[a].push_back(b);
        }

        topsort(n);
        for(int i=0; i<v.size(); i++)
        {
            if(i!=0) cout << " ";
            cout << v[i];
        }
        cout << endl;
    }

    return 0;
}
