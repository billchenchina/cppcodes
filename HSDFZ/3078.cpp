#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    char a[10000];
    int n,m;
    cin>>n;
    cin>>a;
    cin>>m;
    for(int i=m-1;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
