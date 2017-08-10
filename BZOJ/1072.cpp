// By popoqqq
// to be finished
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,d,ans;
char s[20];
// dp_map
int f[1<<10][1<<10];
// 10^i
int tens[10];
//
int cnt[10];
// i!
int factorial[11];

// State_Compressed_DP
void DP(int x) {
    for(int i=0; i<n; i++)
        if((1<<i)&x) { // if i is chosen
            int temp=tens[__builtin_popcount(x)-1]%d*(s[i]-'0')%d;
            for(int j=0; j<d; j++) {
                f[x][(j+temp)%d]+=f[(1<<i)^x][j];
            }
        }
}
int main() {
    int T,i;
    {
        // pre-process
        tens[0]=1;
        for(i=1; i<10; i++)
            tens[i]=tens[i-1]*10;
        factorial[0]=1;
        for(i=1; i<=10; i++)
            factorial[i]=factorial[i-1]*i;
    }
    for(cin>>T; T; T--) {
        memset(f,0,sizeof f);
        scanf("%s%d",s,&d);
        n=strlen(s);
        // DP
        f[0][0]=1;
        for(i=1; i<(1<<n); i++) {
            DP(i);
        }
        ans=f[(1<<n)-1][0];
        memset(cnt,0,sizeof cnt);
        for(i=0; i<n; i++) {
            cnt[s[i]-'0']++;
        }
        for(i=0; i<=9; i++) {
            ans/=factorial[cnt[i]];
        }
        cout<<ans<<endl;
    }
}
