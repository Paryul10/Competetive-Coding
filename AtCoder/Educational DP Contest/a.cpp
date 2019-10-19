#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 7;

long long height = 0;
long long dp[MAXN];
long long h[MAXN];
int n;

long long rec(int idx)
{
    if (dp[idx] != -1)
        return dp[idx];
    if (idx == n - 1)
    {
        dp[idx] = 0;
        return dp[idx];
    }
    if (idx == n - 2)
    {
        dp[idx] = abs(h[idx + 1] - h[idx]);
        return dp[idx];
    }
    dp[idx] = min(rec(idx + 1) + abs(h[idx + 1] - h[idx]), rec(idx + 2) + abs(h[idx + 2] - h[idx]));
    return dp[idx];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        dp[i] = -1;
    cout << rec(0) << endl;
    return 0;
}