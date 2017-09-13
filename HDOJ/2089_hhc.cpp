#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dp_func(int len, bool first_digit_is_2, bool is_top_digit, const vector<int> &digit, vector<vector<int> > &dp)
{
    if (is_top_digit)
    {
        if (len == 0)
        {
            return 1;
        }
        int rs = 0;
        for (int i = 0; i <= digit[len - 1]; ++i)
        {
            if (i != 4 && !(first_digit_is_2 && i == 2))
            {
                rs += dp_func(len - 1, i == 6, i == digit[len - 1], digit, dp);
            }
        }
        return rs;
    }
    if (dp[len][first_digit_is_2] == -1)
    {
        if (len == 0)
        {
            dp[len][first_digit_is_2] = 1;
        }
        else
        {
            int rs = 0;
            for (int i = 0; i <= 9; ++i)
            {
                if (i != 4 && !(first_digit_is_2 && i == 2))
                {
                    rs += dp_func(len - 1, i == 6, false, digit, dp);
                }
            }
            dp[len][first_digit_is_2] = rs;
        }
    }
    return dp[len][first_digit_is_2];
}

int solve(int x)
{
    vector<int> digit;
    for (int i = x; i > 0; i /= 10)
    {
        digit.push_back(i % 10);
    }
    vector<vector<int> > dp(digit.size() + 1, vector<int>(2, -1));
    return dp_func(digit.size(), false, true, digit, dp);
}

int main()
{
    for (int n, m; cin >> n >> m, n != 0 && m != 0; )
    {
        cout << solve(m) - solve(n - 1) << endl;
    }

    return 0;
}
