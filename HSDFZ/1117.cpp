#include <cstdio>
#include <iostream>
using namespace std;
int maxn;
void geta(int n);
int mi(int);
int zuida(int);
void geta(int n) {
    if(n==0)return;
    if(n==1) {
        cout<<"2(0)";
        return;
    } else if(n==2) {
        cout<<"2";
        return;
    } else {
        if(mi(n)==2){
            cout<<2;
        }else{

        cout<<"2(";
        geta(zuida(n));
        cout<<")";
        }
        if(n!=mi(n)) {
            cout<<"+";
            int tmp=n-mi(n);
            geta(tmp);
        }
    }
}
int mi(int n) {
    int i=-1;
    maxn=1;
    while(maxn<=n) {
        maxn*=2;
        i++;
    }
    return maxn/2;
}
int zuida(int n) {
    int i=-1;
    maxn=1;
    while(maxn<=n) {
        maxn*=2;
        i++;
    }
    return i;
}

int main() {
    int n;
    cin>>n;
    geta(n);
    return 0;
}
