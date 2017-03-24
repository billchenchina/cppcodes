#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin>>s;
    int count=0,last=s[0]-'0';
    for(int i=0;i<s.length();i++){
        if(s[i]-'0'==last){
            count++;
        }
        else{
            cout<<count<<last;
            count=1;
            last=s[i]-'0';
        }
    }
    cout<<count<<last; 
    return 0;
}