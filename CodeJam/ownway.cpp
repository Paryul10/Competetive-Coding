#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin >> t;
    int x = 1;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int l = s.size();
        for (int i = 0; i < l; i++)
        {
            if (s[i] == 'S')
                s[i] = 'E';
            else
                s[i] = 'S';
        }
        cout << "Case #" << x << ": " << s << endl;
        x++;
    }
    return 0;
}