/*
 * Accepted
 * Time: 20ms
 * Memory: 2580kb
 **/


#include <bits/stdc++.h>

#define YES "YES\n"
#define NO "NO\n"

using namespace std;

struct player {
    int type;
    int blood;
    int protection;
    int minus_blood;
    player() {
        minus_blood=1;
    }
    /*
     * @return true if alive
     * @return false if died
    */
    bool minusBlood(int delta) {
        if(protection<delta) {
            blood-=(delta-protection);
            protection=0;


        } else {
            protection-=delta;
        }
        if(blood>0)return true;
        else return false;
    }
    // @return true if player2 alive
    // @return false if player2 died
    bool attack(player & player2) {
        switch(this->type) {
        case 1:
            return player2.minusBlood(1);
            break;
        case 2:
            return player2.minusBlood(2);
            break;
        case 3:
            this->protection+=2;
            return true;
            break;
        case 4:
            this->blood+=(this->blood+2<=30?2:(this->blood+2==31)?1:0);
            return true;
            break;
        }
    }
};

int main() {
#ifndef bccdbg
    ifstream fin("legend.in");
    ofstream fout("legend.out");
#else
#define fin cin
#define fout cout
#endif // bccdbg

    int T;
    fin>>T;
    while(T--) {
        player player1,player2;
        fin>>player1.type>>player1.blood>>player1.protection;
        fin>>player2.type>>player2.blood>>player2.protection;
        while(true) {
#ifdef bccdbg
            cout<<"Round #"<<player1.minus_blood<<endl<<endl;
#endif // bccdbg

            if(!player1.minusBlood(player1.minus_blood)) {
                goto die;
            }
            player1.minus_blood++;
            if(!player2.minusBlood(player2.minus_blood)) {
                goto alive;
            }
            player2.minus_blood++;

            if(!player1.attack(player2)) {
                goto alive;
            }

            if(!player2.attack(player1)) {
                goto die;
            }

        }
        goto alive;
        continue;
die: {
            fout<<NO;
#ifdef bccdbg
            cout<<"Player1 "<<player1.blood<<" "<<player1.protection<<endl
                <<"Player2 "<<player2.blood<<" "<<player2.protection<<endl;
#endif // bccdbg
            continue;
        }

alive: {
            fout<<YES;
#ifdef bccdbg
            cout<<"Player1 "<<player1.blood<<" "<<player1.protection<<endl
                <<"Player2 "<<player2.blood<<" "<<player2.protection<<endl;
#endif // bccdbg
            continue;
        }
    }
}
