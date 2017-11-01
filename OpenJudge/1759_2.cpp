#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int>vec(N,0);
    vector<int>maxLen(N,1);
    for(int i=0; i<N; ++i)
    {
        cin>>vec[i];
    }
    int maxans=1;
    for(int i=1 ; i<N; ++i)
    {
        int maxn=1;
        for(int j=0; j<i; ++j)
        {
            if(vec[i]>vec[j]&&maxLen[j]>maxn-1)
            {
                maxn=maxLen[j]+1;
            }
        }
        maxLen[i]=maxn;
        if(maxn>maxans)
        {
            maxans=maxn;
        }
    }
    cout<<maxans;

}


