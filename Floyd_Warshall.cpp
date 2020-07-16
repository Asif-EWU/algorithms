#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;

int arr[107][107];

void floyd_warshall(int n)
{
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(arr[i][j]>arr[i][k]+arr[k][j])
                    arr[i][j]=arr[i][k]+arr[k][j];
}

int main()
{
    int test, n, m, a, b;

    cin >> test;
    for(int t=1; t<=test; t++)
    {
        cin >> n >> m;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    arr[i][j]=0;
                else
                    arr[i][j]=MAX;  // DON'T USE INT_MAX, IT MAY OVERFLOW IN FUNCTION
            }
        }

        for(int i=0; i<m; i++)
        {
            cin >> a >> b;
            arr[a][b]=1;
            arr[b][a]=1;
        }
        floyd_warshall(n);
        cin >> a >> b;

        printf("Shortest path between a and b is: %d\n",arr[a][b]);
    }

    return 0;
}
