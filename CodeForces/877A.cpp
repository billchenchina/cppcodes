// FST
#include <bits/stdc++.h>

using namespace std;

string name_list[]={"Danil","Olya","Slava","Ann","Nikita",};

int len[]={5,4,5,3,6};

int main()
{
    string a;
    cin>>a;
    int k=0;
    for(int i=0;i<5;++i)
    {
        for(int j=0;j<a.size();++j)
        {
            if(a.substr(j,len[i])==name_list[i])
            {
                k++;
            }
        }
    }
    if(k==1)
    {
        cout<<"YES";
    }
    else cout<<"NO";
    return 0;
}
