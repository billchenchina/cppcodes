#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char a[1000];
    gets(a);
    int b=strlen(a);
    for(int i=b-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
