#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int n,a[1000],b[1000],ttl=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<n;i++){
		cin>>b[i];
		ttl+=a[i]*b[i];
	} 
	cout<<ttl;
	return 0;
}