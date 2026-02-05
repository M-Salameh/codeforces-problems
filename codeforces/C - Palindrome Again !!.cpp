#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


int minf(char a,char b)
{
    if(a<b)
    {
        return min(abs(int(a)-int(b)),(int('z')-int(b))+int(a)-int('a')+1);
    }
    else
    {
     return minf(b,a);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int tc=1;
    cin >> tc;
    while(tc--)
    {
        int n,p;
        cin>>n>>p;
        vector <int> pos;
        string s;
        cin>>s;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=s[n-i-1])
            {
            pos.push_back(i+1);
            if(i<n/2) ans+=minf(s[i],s[n-i-1]);
            }
        }

        if(pos.size()==0)
        {
            cout<<0<<endl;
        }
        else
        {
            int posb1=pos[0];

            int low=lower_bound(pos.begin(),pos.end(),n/2)-pos.begin();
            int posf1;

            if (pos[low]!=n/2 && low) posf1 = pos[low-1];
            else posf1=n/2;

            int posb2;
            if (pos[low]==n/2 && low<n) posb2 = pos[low+1];
            else posb2 = pos[low];

            int posf2 = pos[pos.size()-1];

            if(p<=n/2)
            {
                ans += min(abs(p-posb1),abs(p-posf1))+posf1-posb1;
            }
            else
            {
                ans += min(abs(p-posb2),abs(p-posf2))+posf2-posb2;
            }
            cout<< ans <<endl;
        }
    }
    return 0;
}
