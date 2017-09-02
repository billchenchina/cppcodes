#include <bits/stdc++.h>

using namespace std;
int dp1_arr[101][101]= {0};
int dp2_arr[101][101]= {0};
int main()
{
    int N;
    cin>>N;
    int prefix_arr[201];
    // input data and switch it to prefix arr
    for(int i=0; i<N; ++i)
    {
        int tmp;
        cin>>tmp;
        if(i==0)
        {
            prefix_arr[i]=tmp;
        }
        else
        {
            prefix_arr[i]=prefix_arr[i-1]+tmp;
        }
    }
    // prefix arr times two
    for(int i=N; i<2*N; ++i)
    {
        if(i==N)
        {
            prefix_arr[i]=prefix_arr[i-1]+prefix_arr[0];
        }
        else
        {
            prefix_arr[i]=prefix_arr[i-1]+(prefix_arr[i-N]-prefix_arr[i-N-1]);
        }
    }
    for(int range=1; range<=N; ++range)
    {
        if(range==1)
        {
            for(int start_pos=0; start_pos<N; ++start_pos)
            {
                dp1_arr[start_pos][start_pos]= 0;
                dp2_arr[start_pos][start_pos]= 0;
            }
        }
        else
        {
            for(int start_pos=0; start_pos<N; ++start_pos)
            {
                int end_pos=start_pos+range-1;
                int minn=INT_MAX;
                int maxn=0;
                for(int mid=start_pos; mid<end_pos; ++mid)
                {
                    int m2=mid+1;
                    int e2=end_pos;
                    if(m2>=N)
                    {
                        m2%=N;
                        e2%=N;
                    }
                    if(start_pos==0)
                    {
                        minn=minn<(dp1_arr[start_pos][mid]+dp1_arr[m2][e2]+prefix_arr[end_pos])?minn:(dp1_arr[start_pos][mid]+dp1_arr[m2][e2]+prefix_arr[end_pos]);
                        maxn=maxn>(dp2_arr[start_pos][mid]+dp2_arr[m2][e2]+prefix_arr[end_pos])?maxn:(dp2_arr[start_pos][mid]+dp2_arr[m2][e2]+prefix_arr[end_pos]);
                    }
                    else
                    {
                        minn=minn<(dp1_arr[start_pos][mid]+dp1_arr[m2][e2]+prefix_arr[end_pos]-prefix_arr[start_pos-1])?minn:(dp1_arr[start_pos][mid]+dp1_arr[m2][e2]+prefix_arr[end_pos]-prefix_arr[start_pos-1]);
                        maxn=maxn>(dp2_arr[start_pos][mid]+dp2_arr[m2][e2]+prefix_arr[end_pos]-prefix_arr[start_pos-1])?maxn:(dp2_arr[start_pos][mid]+dp2_arr[m2][e2]+prefix_arr[end_pos]-prefix_arr[start_pos-1]);
                    }
                }
                //cout<<start_pos<<' '<<end_pos<<" => "<<minn<<endl;
                dp1_arr[start_pos][end_pos]=minn;
                dp2_arr[start_pos][end_pos]=maxn;
            }
        }
    }
    int ans1=INT_MAX;
    int ans2=0;
    for(int i=0; i<N; i++)
    {
        if(dp1_arr[i][i+N-1]<ans1)
            ans1=dp1_arr[i][i+N-1];
        if(dp2_arr[i][i+N-1]>ans2)
            ans2=dp2_arr[i][i+N-1];
    }
    cout<<ans1<<endl<<ans2;

}
