#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char a[14],r[14];
    gets(a);
    strcpy(r,a);
    int b[10],sum=0;
    b[0]=a[0]-'0';
    b[1]=a[2]-'0';
    b[2]=a[3]-'0';
    b[3]=a[4]-'0';
    b[4]=a[6]-'0';
    b[5]=a[7]-'0';
    b[6]=a[8]-'0';
    b[7]=a[9]-'0';
    b[8]=a[10]-'0';
    for(int i=0; i<9; i++) {
        sum+=b[i]*(i+1);
    }
    b[9]=sum%11;
    if(b[9]==10) {
        r[12]='X';
    } else {
        r[12]=b[9]+'0';
    }
    if(a[12]==r[12]){
        cout<<"Right";
    } else{
        cout<<r;
    }



    return 0;
}
