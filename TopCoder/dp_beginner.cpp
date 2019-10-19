// Given a list of N coins, their values (V1, V2, … , VN), and the total sum S. 
// Find the minimum number of coins the sum of which is S (we can use as many coins of one type as we want), 
// or report that it’s not possible to select coins in such a way that they sum up to S.

#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 7;
const int INF = 1e7;

int N;
int coins[MAXN];
int S;
int dp[1000][1000];

int min_coins(int idx, int sum)
{
    if (dp[idx][sum] != -1)
        return dp[idx][sum];
    if (idx == N)
    {
        if (sum == S)
        {
            dp[idx][sum] = 0;
            return 0;
        }
        dp[idx][sum] = INF;
        return INF;
    }
    dp[idx][sum] = min(min_coins(idx + 1, sum + coins[idx]) + 1, min_coins(idx + 1, sum));
    return dp[idx][sum];
}

int main()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> coins[i];
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
            dp[i][j] = -1;
    }
    min_coins(0, 0);
    cout << dp[0][0] << endl;
    return 0;
}