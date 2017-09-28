#include <bits/stdc++.h>

using namespace std;

int main()
{
    int weight[102];
    int n;
    cin>>n;
    for(int i=0;i<n*2;++i)
    {
        cin>>weight[i];
    }
    sort(weight,weight+(2*n));
    int maxn=0;
    int pos=0;
    for(int i=0;i<n;++i)
    {
        if(weight[i+1]-weight[i]>maxn)
        {
            maxn=weight[i+1]-weight[i];
            pos=i*2;
        }
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(i*2==pos)continue;
        ans+=weight[i*2+1]-weight[i*2];
    }
    cout<<ans;
}
