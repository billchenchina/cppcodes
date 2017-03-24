#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int m,n,a,ttl=0;
    cin>>m>>n;
    for(int i=0; i<m; i++) {
        for(int k=0; k<n; k++) {
            cin>>a;
            if(i==0||i==m-1||k==0||k==n-1) {
                ttl+=a;
            }
        }
    }
    cout<<ttl;
    return 0;
}