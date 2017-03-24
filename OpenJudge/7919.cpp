#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main() {
    long long n;
    int c;
    char a[20],d[20];
    cin>>n;
    if(n<0){
        cout<<"-";
        n=-n;
    }
    sprintf(a,"%d",n);
    c=strlen(a);
    for(int i=0;i<c;i++){
        d[c-i-1]=a[i];
    }
    sscanf(d,"%d",&n);
    cout<<n;
    return 0;
}