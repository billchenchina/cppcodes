#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int a,b,n,tmp=0,max=-1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a>=90&&a<=140&&b>=60&&b<=90){
			tmp++;
			if(tmp>max){
				max=tmp;
			}
		}
		else{
			tmp=0;
		}
	}
	cout<<max;
	return 0;
}
