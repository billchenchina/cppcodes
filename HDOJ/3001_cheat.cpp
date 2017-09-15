#include <bits/stdc++.h>
#define INF 99999999
using namespace std;

typedef long long ll;

// dp[i][j]��ʾi״̬����j��β����̲���
int dp[60000][11];

// three[i]��ʾ3^i
int three[11];

// digit[i][j]��ʾ����i�����Ʊ�ʾ�µĵ�jλ��ֵ
// �� 35 -> 1 0 2 2
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
                    // ֻҪ���������д���һ��0����ô��˵�����е�û�б����꣬�Ͳ��ܵ������մ�����
                    flag=false;
                }
                // ���ƹ��ѣ�
                if(dp[j][i]!=INF)
                {
                    for(int k=0; k<n; k++)
                    {

                        // ע�����digit[j][k]!=2,��Ϊ���j״̬��k���Ѿ��߹���������Ȼ�ǲ��ܼ��������ߵ�
                        // ����� i ��ֱ�ӵ��� k �� j ״̬�� k δ��������
                        if(tu[i][k]!=INF&&digit[j][k]!=2)
                        {
                            // �� i ����һ������ k ��·��
                            dp[j+three[k]][k]=min(dp[j][i]+tu[i][k],dp[j+three[k]][k]);
                        }
                    }
                }
            }
            if(flag)
            {
                // ������3���ƣ����ܷ�����ж�һ���������������Ƿ����0��������dp������һ��dpһ��ֱ��ͳ�ƽ����Ҳ����������T_T
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

