
#include <bits/stdc++.h>


using namespace std;

int n,m;

bool mapn[1001][1001];


// if mapn[i][j]==0
//  value[i][j] means free
// else
//  value[i][j]means answer
int value[1001][1001];

int bcj[1001][1001];
int bcj_=1;

bool visited[1001][1001];

// get how much the biggest area is
int dfs(int i,int j)
{
    if(value[i][j])return value[i][j];
    if(i<=0||i>n||j<=0||j>m)
        return 0;
    if(visited[i][j])
        return 0;
    visited[i][j]=1;

    bcj[i][j]=bcj_;
    int ret=1;
    if(i!=1&&mapn[i-1][j]==0)
    {
        ret+=dfs(i-1,j);
    }
    if(j!=1&&mapn[i][j-1]==0)
    {
        ret+=dfs(i,j-1);

    }
    if(i!=n&&mapn[i+1][j]==0)
    {
        ret+=dfs(i+1,j);
    }

    if(j!=m&&mapn[i][j+1]==0)
    {
        ret+=dfs(i,j+1);
    }
    return ret;
}
void dfs2(int i,int j,int val)
{
    value[i][j]=val;
    if(i!=1&&mapn[i-1][j]==0&&value[i-1][j]==0)
    {
        dfs2(i-1,j,val);
    }
    if(i!=n&&mapn[i+1][j]==0&&value[i+1][j]==0)
    {
        dfs2(i+1,j,val);
    }
    if(j!=1&&mapn[i][j-1]==0&&value[i][j-1]==0)
    {
        dfs2(i,j-1,val);
    }
    if(j!=m&&mapn[i][1+j]==0&&value[i][j+1]==0)
    {
        dfs2(i,j+1,val);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0; i<n; ++i)
    {
        char s[1001];
        scanf("%s",s);
        for(int j=0; j<m; ++j)
        {
            if(s[j]=='*')
            {
                mapn[i+1][j+1]=1;
            }
        }
    }
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(mapn[i][j]==0&&value[i][j]==0)
            {
                int val=dfs(i,j);
                dfs2(i,j,val);
                bcj_++;
            }
        }
    }
    \
    //for(int i=1; i<=n; ++i)
    //{
    //    for(int j=1; j<=m; ++j)
    //    {
    //        cout<<value[i][j];
    //    }
    //    cout<<endl;
    //}
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(mapn[i][j]==0)
            {
                printf(".");
            }
            else
            {
                int ans=1;
                set<int>s;
                if(i!=1&&mapn[i-1][j]==0)
                {
                    ans+=value[i-1][j];
                    s.insert(bcj[i-1][j]);
                }
                if(i!=n&&mapn[i+1][j]==0&&s.find(bcj[i+1][j])==s.end())
                {
                    ans+=value[i+1][j];
                    s.insert(bcj[i+1][j]);
                }
                if(j!=1&&mapn[i][j-1]==0&&s.find(bcj[i][j-1])==s.end())
                {
                    ans+=value[i][j-1];
                    s.insert(bcj[i][j-1]);
                }
                if(j!=m&&mapn[i][j+1]==0&&s.find(bcj[i][j+1])==s.end())
                {
                    ans+=value[i][j+1];
                    s.insert(bcj[i][j+1]);
                }
                //for(set<int>::iterator it=s.begin(); it!=s.end(); ++it)
                //{
                //    cout<<*it<<' ';
                //}
                //cout<<endl;
                printf("%d",ans%10);
            }
        }
        printf("\n");
    }
}
