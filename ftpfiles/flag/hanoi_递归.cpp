#include <cstdio>
#include <iostream>
using namespace std;
void hanoi(int n,char src,char mid,char dest) {
    if(n==1) {
        cout<<src<<"->"<<dest<<endl;
        return;
    }
    hanoi(n-1,src,dest,mid);
    cout<<src<<"->"<<dest<<endl;
    hanoi(n-1,mid,src,dest);
    return;
}
int main() {
    int n;
    cin>>n;
    hanoi(n,'A','B','C');
    return 0;
}
