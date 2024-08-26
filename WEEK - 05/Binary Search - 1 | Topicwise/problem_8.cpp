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




int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t=1;
    while(1){
        ll len, q; cin >> len >> q;
        if(len==0 && q==0) return 0;
        vector<ll> v(len);

        for(int x=0; x<len; x++) cin >> v[x];
        srt(v);

        cout << "CASE# " << t << ":" << endl;
        while(q--){
            ll val; cin >> val;
            auto it=lower_bound(v.begin(), v.end(),val);
            if(*it!=val) cout << val << " not found" << endl;
            else cout << val << " found at " << ++it-v.begin() << endl;
        }
        t++;
    }
    return 0;
}