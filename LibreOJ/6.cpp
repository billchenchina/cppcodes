#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::cout << "get_num" << std::endl;
	int n;
	cin >> n;
	vector<int> ans;
	for(int i=0;i<n;++i)
    {
        int l=0;
        int r=1000001;
        for(;;)
        {
            int mid=l+(r-l)/2;
            int ret=0;
            cout << "guess " << i << " " << mid << endl;
            cin >> ret;
            if(ret == -1)
            {
                l=mid+1;
            }
            else if(ret == 1)
            {
                r=mid;
            }
            else
            {
                ans.push_back(mid);
                break;
            }
        }
    }
    cout << "submit";
    for(const auto &i : ans)
    {
        cout << " " << i;
    }
    cout<<endl;

}
