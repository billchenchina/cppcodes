#include <bits/stdc++.h>

using namespace std;

string to_binary_string(int x)
{
    string str="";
    while(x)
    {
        str.append(1,'0'+x%2);
        x>>=1;
    }
    reverse(str.begin(),str.end());
    return str;
}

int main()
{
    int n;
    cin>>n;
    vector<bitset<32> >bst(n);
    vector<int>selected[32];
    int maxn=0;
    for(int i=0;i<n;++i)
    {
        unsigned int x;
        cin>>x;
        bst[i]=x;
        for(int j=0;j<32;++j)
        {
            if(bst[i][j])
            {
                selected[j].push_back(x);
            }
        }
    }
    vector<int>vec;
    for(int i=31;i>=0;--i)
    {
        if(selected[i].size()>=2)
        {
            vec=selected[i];
            break;
        }
    }
    for(int i=0;i<vec.size();++i)
    {
        for(int j=0;j<i;++j)
        {
            if((vec[i]&vec[j])>maxn)
            {
                maxn=vec[i]&vec[j];
            }
        }
    }
    cout<<maxn;



}
