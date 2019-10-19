#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'betterCompression' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string betterCompression(string s)
{
    int l = s.size();
    int f[26];
    for (int i = 0; i < 26; i++)
        f[i] = 0;
    int c = 0;
    int count = 0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
        {
            f[c] += count;
            c = s[i] - 97;
            count = 0;
        }
        else
        {
            count = count * 10 + (s[i] - 48);
        }
    }
    f[c] += count;
    string ans;
    for (int i = 0; i < 26; i++)
    {
        if (f[i] > 0)
        {
            ans += i + 97;
            ostringstream t1;
            t1 << f[i];
            string t = t1.str();
            ans += t;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    string ans = betterCompression(s);
    cout << ans << endl;
    return 0;
}