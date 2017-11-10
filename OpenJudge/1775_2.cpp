#include <bits/stdc++.h>

using namespace std;



int main()
{
    int Time,N;
    cin>>Time>>N;
    static int time[101];
    static int weight[101];
    for(int i=1;i<=N;++i)
    {
        cin>>time[i]>>weight[i];
    }
    static int arr[1001];
    for(int i=1;i<=N;++i)
    {
        for(int j=Time;j>=1;--j)
        {
            if(time[i]>j)
            {
                arr[j]=arr[j];
            }
            else
            {
                arr[j]=max(arr[j],arr[j-time[i]]+weight[i]);
            }
        }
    }
    cout<<arr[Time];
}
