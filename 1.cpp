#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int arr[n+1];
    int i;
    int freq[101];
    int index[101];
    for(i=0;i<=100;i++)
    {
        freq[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
        index[arr[i]]=i;
    }
    int count=0;
    for(i=1;i<=100;i++)
    {
        if(freq[i]!=0)
        {
            count++;
        }
    }
    int counter=1;
    i=1;
    if(count>=k)
    {
        cout << "YES" <<'\n';
        while(i<=100 && counter<=k)
        {
            if(freq[i]!=0)
            {   
                cout << index[i] << " ";
                counter++;  
            }
            i++;
        }
        cout << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }

    return 0;
}