#include <cstdio>
#include <iostream>
using namespace std;
int n,v,w[20000],c[20000],f[20000];
int main()
{
    cin>>n>>v;//Input n&v
    for(int i=1; i<=n; i++)
    {
        cin>>w[i]>>c[i];//Input w&c;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=v;j++){
            if(w[i]<=j){
                f[j]=max(f[j],f[j-w[i]]+c[i]);
            }
        }
    }
    cout<<f[v];
    return 0;
}
