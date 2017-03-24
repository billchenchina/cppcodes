#include <cstdio>
#include <iostream>
using namespace std;
int r[10000]={0};
int main() {
    int l,m,m1,m2,ttl=0;
    cin>>l>>m;
    for(int i=0;i<=l;i++){
        r[i]=1;
    }
    
    for(int i=0;i<m;i++){
        cin>>m1>>m2;
        for(int j=m1;j<=m2;j++){
            r[j]=0;
        }
    }
    
    for(int i=0;i<=l;i++){
        if(r[i]==1){
            ttl++;
        }
    }
    cout<<ttl;
    return 0;
}
