#include <cstdio>
#include <vector>

using namespace std;
int ListSize=1000000;
vector<bool>isprime(ListSize+1,1);
vector<int>primeList;
int main() {
    isprime[1]=0;
    for(int i=2; i<=ListSize; ++i) {
        if(isprime[i])primeList.push_back(i);
        for(int j=0; j<primeList.size()&&i*primeList[j]<=ListSize; ++j) {
            isprime[i*primeList[j] ]=0;
            if(i%primeList[j]==0)break;
        }
    }
    int num;
    while(scanf("%d",&num)) {
            if(num==0)break;
        for(int i=0;i<primeList.size()&&primeList[i]*2<=num;++i) {
            if(isprime[num-primeList[i]]){
                printf("%d = %d + %d\n",num,primeList[i],num-primeList[i]);
                break;
            }
        }
    }
    return 0;
}
