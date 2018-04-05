#include <bits/stdc++.h>

using namespace std;
double P[2001][2001];
int main() {
    int N, t;
    double p;
    cin>>N>>p>>t;
    P[0][0]=1;
    for(int i=0;i<=t;++i)
    {
        for(int j=0; j<=N; ++j)
        {
            if(i==0)
            {
                if(j==0)
                {
                    P[i][j]=1;
                }
                else
                {
                    P[i][j]=0;
                }
            }
            else if(i!=0 && j==0)
            {
                P[i][j]=P[i-1][j]*(1-p);
            }
            else
            {
                if(j==N)
                {
                    P[i][j] = P[i-1][j] + p*P[i-1][j-1];
                }
                else
                    P[i][j] = (1-p)*P[i-1][j] + p*P[i-1][j-1];
            }
        }
    }
    double ans=0;
    for(int i=0;i<=N;i++)
    {
        ans += P[t][i]*i;
    }
    printf("%.4lf", ans);

}
