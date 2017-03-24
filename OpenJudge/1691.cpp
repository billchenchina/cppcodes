#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char cd(char i){
	if(i>='a'&&i<='z'){
		i=i-'a'+'A';
		return i;
	}else if(i>='A'&&i<='Z'){
		i=i-'A'+'a';
		return i;
	}else{
		return i;
	}
}
int main() {
	char a[80],b;
	int l;
	gets(a);
	l=strlen(a);
	for(int i=0;i<l;i++){
		b=cd(a[i]);
		printf("%c",b);
	}
	return 0;
}