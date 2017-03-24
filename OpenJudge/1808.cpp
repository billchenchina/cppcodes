#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int f[1000][1000];

int main() {
    string a, b;
    while (cin>>a>>b) {
                memset(f,0,sizeof(f));
        for(int i = 1; i <= a.size(); i++) {
            for(int j = 1; j <= b.size(); j++) {
                if (a[i-1] == b[j-1]) {
                    f[i][j] = f[i-1][j-1] + 1;
                }
                else {
                    f[i][j] = f[i-1][j]>f[i][j-1] ? f[i-1][j] : f[i][j-1];
                }
            }
        }
        cout<<f[a.size()][b.size()]<<endl;
    }
    return 0;
}