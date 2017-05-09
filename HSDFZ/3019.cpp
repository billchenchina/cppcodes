#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main() {
    char a[6];
    int l;
    gets(a);
    l=strlen(a);
    cout<<l<<endl;
    for(int i=0; i<l; i++) {
        cout<<a[i];
        if(i==l-1) {
            cout<<endl;
        } else {
            cout<<" ";
        }
    }
    for(int i=l-1; i>-1; i--) {
        cout<<a[i];
    }
    return 0;
}
