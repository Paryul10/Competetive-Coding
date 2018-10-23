#include<bits/stdc++.h>

using namespace std;
//long long int sum[200005];
int main()
{
    int n;
    cin >> n;
    string arr[n];
    int len[n];
    pair<int,string> p[n];
    int i;
    for(i=0;i<n;i++)
    {
        cin >> arr[i];
        len[i]=arr[i].length();
    }
    //cout << arr[2] << '\n';
    for(i=0;i<n;i++)
    {
        p[i].first=len[i];
        p[i].second=arr[i];
    }
    sort(p,p+n);
    for(i=0;i<n;i++)
    {
        len[i]=p[i].first;
        arr[i]=p[i].second;
    }
    //cout << arr[1] << '\n';
    int j;
    int flag=1;
    for(i=n-1;i>=0;i--)
    {
        string s1=arr[i];
        {
            for(j=0;j<i;j++)
            {
                string s2=arr[j];
                //bool b = contains(s1,s2);
                if(!strstr(s1.c_str(),s2.c_str()))
                {
                    flag=0;
                    break;
                }
            }
        }
    }
    if(flag==1)
    {
        cout << "YES" << '\n';
        for(i=0;i<n;i++)
        {
            cout << arr[i] << '\n';
        }
    }
    else
    {
        cout << "NO" << '\n';
    }
}
