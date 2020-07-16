#include<bits/stdc++.h>
using namespace std;

struct st
{
    string name;
    int day;
    int month;
    int year;
};

bool compare(st x, st y)
{
    if(x.year==y.year)
    {
        if(x.month==y.month)
        {
            return x.day<y.day;
        }
        return x.month<y.month;
    }
    return x.year<y.year;
}


int main()
{
    st arr[105];
    int n;

    cin >> n;

    for(int i=0; i<n; i++)
        cin >> arr[i].name >> arr[i].day >> arr[i].month >> arr[i].year;

    sort(arr, arr+n, compare);

    cout << arr[n-1].name << endl << arr[0].name << endl;

    return 0;
}
