#include <cstdio>
#include <iostream>
using namespace std;
struct num{
    int in;
    int maxn;
    num(){
        maxn=0;
    }
}nums[1001];
int n;
int maxn;
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>nums[i].in;
        nums[i].maxn=nums[i].in;
        for(int j=i-1;j>=0;j--){
            if(nums[i].in>nums[j].in&&nums[i].maxn-nums[i].in<nums[j].maxn){
                nums[i].maxn=nums[j].maxn+nums[i].in;
            }
        }
        if(nums[i].maxn>maxn)maxn=nums[i].maxn;
    }
    cout<<maxn;
    return 0;
}