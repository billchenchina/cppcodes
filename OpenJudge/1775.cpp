#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Time;
    int N;
    cin>>Time>>N;
    vector<int>time(N+1,0);
    vector<int>value(N+1,0);
    vector<vector<int> >dp_map(1+N,vector<int>(Time+1,0));
    for(int i=1;i<=N;++i)
    {
        cin>>time[i]>>value[i];
    }
    for(int i=1;i<=N;++i)
    {
        for(int j=1;j<time[i];++j)
        {
            dp_map[i][j]=dp_map[i-1][j];
        }
        for(int j=time[i];j<=Time;++j)
        {
            dp_map[i][j]=max(dp_map[i-1][j-time[i]]+value[i],dp_map[i-1][j]);
        }
    }
    cout<<dp_map[N][Time];
}
