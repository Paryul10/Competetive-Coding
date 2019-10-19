#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1000;
const long long INF = -1e18;
int N, W;
int w[MAXN];
long long v[MAXN];
long long dp[105][100005];

long long rec(int idx, int weight)
{
    if (weight > W)
    {
        return INF;
    }
    if (dp[idx][weight] != -1)
        return dp[idx][weight];

    if (idx == N)
    {
        if (weight > W)
            return INF;
        return 0;
    }
    dp[idx][weight] = max(rec(idx + 1, weight + w[idx]) + v[idx], rec(idx + 1, weight));
    return dp[idx][weight];
}

int main()
{
    cin >> N >> W;
    for (int i = 0; i < N; i++)
        cin >> w[i] >> v[i];
    for (int i = 0; i < 105; i++)
        for (int j = 0; j < 100005; j++)
            dp[i][j] = -1;
    cout << rec(0, 0) << endl;
    return 0;
}