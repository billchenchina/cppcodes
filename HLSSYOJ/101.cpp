#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000+5

vector<int>vec[MAXN];

int main()
{
    int m;
    cin>>m;
    for(int i=1; i<=m; ++i)
    {
        int x;
        cin>>x;
        vec[x].push_back(i);
    }
    int n;
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        int L;
        cin>>L;
        vector<int>::iterator iter;
        bool NO=false;
        int end_pos=0;
        for(int j=0; j<L; ++j)
        {
            int bj;
            cin>>bj;
            if(NO)continue;
            iter=upper_bound(vec[bj].begin(),vec[bj].end(),end_pos);
            if(iter==vec[bj].end())NO=true;
            else end_pos=*iter;
        }
        if(NO)
        {
            cout<<"NIE\n";
        }
        else
        {
            cout<<"TAK\n";
        }
    }
}
