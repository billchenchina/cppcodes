#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    vector<pair<long long,long long> >vec;
    for(int i=0;i<n;++i)
    {
        long long s,d;
        cin>>s>>d;
        vec.push_back(make_pair(s,d));
    }
    int day=vec[0].first+1;
    for(int i=1;i<n;++i)
    {
        if(day<=vec[i].first)
        {
            day=vec[i].first+1;
            continue;
        }
        long long times=(day-vec[i].first)/vec[i].second;
        if((day-vec[i].first)%vec[i].second==0)
        {
            day=vec[i].first+times*vec[i].second+1;
        }
        else
        {
            day=day=vec[i].first+(times+1)*vec[i].second+1;
        }


    }
    cout<<day-1;
}
