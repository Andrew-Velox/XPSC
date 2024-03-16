#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll len; cin >> len;

    vector<ll> v(len-1);
    for(int x=0; x<len;x++) cin >> v[x];

    sort(v.begin(),v.end());

    ll i=1;

    for(int val: v){
        if(val!=i) break;
        i++;
    }

    cout << i << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}