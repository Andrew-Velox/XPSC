#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll len; cin >> len;

    string a,b;
    cin >> a;
    cin >> b;

    // cout << a << endl << b << endl;


    ll cnt=0;
    for(int x=0; x<len; x++){
        if((a[x]=='R' && b[x]!='R') || (a[x]!='R' && b[x]=='R')) break;
        cnt++;
    }

    if(cnt==len) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}