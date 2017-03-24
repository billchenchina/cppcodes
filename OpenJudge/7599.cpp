#include <cstdio>
#include <iostream>
using namespace std;
char a[9],b[9];
int c[100];
int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        scanf("%s%s",a,b);
        if(a[0]=='R') {
            if(b[0]=='R') {
                c[i]=0;
            } else if(b[0]=='S') {
                c[i]=1;
            } else {
                c[i]=2;
            }
        } else if(a[0]=='S') {
            if(b[0]=='S'){
                c[i]=0;
            }else if(b[0]=='R'){
                c[i]=2;
            }else{
                c[i]=1;
            }
        }else{
            if(b[0]=='P'){
                c[i]=0;
            }else if(b[0]=='S'){
                c[i]=2;
            }else{
                c[i]=1;
            }
        }
        
    }
    for(int i=0;i<n;i++){
        if(c[i]==0){
            cout<<"Tie";
        }else if(c[i]==1){
            cout<<"Player1";
        }else{
            cout<<"Player2";
        }
        if(i!=n-1){
            cout<<endl;
        }
    }

    return 0;
}