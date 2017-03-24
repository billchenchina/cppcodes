#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char a[500],b[500];
double pd,pda;
int main() {
    scanf("%lf\n",&pd);
    gets(a);
    gets(b);
    int l=strlen(a),i=0;
    for(int k=0;k<l;k++){
        if(a[k]==b[k]){
            i++;
        }
    }
    pda=1.0*i/l;
    if(pda>pd){
        cout<<"yes";
    }else{
        cout<<"no";
    }
    return 0;
}
