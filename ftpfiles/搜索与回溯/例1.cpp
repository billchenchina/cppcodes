#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int huan[21];
long long ttl=0;
bool use[21];
bool check(int a) {
	int sq=sqrt(a);
	for(int i=2; i<=sq; i++) {
		if(a%i==0)return false;
	}
	return true;
}
void print() {
	for(int i=1; i<21; i++) {
		cout<<huan[i]<<' ';
	}
	cout<<endl;

}
void tianshu(int Arr) {
	for(int i=1; i<21; i++) {
		if(!use[i]) {
			if(Arr>=2&&Arr<=19) {
				huan[Arr]=i;
				use[i]=1;
				if(check(huan[Arr]+huan[Arr-1])) {
					tianshu(Arr+1);
				}
				use[i]=0;
				huan[Arr]=0;
			} else if(Arr==20) {
				use[i]=1;
				huan[Arr]=i;
				if(check(huan[Arr]+huan[Arr-1])&&check(huan[Arr]+huan[1])) {
					print();
					ttl++;
				}
				use[i]=0;
			} else if(Arr==1) {
				huan[Arr]=i;
				use[i]=1;
				tianshu(Arr+1);
				use[i]=0;
			}

		}
	}

}
int main() {
	freopen("o.out","w",stdout);
	tianshu(1);
	cout<<ttl;
	fclose(stdout);
	return 0;
}
