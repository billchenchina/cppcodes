#include <cstdio>
#include <iostream>
using namespace std;
bool get_or_not;
int lj[100][2];
int dst[2]= {8,4},fangx[4][2]= {{1,2},{2,1},{2,-1},{1,-2}};
void print(int k) {
    for(int i=0;i<=k;i++){
        cout<<lj[i][1]<<','<<lj[i][0];
        if(i!=k)cout<<"->";
    }
    cout<<endl;
}
void srch(int k) {
    for(int i=0; i<4; i++) {
        if(lj[k-1][0]>=0&&lj[k-1][0]<=dst[0]&&lj[k-1][1]>=0&&lj[k-1][1]<=dst[1]) {
            lj[k][0]=lj[k-1][0]+fangx[i][0];
            lj[k][1]=lj[k-1][1]+fangx[i][1];
            if(lj[k][0]==dst[0]&&lj[k][1]==dst[1])print(k);
            else {
                srch(k+1);
            }
        }
    }
}
int main() {
    srch(1);
    return 0;
}
