#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<bitset<32> >vbs(n);
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        vbs[i]=x;
    }
    for(int j=31;j>=0;--j)
    {
        vector<bitset<32> >b;
        for(int i=0;i<vbs.size();++i)
        {
            if(vbs[i][j])
            {
                b.push_back(vbs[i]);
            }
        }
        if(b.size()>=2)
        {
            vbs=b;
            b.clear();
        }
        else
        {
            continue;
        }
    }
    int x=vbs[0].to_ulong();
    int y=vbs[1].to_ulong();
    cout<<x&y;
}
