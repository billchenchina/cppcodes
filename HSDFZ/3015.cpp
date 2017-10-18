#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[20];
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    int maxn=-2147483647,minn=2147483647;
    for(int i=1;i<=n;++i)
    {
        if(maxn<a[i])
            maxn=a[i];
        if(minn>a[i])
            minn=a[i];
    }
    cout<<maxn<<" "<<minn;
    return 0;
}
