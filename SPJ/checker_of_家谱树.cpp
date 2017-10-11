#include "testlib.h"
#include <iostream>
#include <vector>
#include <set>

int main(int argc,char *argv[])
{
    setName("Test the answer");
    registerTestlibCmd(argc, argv);
    bool correct=true;
    int N;
    N=inf.readInt();
    std::vector<int>vec(N+1,0);
    std::vector<int>vec2(N+1,0);
    for(int i=1; i<=N; ++i)
    {
        if(ouf.eof())
        {
            quitf(_wa, "The answer is wrong");
            return 0;
        }
        vec[i]=ouf.readInt(1,N);
        vec2[vec[i]]=i;
    }
    for(int fa=1; fa<=N; ++fa)
    {
        int son;
        for(;;)
        {
            son=inf.readInt(0,N);
            if(son==0)
            {
                break;
            }
            if(vec2[son]<vec2[fa])
            {
                quitf(_wa,"The answer is wrong");
            }
        }

    }
    quitf(_ok, "The answer is correct.");
}
