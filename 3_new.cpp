#include<bits/stdc++.h>
using namespace std;
long long int sum[200005];
int main()
{
    int k;
    cin >> k;
    vector<int> v[200005];
    //vector<int> newsum[200005];
    int len[200005];
    int sumlength=0;
    //long long int sum[200005];
    int i,j;
    for(i=0;i<k;i++)//o based for both k and seqy=uences
    {
        cin >> len[i];
        sumlength+=len[i];
        for(j=0;j<len[i];j++)
        {
            int p;
            cin >> p;
            sum[i]+=p;
            v[i].push_back(p);
        }
    }
}
