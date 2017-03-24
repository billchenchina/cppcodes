#include<iostream>
#include<cstdio>
using namespace std;

int main() {
int n,b,c,a[1000];
scanf("%d",&n);
c=0;
for(int i=0;i<n;i++){
	scanf("%d",&a[i]);
} 
if(n==1){
	b=a[0];
} 
else{
for(int i=1;i<n;i++){
	if(a[c]<a[i]){
		c=i;
		b=a[i];
	}
	else{
		b=a[c];
	} 
}
}
printf("%d",b);
return 0;
}