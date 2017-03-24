#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int ct[102][102],n,zc=0,mj=0;
    cin>>n;
    for(int i=0;i<102;i++){
        for(int k=0;k<102;k++){
            ct[i][k]=255;
        }
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            cin>>ct[i][k];
            if(ct[i][k]<=50){
                zc++;
            }
        }
    }
    cout<<zc<<" ";
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            if(ct[i][k]<=50){
                if(ct[i-1][k]>50||ct[i+1][k]>50||ct[i][k-1]>50||ct[i][k+1]>50){
                    mj++;
                }
            }
        }
    }
    cout<<mj;
    return 0;
}