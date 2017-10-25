#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m,q,u,v,t;
    cin>>n>>m>>q>>u>>v>>t;
    queue<long long>q_[3];
    vector<long long>vec;
    for(long long i=0; i<n; ++i)
    {
        long long tmp;
        cin>>tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end(),greater<long long>());
    for(int i=0; i<vec.size(); ++i)
    {
        q_[0].push(vec[i]);
    }

    for(long long i=1; i<=m; ++i)
    {
        long long selected=-1;
        long long maxn=LONG_MIN;
        for(long long j=0; j<3; ++j)
        {
            if((!q_[j].empty())&&q_[j].front()>maxn)
            {
                maxn=q_[j].front();
                selected=j;
            }
        }
        q_[selected].pop();
        maxn=maxn+q*(i-1);
        if(i % t == 0)
        {
            cout<<maxn<<' ';
        }
        int a=(long long)(maxn * u)/v;
        int b=maxn - a;
        q_[1].push(a - q * i);
        q_[2].push(b - q * i);
    }
    cout<<endl;
    // if(q_[0].size()+q_[1].size()+q_[2].size()!=n+m)return 500;
    for(long long k=1; k<=n+m; ++k)
    {
        long long selected=-1;
        long long maxn=LONG_MIN;
        for(long long i=0; i<3; ++i)
        {
            if((!q_[i].empty())&&q_[i].front()>maxn)
            {
                maxn=q_[i].front();
                selected=i;
            }
        }
        if(k%t==0)
        {
            cout<<q_[selected].front()+q*m<<' ';
        }
        q_[selected].pop();

    }
}
