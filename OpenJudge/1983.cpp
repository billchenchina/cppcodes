#include <iostream>
#include <cstdio>
using namespace std;

int sudu[10][10];
bool flag;
void dfs(int,int);
void print();
bool check(int,int,int);
int main() {
    int n;
    int i,j;
    cin>>n;
    while(n--) {
        flag=false;
        for(i=1; i<=9; i++) {
            for(j=1; j<=9; j++) {
                scanf("%1d",&sudu[i][j]);
            }
        }
        dfs(1,1);
    }
    return 0;
}
void dfs(int x,int y) {
    if(flag) return;
    if(!sudu[x][y]) {
        for(int i=1; i<=9; i++) {
            if(check(x,y,i)) {
                sudu[x][y]=i;
                if(x==9&&y==9) {
                    flag=1;
                    print();
                    return;
                } else if(y==9) {
                    dfs(x+1,1);
                } else {
                    dfs(x,y+1);
                }
                sudu[x][y]=0;
            }
        }
    } else {
        if(x==9&&y==9) {
            flag=1;
            print();
            return;
        } else if(y==9) {
            dfs(x+1,1);
        } else {
            dfs(x,y+1);
        }
    }
}
bool check(int x,int y,int i) {
    for(int j=1; j<=9; j++) {
        if(sudu[x][j]==i||sudu[j][y]==i)return false;
    }
    int xx=3*((x-1)/3),yy=3*((y-1)/3);
    for(int j=1+xx; j<=3+xx; j++)  {
        for(int k=1+yy; k<=3+yy; k++) {
            if(sudu[j][k]==i)return false;
        }
    }
    return true;
}
void print() {
    for(int i=1; i<=9; i++) {
        for(int j=1; j<=9; j++) {
            cout<<sudu[i][j];
        }
        cout<<endl;
    }
}
