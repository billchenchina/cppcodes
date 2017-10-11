#include <bits/stdc++.h>

using namespace std;
int arr[17000+17000+10];
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        int t;
        cin>>t;
        arr[17001+t]++;
    }
    for(int i=-17000; i<=17000; ++i)
    {
        while(arr[17001+i])
        {
            cout<<i<<' ';
            arr[17001+i]--;
        }
    }

}
