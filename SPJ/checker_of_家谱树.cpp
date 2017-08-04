#include "testlib.h"
#include <iostream>
#include <vector>
#include <set>

int main(int argc,char *argv[])
{
    setName("Test the answer");
    registerTestlibCmd(argc, argv);
    bool correct=1;
    int N;
    N=inf.readInt();
    std::vector<int>pos(N+1,0);
    std::set<int>answer_set;
    for(int i=1; i<=N; i++) {
        int a;
        a=ouf.readInt();
        pos[a]=i;
        answer_set.insert(i);
    }
    std::set<int>output_set;
    for(int i=1; i<=N; i++) {
        while(true) {
            int a;
            a=inf.readInt();
            output_set.insert(a);
            if(a!=0) {
                if(pos[i]>pos[a])
                    correct=0;
            } else break;
        }
    }
    if(correct) {
        quitf(_ok, "The answer is correct.");
    } else {
        quitf(_wa, "The answer is wrong");
    }
}
