


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
bool mark[105];
vector<int>v;

void dfs_topsort(int n)
{
    mark[n]=true;

    for(int i=0; i<arr[n].size(); i++)
    {
        int b=arr[n][i];
        if(!mark[b])
            dfs_topsort(b);
    }
    v.push_back(n);
}


int main()
{
    int n, m, a, b;

    while(cin >> n >> m && n+m)
    {
        for(int i=1; i<=n; i++) arr[i].clear();
        memset(mark,0,sizeof(mark));
        v.clear();

        for(int i=0; i<m; i++)
        {
            cin >> a >> b;
            arr[a].push_back(b);
        }

        for(int i=1; i<=n; i++)
        {
            if(!mark[i])
                dfs_topsort(i);
        }

        for(int i=v.size()-1; i>=0; i--)
        {
            if(i!=v.size()-1) cout << " ";
            cout << v[i];
        }
        cout << endl;
    }

    return 0;
}
