#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 7;
const long long INF = 1e18;

long long height = 0;
long long dp[MAXN];
long long h[MAXN];
int n, k;

long long rec(int idx)
{
    if (dp[idx] != -1)
        return dp[idx];
    if (idx == n - 1)
    {
        dp[idx] = 0;
        return dp[idx];
    }
    dp[idx] = INF;
    for (int i = 1; i <= k; i++)
    {
        if (idx + i <= (n - 1))
        {
            dp[idx] = min(dp[idx], rec(idx + i) + abs(h[idx + i] - h[idx]));
        }
    }
    return dp[idx];
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        dp[i] = -1;
    cout << rec(0) << endl;
    return 0;
}