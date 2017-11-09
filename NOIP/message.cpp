#include<bits/stdc++.h>
#define MAXN 200010
#define INF 0xf66ccff
using namespace std;
typedef int dfn_t;
int n,t[MAXN],mark[MAXN],ans=INF,now=1;
dfn_t dfn[MAXN];
bool vis[MAXN];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            int p=i;
            dfn_t s=0;

            while(1)
            {
                if(vis[p])
                {
                    if(mark[p]==now)
                    {
                        if(ans>s-dfn[p])
                        {
                            ans=s-dfn[p];
                        }
                    }
                    break;
                }
                else
                {
                    mark[p]=now;
                    vis[p]=true;
                    dfn[p]=s;
                    s++;
                    p=t[p];
                }
            }
            now++;
        }
    }
    cout<<ans;
    return 0;
}
