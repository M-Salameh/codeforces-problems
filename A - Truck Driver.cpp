#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
int k;
int x;

int main()
{
    cin >> k;
    priority_queue <int> pq;
    s="a";
    while (s!="\0")
    {
        cin >> s;
        x =  stoi (s);
        pq.push(x);
    }
    return 0;
}
