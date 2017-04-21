#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    int g[102][102];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>g[i][j];
        }
    }
    bool sure[102]={0};
    sure[1]=1;
    for(int i=1; i<=n; i++) { //this point
        int minn=INT_MAX,select;
        for(int j=1; j<=n; j++) { //find min length
            if(g[i][j]<minn&&) {
                minn=g[i][j];
                select=j;
            }
        }

    }
    return 0;
}
