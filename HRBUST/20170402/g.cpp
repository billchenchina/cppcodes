#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct ff {
    char a;
    int n;
    ff(char b,int c) {
        a=b;
        n=c;
    }
};
vector<ff>v;
int get(int NumToBeSolve){
    vector<ff>::iterator i=v.begin();
    while(i!=v.end()){
        if(i->a=='A'){
            NumToBeSolve&=(i->n);
        }else if(i->a=='O'){
            NumToBeSolve|=(i->n);
        }else if(i->a=='X'){
            NumToBeSolve^=(i->n);
        }i++;
    }
    return NumToBeSolve;
}
int main() {
    int n,m,toNum;
    cin>>n>>m;
    string s;
    int maxn=0;
    for(int i=0; i<n; i++) {
        int num;
        cin>>s;
        cin>>num;
        v.push_back(ff(s[0],num));
    }
    toNum=int(m>>1)-1;
    for(; toNum<=m; toNum++) {
        int thist=toNum;
        thist=get(thist);
        maxn=thist>maxn?thist:maxn;
    }

    cout<<maxn;
    return 0;
}
