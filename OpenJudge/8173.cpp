#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char cd(char i) {
    if(i=='z') {
        i='a';
    } else if(i=='Z') {
        i='A';
    } else if((i>='a'&&i<='y')||(i>='A'&&i<='Y')) {
        i++;
    }
    return i;
}
int main() {
    int l;
    char a[80],b;
    gets(a);
    l=strlen(a);
    for(int i=0; i<l; i++) {
        b=cd(a[i]);
        printf("%c",b);
    }

    return 0;
}