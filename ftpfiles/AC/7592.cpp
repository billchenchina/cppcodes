#include <cstdio>
#include <iostream>
using namespace std;
int gongyue(int a,int b){
	if(a<b){
		int tmp=a;a=b;b=tmp;
	}
	if(a!=0&&b!=0){
		if(a%b!=0){
			return gongyue(b,a%b);
		}else{
			return b;
		}
	}
}
int main() {
	int a,b;
	cin>>a>>b;
	
	cout<<gongyue(a,b); 
	return 0;
}


