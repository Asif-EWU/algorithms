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

string string_multiply(string s1, string s2)
{
    string s;
    int i, j, x, y, flag=0, arr[100000]={0};

    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    for(i=0; i<s1.size(); i++)
    {
        x=s1[i]-'0';
        for(j=0; j<s2.size(); j++)
        {
            y=s2[j]-'0';
            arr[i+j]+=(x*y);
        }
    }

    for(i=0; i<s1.size()+s2.size(); i++)
    {
        x=arr[i]%10;
        y=arr[i]/10;

        arr[i]=x;
        arr[i+1]+=y;
    }

    for(i=s1.size()+s2.size(); i>=0; i--)
    {
        if(arr[i]>0)
            flag=1;
        if(flag==1)
            s.push_back(arr[i]+'0');
    }

    return s;
}


int main()
{
    string s, s1, s2;
    int i, j, x, y, flag=0, arr[100000]={0};

    cin >> s1 >> s2;
    cout << string_multiply(s1,s2) << endl;

    return 0;
}
