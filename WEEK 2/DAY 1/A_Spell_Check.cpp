#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll len; cin>> len;
    string s; cin>> s;

    string mn="Timru";
    sort(s.begin(),s.end());

    if(s==mn) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}