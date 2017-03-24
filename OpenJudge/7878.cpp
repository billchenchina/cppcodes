#include <cstdio>
#include <iostream>
#include <cmath> 
using namespace std;
int b[10000];
int main(){
    int n,ttl=0,i,k;
    cin>>n;
    int j=1;
    for(i=1;i<=200;i++){
        for(k=1;k<=i;k++){
            if(j==n+1){
                break;
            }
            b[j]=i;
            j++;
        }
        if(j==n+1){
            break;
        }
    }
    for(int i=1;i<=n;i++){
        ttl+=b[i];
    }
    cout<<ttl;
    return 0;
}