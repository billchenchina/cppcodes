// Now RE
// Leave it unfinished
// Abandoned
// see 1880_2.cpp
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> >dp_map1(105,vector<int>(105,0));
vector<int>prefix_amount(2*105);
int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin>>N;

    for(int i=0; i<N; ++i)
    {
        int tmp;
        cin>>tmp;
        prefix_amount[i]=prefix_amount[i-1]+tmp;
    }
    for(int i=N;i<2*N;++i)
    {
        prefix_amount[i]=prefix_amount[i-1]+prefix_amount[i-N]-prefix_amount[i-N-1];
    }
    {
        int ttlrange=2;
        for(int j=0; j<N; ++j)
        {
            if(j==0)
            {
                dp_map1[j][ttlrange]=prefix_amount[j+1];
            }
            else
            {
                dp_map1[j][ttlrange]=prefix_amount[j+1]-prefix_amount[j-1];
            }
        }
    }

    for(int ttlrange=3; ttlrange<=N; ++ttlrange)
    {
        for(int start=0; start<N; ++start)
        {
            int minn=INT_MAX;
            for(int firstrange=1; firstrange<=ttlrange; ++firstrange)
            {
                if(minn>dp_map1[start][firstrange]+dp_map1[(start+firstrange)%N][ttlrange-firstrange]+(start==0?prefix_amount[ttlrange-1]:prefix_amount[ttlrange-1]-prefix_amount[start]))
                {
                    minn=dp_map1[start][firstrange]+dp_map1[(start+firstrange)%N][ttlrange-firstrange]+(start==0?prefix_amount[ttlrange-1]:prefix_amount[ttlrange-1]-prefix_amount[start]);
                }
            }


            cout<<start<<' '<<start+ttlrange-1<<' '<<minn<<endl;
            dp_map1[start][ttlrange]=minn+prefix_amount[start+ttlrange-1]-prefix_amount[start-1];
        }
    }
    int minn=INT_MAX;
    for(int i=0;i<N;++i)
    {
        cout<<dp_map1[i][N]<<' ';
    }
}
