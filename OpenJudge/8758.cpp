#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;


void getlog(int);
inline int get_2(int);




int main() {
    int n;
    cin>>n;
    getlog(n);
    return 0;
}

void getlog(int a) {
    if(a==1) {
        cout<<"2(0)";
        return;
    } else if(a==2) {
        cout<<"2";
        return;
    }
    int b,g2;

    b=log2(a);
    g2=get_2(b);
    if(b==1){
        cout<<"2";
    }else{
    cout<<"2(";
    getlog(b);
    cout<<")";
    }
    if(a!=g2) {
        cout<<"+";
        getlog(a-g2);
    }


}

inline int get_2(int a) {
    return 1 << a;
}