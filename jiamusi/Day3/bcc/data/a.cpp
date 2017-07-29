#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(0));
    ofstream fout("a_data.in");
    int n=50000;
    fout<<n<<endl;
    for(int i=0; i<n; i++)
    {
        fout<<rand()%1000000000<<' ';
    }
    fout<<endl;
    for(int i=0; i<n; i++)
    {
        fout<<rand()%1000000000<<' ';
    }
    fout<<endl;
    fout.close();
    double a=0.2147483647;
    cout<<a;
    return 0;
}
