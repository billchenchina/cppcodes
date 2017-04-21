#include <cstdio>
#include <iostream>
using namespace std;
int main() {
int n,m,fajom[100000];
cin>>n>>m;
for(int i=0;i<n;i++){
	scanf("%d",&fajom[i]);
}
for(int i=0;i<n-m;i++){
	int qs,min=100000;
	for(int k=0;k<n-1;k++){
		if(fajom[k]+fajom[k+1]<min){
			qs=k;
		}
	}
	fajom[qs]+=fajom[qs+1];
	for(int k=qs+1;k<n-1;k++){
		fajom[k]=fajom[k+1];
	}
	n--;
}
int max=0;
for(int i=0;i<m;i++){
	if(fajom[i]>max){
		max=fajom[i];
	}
}
cout<<max;
	return 0;
}


