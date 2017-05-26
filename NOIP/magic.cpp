#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct item {
    int magicValue;
    int id;
};
struct cmp {
    bool operator ()(const item &item1,const item &item2) {
        return item1.magicValue<item2.magicValue;

    }
};
int main() {
    int n,m;
    cin>>n>>m;
    vector<item>itemStack(m);
    for(int i=0; i<m; i++) {
        cin>>itemStack[i].magicValue;
        itemStack[i].id=i+1;
    }
    sort(itemStack.begin(),itemStack.end(),cmp());

    return 0;
}
