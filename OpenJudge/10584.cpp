#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
    int n,x,ttl=0;
    cin>>n>>x;
    for(int i=1; i<=n; i++) {
        int k=i;
        while(k!=0){
            if(k%10==x) ttl++;
            k=k/10;
        }
    }
    cout<<ttl;
    return 0;
}