#include <bits/stdc++.h>

using namespace std;

long long C_arr[10001][10001]={0};

void initC(int maxn,int p)
{
    for(int n=1;n<=maxn;++n)
    {
        for(int m=0;m<=n;++m)
        {
            if(m==0)
            {
                C_arr[n][m]=1;
            }
            else if(m==1)
            {
                C_arr[n][m]=n%p;
            }
            else if(m==n)
            {
                C_arr[n][m]=1;
            }
            else
            {
                C_arr[n][m]=(C_arr[n-1][m]+C_arr[n-1][m-1])%p;
            }
        }
    }
}
long long lucas(int n,int m,int p)
{
    if(m==0)return 1;
    if(m==1)return n%p;
    if(n<p&&m<p)
    {
        return C_arr[n][m];
    }
    else
    {
        return (lucas(n/p,m/p,p)*lucas(n%p,m%p,p))%p;
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,p;
        cin>>n>>m>>p;
        initC(n,p);
        cout<<lucas(n+m,m,p)<<endl;
    }

}
