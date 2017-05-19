/*
 * AC:
 *    #1 #12 #14 #15 #16 #17 #18 #19
 *
 *
 *
 *
 *
**/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    int maxt=0;

    vector<int>v(100000,-INT_MAX);
    cin>>n;
    while(n--) {
        int t,k;
        cin>>t>>k;
        maxt=t;
        while(k--) {
            int country;
            cin>>country;
            v[country]=t;
        }
        int ttl=0;
        for(vector<int>::iterator iter=v.begin(); iter!=v.end(); iter++) {
            if(*iter>maxt-86400) {
                ttl++;
            }
        }
        cout<<ttl<<endl;
    }



}
