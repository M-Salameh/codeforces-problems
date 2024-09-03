#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool unlocked[4];
int key[4];
int n;
string ans[10100];
void read(int rec)
{
    memset(unlocked , false , sizeof(unlocked));
    cin >> n;
    unlocked[n]=true;
    unlocked[0]=true;
    for (int i=1; i<=3 ; i++)
    {
        cin >> key[i];
    }
    int i=n;
    while ((key[i] !=0 && unlocked[i]))
    {
        unlocked[key[i]] = true;
        i=key[i];
    }
    if (unlocked[1]&&unlocked[2]&&unlocked[3])
    {
        ans[rec] = "YES";
        return;
    }
    else ans[rec]="NO";
    return;
}

int main()
{
    int tc;
    cin >> tc;
    for (int i=1; i<=tc ; i++)
    {
        read(i);
    }
    for (int i=1 ; i<=tc ; i++)
    {
        cout << ans[i] <<endl;
    }
    return 0;
}
