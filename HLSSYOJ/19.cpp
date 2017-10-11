#include <iostream>

using namespace std;

int main()
{
    bool arr[102]= {0};
    int n,x;
    cin>>n>>x;
    for(int i=0; i<n; ++i)
    {
        int x;
        cin>>x;
        arr[x]=1;
    }
    int sum=0;
    for(int i=0; i<x; ++i)
    {
        if(!arr[i])
        {
            sum++;
        }
    }
    if(arr[x])
    {
        sum++;
    }
    cout<<sum;
}
