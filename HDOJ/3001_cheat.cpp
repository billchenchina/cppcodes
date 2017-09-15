#include <bits/stdc++.h>
#define INF 99999999
using namespace std;

typedef long long ll;

// dp[i][j]表示i状态下以j结尾的最短步数
int dp[60000][11];

// three[i]表示3^i
int three[11];

// digit[i][j]表示数字i三进制表示下的第j位的值
// 如 35 -> 1 0 2 2
//          3 2 1 0
int digit[60000][11];

int tu[15][15];
int n,m;


void init()
{
    three[0]=1;
    for(int i=1; i<11; i++)
    {
        three[i]=three[i-1]*3;
    }
    for(int i=0; i<three[10]; i++)
    {
        int tem=i;
        for(int j=0; j<10; j++)
        {
            digit[i][j]=tem%3;
            tem/=3;
        }
    }
}

int main()
{
    init();
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0; i<n; i++) // init
        {
            for(int j=0; j<n; j++)
            {
                tu[i][j]=INF;
            }
        }
        for(int i=0; i<three[n]; i++) // init
        {
            for(int j=0; j<n; j++)
            {
                dp[i][j]=INF;
            }
        }
        while(m--) // input data
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            tu[a-1][b-1]=tu[b-1][a-1]=min(c,tu[a-1][b-1]);
        }
        for(int i=0; i<n; i++)
        {
            dp[three[i]][i]=0; // init dp array
        }

        int ans=INF;
        for(int j=0; j<three[n]; j++)
        {
            bool flag=true;
            for(int i=0; i<n; i++)
            {
                if(digit[j][i]==0)
                {
                    // 只要三进制数中存在一个0，那么就说明还有点没有遍历完，就不能当做最终答案来求
                    flag=false;
                }
                // 类似广搜？
                if(dp[j][i]!=INF)
                {
                    for(int k=0; k<n; k++)
                    {

                        // 注意这个digit[j][k]!=2,因为如果j状态在k点已经走过两次了显然是不能继续往下走的
                        // 如果从 i 能直接到达 k 且 j 状态下 k 未访问两次
                        if(tu[i][k]!=INF&&digit[j][k]!=2)
                        {
                            // 从 i 建立一条到达 k 的路径
                            dp[j+three[k]][k]=min(dp[j][i]+tu[i][k],dp[j+three[k]][k]);
                        }
                    }
                }
            }
            if(flag)
            {
                // 由于是3进制，不能方便的判断一串三进制数里面是否存在0，所以在dp过程中一边dp一边直接统计结果，也是迫于无奈T_T
                for(int i=0; i<n; i++)
                {
                    ans=min(ans,dp[j][i]);
                }
            }
        }
        if(ans>=INF)
        {
            printf("-1\n");
        }
        else
        {
            cout<<ans<<endl;
        }
    }
    return 0;
}

