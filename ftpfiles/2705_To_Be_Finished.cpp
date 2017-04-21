#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string a;
	while(cin>>a) {
		char zhan[101];
		int Arr=0;
		for(int i=0; i<a.size(); i++) {
			if(a[i]=='(') {
				zhan[Arr]='(';
				Arr++;
			} else if(a[i]==')') {
				Arr--;
			}

		}
		if(Arr!=0) {
			cout<<abs(Arr);
			continue;
		}
	}
	return 0;
}


