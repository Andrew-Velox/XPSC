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
    ll len,q; cin >> len >> q;
    vector<ll> v(len);

    ll sum=0;
    for(int x=0; x<len; x++){
        cin >> v[x];
        sum+=v[x];
    }

    grtsrt(v);
    vector<ll> p_sum(len);
    ll sm=0;
    for(int x=0; x<len; x++){
        sm+=v[x];
        p_sum[x]=sm;
    }


    while(q--){
        ll val; cin >> val;
        if(val>sum) cout << -1 << endl;
        else{

            auto it = lower_bound(p_sum.begin(),p_sum.end(),val);
            it++;
            cout << it-p_sum.begin() << endl;
        }
    }
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
} 
