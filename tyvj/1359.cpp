#include <bits/stdc++.h>

using namespace std;

bool check_(int salary,const vector<int>&arr,int N,int M)
{
    int sum=0;
    int times=0;
    for(int i=1;i<=N;++i)
    {
        if(sum+arr[i]>salary)
        {
            times++;
            sum=arr[i];
        }
        else
        {
            sum+=arr[i];
        }
    }
    return M>times;
}

int main()
{
    int N,M;
    cin>>N>>M;
    vector<int>arr(N+1);
    int L=0,R=0;
    int maxn=0;
    for(int i=0; i<N; ++i)
    {
        cin>>arr[i+1];
        if(maxn<arr[i+1])maxn=arr[i+1];
        R+=arr[i+1];
    }
    L=maxn;
    while(L<=R)
    {
#define mid (L+(R-L)/2)
#define check(a) (check_(a,arr,N,M))
        if(check(mid))
#undef check
        {
            R=mid-1;
        }
        else
        {
            L=mid+1;
        }
#undef mid
    }
    cout<<R+1;
}
