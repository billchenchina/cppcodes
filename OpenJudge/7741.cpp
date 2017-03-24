#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int a[6][5],m,n;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>a[i][j];
        }
    }
    cin>>m>>n;
    m--;
    n--;
    for(int i=0;i<5;i++){
        a[5][i]=a[m][i];
        a[m][i]=a[n][i];
        a[n][i]=a[5][i];
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<a[i][j];
            if(j!=4){
                cout<<" ";
            }
        }
        if(i!=4){
            cout<<endl;
        }
    }
    
    return 0;
}