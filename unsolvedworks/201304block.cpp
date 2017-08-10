#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int n,h[100000],maxn=1,minn=1000000,ttl=0,l=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d",&h[i]);
        if(h[i]>maxn) maxn=h[i];
        if(h[i]<minn) minn=h[i];
    }

    while(maxn>0) {
        int maxc=0;
        for(int i=l; i<n; i++) {
            if(h[i]>maxc) {
                maxc=h[i];
            }
        }
        if(h[l]==0) {
            l++;
            continue;
        }
        ttl++;
        int i=l;
        while(h[i]!=0) {
            h[i]--;
            i++;
        }
        maxn=0;
        for(int i=l;i<n;i++){
            if(h[i]>maxn)maxn=h[i];
        }
    }
    cout<<ttl;
    fclose(stdin);fclose(stdout);
    return 0;
}
