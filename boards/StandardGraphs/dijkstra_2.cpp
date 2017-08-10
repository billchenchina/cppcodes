#include <cstdio>
#include <iostream>
#include <memory.h>
#include <math.h>
using namespace std;
int mapn[50][50];
bool isblue[50];
int s[50];
int n,//num of point
    m;//num of line
int from,to;
int thisp;
int main() {
    memset(mapn,0x3f,sizeof(mapn));
    memset(s,0x3f,sizeof(s));
    memset(isblue,1,sizeof(isblue));

    cin>>n>>m;
    for(int i=1; i<=m; i++) {
        int f,t,l;
        cin>>f>>t>>l;
        mapn[f][t]=l;
    }

    cin>>from>>to;
    for(int i=1; i<=n; i++) {
        s[i]=mapn[from][i];
    }
    mapn[from][from]=0;
    s[from]=0;
    isblue[from]=0;
    for(int i=1; i<n; i++) {
        int k=0;
        for(int j=1; j<=n; j++) {
            if(isblue[j]&&s[j]<s[k]) {
                k=j;
            }
        }
        isblue[k]=false;
        if(k==0)    break;
        if(k==to)   break;
        for(int j=1;j<=n;j++){
            if(isblue[j]&&s[k]+mapn[k][j]<s[j]){
                s[j]=s[k]+mapn[k][j];
            }
        }
    }
    cout<<s[to];
    return 0;
}


