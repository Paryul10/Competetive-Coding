#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int x = 1;
    while (t--)
    {
        string n;
        cin >> n;
        long long int N = stoi(n);
        int l = n.size();
        string n1;
        for (int i = 0; i < l; i++)
        {
            if (n[i] == '4')
                n[i] = '3';
        }
        long long int N1 = stoi(n);
        long long int N2 = N - N1;
        cout << "Case #" << x << ": " << N1 << " " << N2 << endl;
        x++;
    }
    return 0;
}