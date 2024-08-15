#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll len; cin >> len;

    vector<ll> v(len);

    for(int x=0; x<len; x++) cin >>v[x];
    sort(v.begin(),v.end());

    // for(int x=0; x<len; x++) cout <<v[x] << " ";
    // cout << endl;

    ll sm=0;
    for(int x=0; x<len-1; x++){
        ll cnt=0;
        while(x<len-1 && v[x]==v[x+1]){
            cnt++;
            x++;
        }
        sm+=cnt;
    }

    if(sm%2==0) cout <<len-sm << endl;
    else cout << len-sm-1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}