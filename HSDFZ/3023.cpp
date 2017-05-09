#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int a[3][3];
    for(int i=0; i<3; i++) {
        for(int k=0; k<3; k++) {
            cin>>a[i][k];
        }
    }
    cout<<a[0][0]+a[1][1]+a[2][2]<<" "<<a[0][2]+a[1][1]+a[2][0];
        return 0;
}
