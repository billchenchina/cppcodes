#include "testlib.h"
#include <iostream>
#include <vector>

<<<<<<< HEAD
// checker of "¼ÒÆ×Ê÷"
=======
// checker of å®¶è°±æ ‘
>>>>>>> remotes/origin/master
int main(int argc,char *argv[])
{
    setName("Test the answer");
    registerTestlibCmd(argc, argv);
    bool correct=1;
    int N;
    N=inf.readInt();
    std::vector<int>pos(N+1,0);
    for(int i=1; i<=N; i++) {
        int a;
        a=ouf.readInt();
        pos[a]=i;
    }
    for(int i=1; i<=N; i++) {
        while(true) {
            int a;
            a=inf.readInt();
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




