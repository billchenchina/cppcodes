#include <iostream>
#include <cstdio>
using namespace std;

int main() {
int a[7][2],b,max[2];
max[0]=0;
for(int i=0;i<7;i++){
    cin>>a[i][0]>>b;
    a[i][0]+=b;
    a[i][1]=a[i][0]-8;
    if(a[i][1]>max[0]){
        max[0]=a[i][1];
        max[1]=i+1;
    }
}
cout<<max[1];

    return 0;
}