#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll len; cin>>len;

    vector<ll> v(len+1);
    for(int x=1; x<=len; x++) cin >> v[x];
    // for(int x=1; x<=len; x++) cout<< v[x]<<" ";

    if(len==1) cout << v[len]-len << endl;
    else{

        ll mx=v[1];

        ll in=1,cnt=0;;
        for(ll x=1; x<=len; x++){
            if(v[x]>in){
                cnt+=v[x]-in;
                in=v[x]+1;
            }
            else in++;
        }

        cout << cnt << endl;

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}