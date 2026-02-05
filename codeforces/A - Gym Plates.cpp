#include <bits/stdc++.h>
#define int long long
#define double long double
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define endl '\n'
using namespace std;

int tc = 1;
int n;
int arr[105];
int dp[105][3][3][3][3][3][3][3][3][3][3];
int freq[105][10];
bool leave[105];



int solve(int i , vector<int> cur_freq)
{
    if (i > n) return 0;
    int& ret = dp[i][cur_freq[0]][cur_freq[1]][cur_freq[2]][cur_freq[3]][cur_freq[4]][cur_freq[5]][cur_freq[6]][cur_freq[7]][cur_freq[8]][cur_freq[9]];

    if (ret + 1) return ret;
    int p1 = 0 , p2 = 0;

    if (leave[i])
    {
        return ret = solve(i+1 , cur_freq);
    }

    vector<int> new_freq = cur_freq;

    bool can_take = true;

    for (int j = 0 ; j <= 9 ; j++)
    {
        if (freq[i][j] + cur_freq[j] < 3)
        {
            new_freq[j] = freq[i][j] + cur_freq[j];
        }
        else
        {
            can_take = false;
            break;
        }
    }
    if (can_take)
    {
        p1 = arr[i] + solve(i+1 , new_freq);
        p2 = solve(i+1 , cur_freq);
        return ret = max(p1 , p2);
    }

    return ret = solve(i+1 , cur_freq);

}


void reset()
{
    for (int i=1 ; i<=n ; i++)
    {
        arr[i] = 0;
        leave[i] = false;
    }
    memset(dp , -1 , sizeof(dp));
    memset(freq , 0 , sizeof(freq));

}

signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        reset();
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
            int temp = arr[i];

            while(temp)
            {
                freq[i][temp%10]++;
                leave[i] |= (freq[i][temp%10]>2);
                temp /= 10;
            }
        }
        vector<int> fr (11 , 0);
        cout << solve(1 , fr) << endl;

    }
    return 0;
}
