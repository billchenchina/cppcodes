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
    int maxn=-1;
    for(int i=0;i<ans_vec.size();++i)
    {
        for(int j=0;j<i;++j)
        {
            if((ans_vec[i]&ans_vec[j])>maxn)
            {
                maxn=ans_vec[i]&ans_vec[j];
            }
        }
    }
    cout<<maxn;
}
