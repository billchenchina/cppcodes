#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
int main()
{
    int n,m;
    cin>>n>>m;
    queue<int>q;
    for(int i=1; i<=m; ++i)
    {
        q.push(1);
        cout<<1<<' ';
    }
    int sum=m;
    for(int i=m+1; i<=n; ++i)
    {
        cout<<sum<<' ';
        q.push(sum);
        sum+=sum;
        sum%=MOD;
        sum-=q.front();
        while(sum<0)sum+=MOD;
        sum%=MOD;
        q.pop();
    }

    return 0;

}
