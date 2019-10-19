#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'pilesOfBoxes' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY boxesInPiles as parameter.
 */

long pilesOfBoxes(vector<int> boxesInPiles)
{
    int n = boxesInPiles.size();
    sort(boxesInPiles.begin(), boxesInPiles.end());

    int f[2000005];
    for (int i = 0; i < 2000005; i++)
        f[i] = 0;
    for (int i = 0; i < n; i++)
        f[boxesInPiles[i]]++;
    int init = boxesInPiles[n - 1];
    int fin = boxesInPiles[n - 1];
    long count = 0;
    for (int i = init - 1; i >= boxesInPiles[0]; i--)
    {
        if (f[i] > 0)
        {
            fin = i;
            count += (long)f[init];
            f[fin] += f[init];
            init = i;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> box;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        box.push_back(a);
    }
    long ans = pilesOfBoxes(box);
    cout << ans << endl;
    return 0;
}