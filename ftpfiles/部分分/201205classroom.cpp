#include <cstdio>
#include <iostream>
using namespace std;
int day[1000001],bj[1000001];
int main() {
	int f=0;
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>day[i];
	}
	for(int i=1; i<=m; i++) {
		int l,r,num,pd=0;
		cin>>num>>l>>r;
		for(int j=l; j<=r; j++) {
			if(day[j]<num) {
				cout<<-1<<endl<<i;
				return 0;
			}
		}
		if(pd!=0) {
			f++;
			continue;
		}
		for(int i=1; i<=r; i++) {
			day[i]-=num;
		}
	}
	if(f==0) {
		cout<<0;
		return 0;
	}
	return 0;
}
