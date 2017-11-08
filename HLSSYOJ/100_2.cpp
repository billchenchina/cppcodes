#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
     cin.tie(0);
    int n;
    cin>>n;
    vector<int>vbs_(n);
    vector<bitset<32> >vbs;
    for(int i=0; i<n; ++i)
    {
        cin>>vbs_[i];
    }
    sort(vbs_.begin(),vbs_.end());
    for(int i=0; i<n; ++i)
    {
        if(i<=1)
        {
            vbs.push_back(vbs_[i]);
        }
        else
        {
            if(vbs_[i]==vbs_[i-1]&&vbs_[i-1]==vbs_[i-2])
            {
                continue;
            }
            else
            {
                vbs.push_back(vbs_[i]);
            }
        }
    }
    for(int j=31; j>=0; --j)
    {
        vector<bitset<32> >b;
        for(int i=0; i<vbs.size(); ++i)
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
    for(int i=0; i<vbs.size(); ++i)
    {
        ans_vec.push_back(vbs[i].to_ulong());
    }
    int maxn=-1;
    for(int i=0; i<ans_vec.size(); ++i)
    {
        for(int j=0; j<i; ++j)
        {
            if((ans_vec[i]&ans_vec[j])>maxn)
            {
                maxn=ans_vec[i]&ans_vec[j];
            }
        }
    }
    cout<<maxn;
}
