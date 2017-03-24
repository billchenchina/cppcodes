#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int apple[10],hght,sum=0;
    for(int i=0; i<10; i++) {
        cin>>apple[i];
        apple[i]=apple[i]-30;
    }
    cin>>hght;
    for(int i=0;i<10;i++){
        sum+=apple[i]<=hght?1:0;
    }
    cout<<sum;
    return 0;
}