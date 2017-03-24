#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int pc(int m,int n,int last){
    int ttl=0,a=m/n;
    if(n==1)return 1;
    for(int i=0;i<=a;i++){
            if(i<last) continue;
        ttl+=pc(m-i,n-1,i);
    }
    return ttl;

}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int m,n,ans;
        cin>>m>>n;
        ans=pc(m,n,0);
        cout<<ans<<endl;
    }
return 0;
}