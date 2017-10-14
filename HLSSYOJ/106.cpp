#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        ans+=i*(n-i+1);
    }
    cout<<ans;
}