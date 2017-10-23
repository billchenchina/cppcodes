#include <bits/stdc++.h>
 
using namespace std;
 
int arr[10+int(1e6)];
int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;++i)
    {
        int x,y;
        cin>>x>>y;
        arr[x]++;
        arr[y+1]--;
    }
    int maxn=arr[1];
    for(int i=2;i<=1000000;++i)
    {
        arr[i]=arr[i]+arr[i-1];
        if(maxn<arr[i])
        {
            maxn=arr[i];
        }
    }
    cout<<maxn;
}