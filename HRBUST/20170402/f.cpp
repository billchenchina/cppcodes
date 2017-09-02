#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main() {
    char a[2000];
    while(cin.getline(a,2001)) {
        stack<char> s;
        int len=strlen(a);
        for(int i=0; i<len; i++) {
            if(a[i]!=' ') {
                s.push(a[i]);
            } else {
                while(!s.empty()) {
                    cout<<s.top();
                    s.pop();
                }
                cout<<' ';
            }
        }
        while(!s.empty()) {
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}
