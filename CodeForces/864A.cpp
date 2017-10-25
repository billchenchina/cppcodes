#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>v(200,0);
    for(int i=0;i<n;++i)
    {
        int k;
        cin>>k;
        v[k]++;
    }
    for(int i=1;i<=100;++i)
    {
        if(v[i]==0)continue;
        else
        {
            for(int j=i+1;j<=100;++j)
            {
                if(v[j]==0)continue;
                else if(v[i]==v[j]&&v[i]+v[j]==n)
                {
                    cout<<"YES"<<endl;
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
    }
    cout<<"NO";
}
