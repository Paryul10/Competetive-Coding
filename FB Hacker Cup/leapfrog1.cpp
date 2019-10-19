#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin >> t;
    int x = 1;
    while (t--)
    {
        string s;
        cin >> s;
        int len = s.size();
        int nb = 0, nu = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == 'B')
                nb++;
            else if (s[i] == '.')
                nu++;
        }
        cout << "Case #" << x << ": ";
        if (nu >= 1 && nb >= nu)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
        x++;
    }
    return 0;
}