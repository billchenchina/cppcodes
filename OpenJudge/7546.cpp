#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char a[255];
int main() {
	int l=0,ttl=0;
	gets(a);
	l=strlen(a);
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9'){
			ttl++;
		}
	}
	cout<<ttl;
	return 0;
}
