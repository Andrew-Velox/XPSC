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
    ll len, mn, mx, dif;
    cin >> len >> mn >> mx >> dif;

    vector<ll> v(len);
    for(int x=0; x<len; x++) cin >> v[x];


    vector<vector<ll>> sub_s;
    for(int x=0; x<(1<<len); x++){
        vector<ll> sub;
        for(int y=0; y<len; y++){
            if((x>>y)&1){
                sub.push_back(v[y]);
            }
        }
        if(sub.size()!=0) sub_s.push_back(sub);
    }

    ll ans=0;

    for(int x=0; x<sub_s.size(); x++){
        ll sum=0;
        ll sml=INT_MAX;
        ll big=INT_MIN;
        for(auto val: sub_s[x]){
            sum+=val;
            sml=min(sml,val);
            big=max(big,val);
        }

        if(sum>=mn && sum<=mx && abs(sml-big)>=dif) ans++;
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