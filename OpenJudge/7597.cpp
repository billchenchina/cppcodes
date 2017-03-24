#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int a[5000],n,m,s,o;
    cin>>n>>m;
    o=0;
    for(int k=0; k<n; k++) {
        a[k]=0;
    }
    for(int k=1; k<=m; k++) {
        for(int i=1; i<=n; i++) {
            if(i%k==0){
                if(a[i-1]==0){
                    a[i-1]=1;
                }
                else{
                    a[i-1]=0;
                }
            }
            else{
                a[i-1]=a[i-1];
            } 
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            s=i+1;
            o++;
            if(o==1){
                printf("%d",s);
            }
            else{
                printf(",%d",s);
            }
            
        }
    }
    return 0;
}