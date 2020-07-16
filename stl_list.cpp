#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string s;
    char c;

    cin >> t;
    while(t--)
    {
        list<char>arr;
        list<char>::iterator it=arr.begin();

        cin >> s;
        for(int i=0; s[i]; i++)
        {
            c=s[i];
            if(c!='<' && c!='>' && c!='-')
                arr.insert(it,c);
            if(c=='<' && it!=arr.begin())
                it--;
            if(c=='>' && it!=arr.end())
                it++;
            if(c=='-' && it!=arr.begin())
            {
                it--;
                it=arr.erase(it);
            }
        }

        for(it=arr.begin(); it!=arr.end(); it++)
            cout << *it;
        cout << endl;
    }

    return 0;
}

// https://www.hackerrank.com/contests/cbi-fall-2017/challenges/key-to-heaven/problem
