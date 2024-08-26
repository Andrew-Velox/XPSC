#include <bits/stdc++.h>
using namespace std;

#ifdef velox
#include "debug.h"
#else
#define debug(x...)
#endif

#define ll long long
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define unq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl '\n'
#define fx(x) fixed<<setprecision(x)

void error_txt(){
    #ifdef velox
    freopen("error.txt","w",stderr);
    #endif
}

ll msb(ll val){ // (__lg)
    ll cnt=0;
    while(val!=0){
        val>>=1;
        cnt++;
    }
    return cnt;
}


void solve(){
    ll len; cin >> len;

    vector<ll> v(len);

    map<ll,ll> cnt;

    for(int x=0; x<len; x++){
        ll val; cin >> val;
        // cnt[msb(val)];
        cnt[__lg(val)]++;
    }

    ll ans=0;

    for(auto it=cnt.begin(); it!=cnt.end(); it++){
        // cout << "last_bit:" << it->first << " " << "Ache: "<<  it->second << endl;
        debug(*it);
        ll x=it->first;
        ll y=it->second;

        ans+=((y*(y-1))/2); // formula -> ( (n*(n-1))/2 )
    }

    cout << ans << endl;

    // for(auto [x, y]: cnt){
    //     cout << x << " " << y << endl;
    // }

}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}