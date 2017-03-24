#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int n,a,min,max;
	cin>>n;
	cin>>a;
	min=a;
	max=a;
	for(int i=1; i<n; i++) {
		cin>>a;
		if(a<min) {
			min=a;
		} else {
			min=min;
		}
		if(a>max) {
			max=a;
		} else {
			max=max;
		}
	}
	cout<<max-min;
	return 0;
}