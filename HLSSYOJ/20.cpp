#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
    string t = s;
    reverse(s.begin(), s.end());
    return s==t;
}

int main()
{
    string s;
    cin >> s;
    for(int i = 0; i <= 10; i++)
    {
        if(isPalindrome(s))
        {
            return cout << "YES", 0;
        }
        s = "0" + s;
    }

    cout << "NO";

}
