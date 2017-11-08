#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    srand(time(NULL));
    int timer=0;
    for(;;)
    {
        timer++;
        ofstream fout("data.in");
        int T=5;
        fout<<T<<"\n";
        for(int i=0;i<T;++i)
        {
            fout<<rand()%1000000009<<"\n";
        }
        fout.close();
        system("std.exe <data.in >std.out");
        system("hwb.exe <data.in >stu.out");
        ifstream stdans("std.out");
        int x;
        stdans>>x;
        stdans.close();
        ifstream yhyans("stu.out");
        int y;
        yhyans>>y;
        yhyans.close();
        cout<<"Hack unsuccessful on:"<<timer<<"\n";
        if(x!=y)
        {
            return 0;
        }
    }
}
