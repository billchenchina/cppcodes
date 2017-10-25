#include <bits/stdc++.h>

using namespace std;


vector<int>v[100000];
int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    for(int i=0;i<n;++i)
    {
        int t;
        cin>>t;
        int x=t%m;
        v[x].push_back(t);
        if(v[x].size()==k)
        {
            cout<<"Yes"<<endl;
            for(int j=0;j<v[x].size();++j)
            {
                cout<<v[x][j]<<' ';
            }
            return 0;
        }
    }
    cout<<"No";
}
