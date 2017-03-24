#include <cstdio>
#include <iostream>
using namespace std;
int n,m,day[100000];
int check(int a){
    int sum=0,count=1;
    for(int i=0;i<n;i++){
        sum+=day[i];
        if(sum>a){
            count++;
            if(count>m){
                return 0;
            }
            sum=day[i];
        }
    }
    return 1;   
}
int main() {
    int l=0,r=0,ans;
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        cin>>day[i];
        if(day[i]>l) l=day[i];
        r+=day[i];
    }
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid)==1){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<l;
    return 0;
}