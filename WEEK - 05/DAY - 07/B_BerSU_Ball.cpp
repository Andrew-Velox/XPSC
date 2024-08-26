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


void solve(){
    ll len1; cin >> len1;
    map<ll,ll> mp;

    for(int x=0; x<len1; x++){
        ll val; cin >> val;
        mp[val]++;
    }

    ll len2; cin >> len2;
    vector<ll> vv(len2);
    for(int x=0; x<len2; x++){
        ll val; cin >> val;
        vv[x]=val;
    }


    ll ans=0;
    srt(vv);
    for(auto val: vv){
        if(mp[val-1] != 0){
            ans++;
            mp[val-1]--;
        }
        else if(mp[val] !=0){
            ans++;
            mp[val]--;
        }
        else if(mp[val+1] != 0){
            ans++;
            mp[val+1]--;
        }
    }

    cout << ans << endl;
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}