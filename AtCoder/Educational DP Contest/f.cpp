#include "bits/stdc++.h"
using namespace std;

string s, t;
int sl, tl;
int dp[4000][4000];

void print(int sp, int tp)
{
    if (sp == sl || tp == tl)
        return;
    if (s[sp] == t[tp])
    {
        if (dp[sp + 1][tp + 1] + 1 >= dp[sp + 1][tp] && dp[sp + 1][tp + 1] + 1 >= dp[sp][tp + 1])
        {
            cout << s[sp];
            print(sp + 1, tp + 1);
        }
        else if (dp[sp + 1][tp] >= dp[sp + 1][tp + 1] + 1 && dp[sp + 1][tp] >= dp[sp][tp + 1])
            print(sp + 1, tp);
        else if (dp[sp][tp + 1] >= dp[sp + 1][tp + 1] + 1 && dp[sp][tp + 1] >= dp[sp + 1][tp])
            print(sp, tp + 1);
    }
    else
    {
        if (dp[sp + 1][tp] > dp[sp][tp + 1])
            print(sp + 1, tp);
        else
            print(sp, tp + 1);
    }
}

int rec(int sp, int tp)
{
    if (sp == sl || tp == tl)
        return 0;
    if (dp[sp][tp] != -1)
        return dp[sp][tp];
    if (s[sp] == t[tp])
    {
        dp[sp][tp] = max(rec(sp + 1, tp + 1) + 1, rec(sp + 1, tp));
        return dp[sp][tp] = max(dp[sp][tp], rec(sp, tp + 1));
    }
    return dp[sp][tp] = max(rec(sp + 1, tp), rec(sp, tp + 1));
}

int main()
{
    cin >> s >> t;
    sl = s.length();
    tl = t.length();
    for (int i = 0; i < 4000; i++)
        for (int j = 0; j < 4000; j++)
            dp[i][j] = -1;
    rec(0, 0);
    print(0, 0);
    cout << endl;
    return 0;
}