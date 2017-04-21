#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline int getCardValue(string s);
inline int getGrade(string s);
int T;

int main() {
    cin>>T;
    while(T--){
        vector<pair<int,int> >v1,v2;
        string s1,s2,s3,s4;
        cin>>s1>>s2>>s3>>s4;
        v1.push_back(pair<int,int>(getCardValue(s1),getGrade(s1)));
        v1.push_back(pair<int,int>(getCardValue(s3),getGrade(s3)));
        v2.push_back(pair<int,int>(getCardValue(s2),getGrade(s2)));
        v2.push_back(pair<int,int>(getCardValue(s4),getGrade(s4)));

    }
    return 0;
}

inline int getCardValue(string s) {
    switch(s.c_str()[0]){
    case 'A':
        return 14;
    case 'K':
        return 13;
    case 'Q':
        return 12;
    case 'J':
        return 11;
    case '1':
        return 10;
    default:
        return s.c_str()[0]-'0';
    }
}

inline int getGrade(string s){
    switch(s.c_str()[0]){
    case 'A':
        return 1;
    case 'K':
        return 13;
    case 'Q':
        return 12;
    case 'J':
        return 11;
    case '1':
        return 10;
    default:
        return s.c_str()[0]-'0';
    }
}
