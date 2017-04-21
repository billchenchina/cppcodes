#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int a[15],i=1,n,ttl=0;
    scanf("%d",&a[0]);
    while(a[i-1]!=0) {
        scanf("%d",&a[i]);
        i++;
    }
    n=i;
    for(i=0; i<n-1; i++) {
        for(int k=0; k<n-1; k++) {
            if((a[i]%a[k]==0)&&(a[i]/a[k]==2)) {
                ttl++;
            }
        }
    }
    cout<<ttl;
    return 0;
}
