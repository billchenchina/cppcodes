#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    vector<int>color(N*2);
    for(int i=0;i<N;++i)
    {
        cin>>color[i];
        color[i+N]=color[i];
    }
    vector<int>mapn(N,vector<int>(N+1));
    for(int i=2;i<=N;++i)
    {

    }
}
