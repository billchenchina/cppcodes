#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct friend_city
{
    int city_a;
    int city_b;
    int maxn;
    friend_city(){
        maxn=1;
    }
} pairs[5001];
int n;
bool rule1(friend_city a,friend_city b)
{
    return a.city_a<b.city_a;
}
int main()
{
    freopen("ship.in","r",stdin);
    freopen("ship.out","w",stdout);
    int maxn=1;;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>pairs[i].city_a>>pairs[i].city_b;
    }
    sort(pairs,pairs+n,rule1);
    for(int i=1;i<n;i++){

        for(int j=i-1;j>=0;j--){
            if(pairs[i].city_b>pairs[j].city_b&&pairs[i].maxn-1<pairs[j].maxn){
                pairs[i].maxn=pairs[j].maxn+1;
            }

        }
        if(maxn<pairs[i].maxn){
            maxn=pairs[i].maxn;
        }
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
