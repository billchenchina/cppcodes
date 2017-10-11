#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>v1(n);
    vector<int>v2(n);
    for(int i=0; i<n; ++i)
    {
        cin>>v1[i];
    }
    for(int i=0; i<n; ++i)
    {
        cin>>v2[i];
    }
    if(accumulate(v1.begin(),v1.end(),0)!=accumulate(v2.begin(),v2.end(),0))
    {
        cout<<-1;
        return 0;
    }
    int change=0;
    for(int i=0; i<n-1; ++i)
    {
        if(v1[i]<v2[i])
        {
            change+=v2[i]-v1[i];
            v1[i+1]-=v2[i]-v1[i];
            v1[i]=v2[i];
        }
        else
        {
            change+=v1[i]-v2[i];
            v1[i+1]+=v1[i]-v2[i];
            v1[i]=v2[i];
        }
    }
    cout<<change;
}
