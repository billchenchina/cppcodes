/*
 * From Luogu
 * Author: [frankchenfu](https://www.luogu.org/space/show?uid=23398)
 * Link: https://www.luogu.org/wiki/show?name=%E9%A2%98%E8%A7%A3+P2258
 * Passage Released Time: 2017-01-30 20:19
 * Problem Info:
 *     Link: https://www.luogu.org/problem/show?pid=2258
 *     PID: P2258
 *     Title: 子矩阵
 * Edited and Commented by Billchenchina
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

#define inf INT_MAX
#define N 17
#define res result
using namespace std;

int n,m,r,c,result=inf;

int p[N][N];

/*
 * v[] is used for DFS()
 * v[0] means the length of the array now
 * v[1...] means the line(s) selected by DFS
 */
int v[N];

int f[N];
int t[N];
int t1[N][N];

inline void init();
inline void work();
inline void DFS(int,int);
inline int DP();




int main() {
    init();
    work();
    return 0;
}


inline void init() {
    cin>>n>>m>>r>>c;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>p[i][j];
}

inline void work() {
    DFS(1,0);
    printf("%d\n",res);
    return;
}

inline void DFS(int i, int dep) {

    //exit here
    if(dep==r) {
        res=min(res,DP());
        return;
    }

    //DFS Again
    for(int j=i; j<=n-r+dep+1; j++) {
        v[0]++;
        v[v[0]]=j;

        DFS(j+1,dep+1);

        v[v[0]]=0;
        v[0]--;
    }
}

//DP Here
inline int DP() {
    memset(t,0,sizeof(t));
    memset(t1,0,sizeof(t1));
    /* 
     * t[i] stands for in Column i,the total grade
     */
    for(int i=1; i<=m; i++) {
        for(int j=1; j<v[0]; j++) {
            t[i]+=abs(p[v[j]][i]-p[v[j+1]][i]);
        }
    }
    //TODO Comment here
    for(int i=1; i<m; i++) {
        for(int j=i+1; j<=m; j++) {
            for(int k=1; k<=v[0]; k++) {
                t1[i][j]+=abs(p[v[k]][i]-p[v[k]][j]);
            }
        }
    }

    for(int i=1; i<=m; i++) {
        f[i]=t[i];
    }

    for(int i=2; i<=c; i++) {
        for(int j=m; j>=i; j--) {
            f[j]=inf;
            for(int k=j-1; k>=i-1; k--) {
                f[j]=min(f[j],f[k]+t1[k][j]);
            }
            f[j]+=t[j];
        }
    }

    int ans=inf;

    for(int i=c; i<=m; i++) {
        ans=min(ans,f[i]);
    }
    return ans;
}