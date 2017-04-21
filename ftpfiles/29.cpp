#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int n,a,si,san,er,yi,k;
	cin>>n;
	k=0;
	for(int i=0; i<n; i++) {
		cin>>a;
		si=a/1000;
		a=a%1000;
		san=a/100;
		a=a%100;
		er=a/10;
		a=a%10;
		yi=a;
		if(yi-si-san-er>0) {
			k++;
		} else {
			k=k;
		}
	}
	cout<<k;
	return 0;
}
