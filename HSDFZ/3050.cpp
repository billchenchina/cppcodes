#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char a[100000];
    gets(a);
    int b=strlen(a);
    for(int i=0;i<b;i++){
        if(a[i]=='z'){
            a[i]='a';
        }else if(a[i]>='a'&&a[i]<'z'){
            a[i]++;
        }
    }
    cout<<a;
    return 0;
}
