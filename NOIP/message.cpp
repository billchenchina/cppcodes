#include <bits/stdc++.h>

using namespace std;


void dfs(int root,int i,vector<int>&visited,int &_dfn,vector<int>&to_list,int &counter)
{
    counter++;
    visited[i]=_dfn;
    _dfn++;
}

int main()
{
    int n;
    cin>>n;
    vector<int>to_list(n+1);
    vector<list<int> >in_list(n+1);
    for(int i=1;i<=n;++i)
    {
        int t;
        cin>>t;
        to_list[i]=t;
        in_list[t].push_back(i);
    }
    vector<int>visited(n+1,0);
    int maxn=INT_MAX;
    int _dfn=1;
    for(int i=1;i<=n;++i)
    {
        int counter=0;
        if(!visited[i])
        {
            //dfs(i,i,visited,to_list,counter);
        }
    }
    cout<<maxn;




}
