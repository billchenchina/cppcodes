#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int x=n-1,y=0;
    n=2*n-1;
    int cs=n*n,jz[40][40]={0};
    for(int i=0;i<cs;i++){
        if(x==n&&y==-1){
            x=n-1;
            y=1;
        }
        if(y==-1){
            y=n-1;
        }if(x==n){
            x=0;
        }
        while(jz[x][y]!=0){
            x--;
            y+=2;
        }
        jz[x][y]=i+1;
        x++;
        y--;
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            cout<<jz[k][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}