#include <cstdio>
#include <iostream>
using namespace std;
int N,v,n[2001],w[2001],c[2001],f[2001];
int main()//件数、大小、价值
{
    freopen("party.in","r",stdin);
    freopen("party.out","w",stdout);
    cin>>N>>v;//Input N&v
    for(int i=1; i<=N; i++)
    {
        cin>>w[i]>>c[i]>>n[i];//Input n,w,c
    }
    for(int i=1; i<=N; i++)
    {
        for(int j=v; j>=1; j--)
        {
            for(int k=0; k<=n[i]; k++)
            {
                if(k*w[i]<=j)
                {
                    f[j]=max(f[j-k*w[i]]+k*c[i],f[j]);
                }
            }
        }
    }
    cout<<f[v];
    return 0;
}
