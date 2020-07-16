#include<bits/stdc++.h>
#define M 1000
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

int arr[M][M];
bool visited[M][M];
int level[M][M];

int bfs(int a, int b, int x, int y, int row, int column)
{
    int fx[]={1,-1,0,0};
    int fy[]={0,0,1,-1};
    queue<pair<int,int> >q;
    int m, n, tx, ty;

    q.push(make_pair(a,b));
    visited[a][b]=true;
    level[a][b]=0;

    while(!q.empty())
    {
        pair<int,int>p=q.front();
        q.pop();
        m=p.first;
        n=p.second;

        for(int i=0; i<4; i++)
        {
            tx=m+fx[i];
            ty=n+fy[i];

            if(tx>=0 && tx<row && ty>=0 && ty<column && arr[tx][ty]!=-1 && !visited[tx][ty])
            {
                visited[tx][ty]=true;
                level[tx][ty]=level[m][n]+1;

                if(tx==x && ty==y)
                    return level[tx][ty];

                q.push(make_pair(tx,ty));
            }
        }
    }
}

int main()
{
    int row, column, n, index, t, a, x1, y1, x2, y2, ans, i, j, k;

    while(1)
    {
        memset(arr,0,sizeof(arr));
        memset(visited,0,sizeof(visited));
        memset(level,0,sizeof(level));

        fs(row);fs(column);
        if(row==0 && column==0)
            break;

        fs(n);
        for(i=0; i<n; i++)
        {
            fs(index);
            fs(t);

            for(j=0; j<t; j++)
            {
                fs(a);
                arr[index][a]=-1;
            }
        }

        fs(x1);fs(y1);
        fs(x2);fs(y2);

        ans=bfs(x1,y1,x2,y2,row,column);
        printf("%d\n",ans);
    }

    return 0;
}
