#include <cstdio>
#include <iostream>
#include <queue>
#include <memory.h>
#define g graph
using namespace std;

int main() {
    int T;
    cin>>T;
    for(int i=0; i<T; i++) {
        int isInstalled[120];
        int graphforInstall[120][120],graphforUnInstall[120][120],numsforInstall[120],numsforUnInstall[120],qNum;
        memset(graphforInstall,0,sizeof(graphforInstall));
        memset(graphforUnInstall,0,sizeof(graphforUnInstall));
        memset(numsforInstall,0,sizeof(numsforInstall));
        memset(numsforUnInstall,0,sizeof(numsforUnInstall));
        memset(isInstalled,0,sizeof(isInstalled));
        int n;
        cin>>n;
        for(int j=1; j<n; j++) {
            scanf("%d",&numsforInstall[j]);
            //cin>>numsforInstall[j];
            for(int k=0; k<numsforInstall[j]; k++) {
                scanf("%d",&graphforInstall[i][k]);
                //cin>>graphforInstall[i][k];
                graphforUnInstall[graphforInstall[i][k]][numsforUnInstall[graphforInstall[i][k]]]=j;
                numsforUnInstall[graphforInstall[i][k]]++;
            }
        }
        //correct until here
        cin>>qNum;
        for(int j=0; j<qNum; j++) {
            string query;
            int packageNum;
            cin>>query;
            scanf("%d",&packageNum);
            //cin>>query>>packageNum;
            if(query[0]=='i') {
                int changeNum=0;
                queue<int>q;
                q.push(packageNum);
                while(!q.empty()) {
                    int t=q.front();
                    if(isInstalled[t]==1) {
                        q.pop();
                        continue;
                    }
                    for(int k=0; k<numsforInstall[t]; k++) {
                        int thist=graphforInstall[t][k];
                        if(isInstalled[thist]==1)continue;
                        else {
                            q.push(thist);
                        }
                    }
                    changeNum++;
                    q.pop();
                    isInstalled[t]=1;

                }
                printf("%d\n",changeNum);
                //cout<<changeNum<<endl;

            } else if(query[0]=='u') {
                int changeNum=0;
                queue<int>q;
                q.push(packageNum);
                while(!q.empty()) {
                    int t=q.front();
                    if(isInstalled[t]==0) {
                        q.pop();
                        continue;
                    }
                    for(int k=0; k<numsforUnInstall[t]; k++) {
                        int thist=graphforUnInstall[t][k];
                        if(isInstalled[thist]==0)continue;
                        else {
                            q.push(thist);
                        }
                    }
                    changeNum++;
                    q.pop();
                    isInstalled[t]=0;

                }
                printf("%d\n",changeNum);
                //cout<<changeNum<<endl;
            }

        }
    }
    return 0;
}
