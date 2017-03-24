#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int m,n,a,sb;
    cin>>m>>n;
    sb=0;
    for(int i=0; i<n; i++) {
        cin>>a;
        if(a<=m){
            m=m-a;
        }
        else{
            sb++;
        }
    }
    cout<<sb;
    return 0;
}