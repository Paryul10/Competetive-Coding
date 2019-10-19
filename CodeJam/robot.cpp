#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin >> t;
    int x = 1;
    while (t--)
    {
        int a;
        cin >> a;
        vector<string> pr;
        vector<int> len;
        int loop = 0;
        for (int i = 0; i < a; i++)
        {
            string t;
            cin >> t;
            pr.push_back(t);
            int l = t.size();
            len.push_back(l);
            if (l > loop)
                loop = l;
        }
        int chk[a];
        for (int i = 0; i < a; i++)
        {
            chk[i] = 1;
        }
        string ans;
        for (int i = 0; i < loop + 1; i++)
        {
            int s = 0, p = 0, r = 0;
            for (int j = 0; j < a; j++)
            {
                if (chk[j] == 1)
                {
                    if (pr[j][i % len[j]] == 'S')
                        s = 1;
                    else if (pr[j][i % len[j]] == 'P')
                        p = 1;
                    else if (pr[j][i % len[j]] == 'R')
                        r = 1;
                }
            }
            if (s == 1 && p == 1 && r == 1)
            {
                ans = "IMPOSSIBLE";
                break;
            }
            else if (s == 1 && p == 1)
            {
                ans += 'S';
            }
            else if (p == 1 && r == 1)
            {
                ans += 'P';
            }
            else if (r == 1 && s == 1)
            {
                ans += 'R';
            }
            else if (s == 1)
            {
                ans += 'R';
                break;
            }
            else if (p == 1)
            {
                ans += 'S';
                break;
            }
            else if (r == 1)
            {
                ans += 'P';
                break;
            }
            int l = ans.size();
            for (int j = 0; j < a; j++)
            {
                if (chk[j] == 1)
                {
                    if (ans[l - 1] == 'S' && pr[j][i % len[j]] == 'P')
                    {
                        chk[j] = -1;
                    }
                    if (ans[l - 1] == 'P' && pr[j][i % len[j]] == 'R')
                    {
                        chk[j] = -1;
                    }
                    if (ans[l - 1] == 'R' && pr[j][i % len[j]] == 'S')
                    {
                        chk[j] = -1;
                    }
                }
            }
        }
        cout << "Case #" << x << ": " << ans << endl;
        x++;
    }
}