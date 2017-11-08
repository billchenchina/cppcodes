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
    vector<int>ans_vec;
    for(int i=0;i<vbs.size();++i)
    {
        ans_vec.push_back(vbs[i].to_ulong());
    }
    cout<<ans_vec[0]&ans_vec[1];
}
