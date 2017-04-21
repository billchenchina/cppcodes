#include <cstdio>
#include <iostream>
#include <memory.h>
using namespace std;
int n,w[1000],c[1000],v;
int table[1000][1000];//table[i][j]
int main()
{
    cin>>n>>v;                       //n&v
    for(int i=1; i<=n; i++)cin>>c[i]; //c
    for(int i=1; i<=n; i++)
    {
        cin>>w[i];                   //w
    }
    for(int i=0;i<=v;i++)table[i][0]=0; //初始化
    memset(table[0],0,sizeof(table[0]));//初始化
    for(int i=1;i<=n;i++){
        for(int j=1;j<=v;j++){
            if(j>=0&&j<w[i]){
                table[i][j]=table[i-1][j];
            }else{
                table[i][j]=max(table[i-1][j],table[i-1][j-w[i]]+c[i]);
            }
        }
    }
    cout<<table[n][v];
    return 0;
}
