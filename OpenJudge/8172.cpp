#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char a[20];
	int l,tmp=0;
	gets(a);
	l=strlen(a);
	if(a[0]>='0'&&a[0]<='9') {
		cout<<"no";
	} else {
		for(int i=0; i<l; i++) {
			if((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')||(a[i]>='0'&&a[i]<='9')||a[i]=='_') {
				tmp=tmp;
			}else{
				tmp=1;
			}
		}
		if(tmp==0) {
			cout<<"yes";
		}else{
			cout<<"no";
		}
	}
	return 0;
}