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
    ll len, q; cin >> len >> q;

    vector<ll> v(len); 
    for(int x=0; x<len; x++) cin >> v[x];

    while(q--){
        ll val; cin >> val;

        ll l=0,r=len-1,in=-1;

        while(l<=r){
            ll mid = (l+r)/2;

            if(v[mid]>=val){
                in = mid;
                r = mid-1;
            }

            else l = mid+1;
        }


        if(in==-1) cout << len+1 << endl;
        else cout << in+1 << endl;

    
    }
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}