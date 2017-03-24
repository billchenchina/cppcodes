#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int n;
struct num {
    vector<int>vec;
    vector<int>maxn;
} nums;

int main() {
    int n;
    cin>>n;
    nums.vec.push_back(0);
    nums.maxn.push_back(0);
    for(int i=1; i<=n; i++) {
        int tmp;
        cin>>tmp;
        nums.vec.push_back(tmp);
        nums.maxn.push_back(1);
    }
    nums.maxn.at(1)=1;
    for(int i=2; i<=n; i++) {
        int tmp=0;
        for(int k=i-1; k>=1; k--) {
            if(tmp<nums.maxn.at(k)&&nums.vec.at(k)<nums.vec.at(i)) {
                tmp=nums.maxn.at(k);
            }
        }
        nums.maxn.at(i)=tmp+1;
    }
    int tmp=0;

    for(int i=1; i<=n; i++) {
         tmp=tmp>nums.maxn.at(i)?tmp:nums.maxn.at(i);
    }
    cout<<tmp;
    return 0;
}