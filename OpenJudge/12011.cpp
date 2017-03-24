#include<iostream>
#include<cstdio>
using namespace std;
int p[100000];
int bs(int a[],int n,int f){
    int l=0,r=n;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(a[mid]==f){
            return mid+1;
        }
        else if(a[mid]<f){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return -1;
}

int main() {
    int n,f,rslt;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>p[i];
    }
    n--;
    cin>>f;
    cout<<bs(p,n,f);
        return 0;
}