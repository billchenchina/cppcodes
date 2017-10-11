#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    vector<int>arr;
    for(int i=0; i<T; ++i)
    {
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    for(int i=0; i<T; ++i)
    {
        cout<<arr[i]<<' ';
    }
}
