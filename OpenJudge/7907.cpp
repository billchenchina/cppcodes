#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[120],n,m=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                a[j]=1002;
            }
            if(a[i]>a[j]){
                break;
            }
        }
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i]==1002){
            break;
        }
        m++;
    }
    cout<<m<<endl;
    for(int i=0;i<m;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
