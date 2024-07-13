#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifdef velox
#include "debug.h"
#else
#define debug(x...)
#endif

#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define unq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define set_bits(x) __builtin_popcountll(x)
#define fst_zero(x) 63-__builtin_ctzll(x)
#define lst_zero(x) __builtin_ctzll(x)
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) ((x/gcd(x,y))*y)
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define ll long long
#define pb push_back
#define endl '\n'
#define fx(x) fixed<<setprecision(x)
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void error_txt(){
    #ifdef velox
    freopen("error.txt","w",stderr);
    #endif
}



void solve(){
    ll len,k; cin >> len >> k;

    ll ans=LLONG_MAX;
    vector<ll> v(len);
    for(int x=0; x<len; x++){
        cin >> v[x];
        ans=min(ans,v[x]);
    }

    if(k>=3){
        cout << 0 << endl;
    }
    else if(len==1){
        cout << ans << endl;
        return;
    }
    srt(v);
    for(int x=1; x<len; x++){
        ans=min(ans,abs(v[x-1]-v[x]));
    }
    if(k==1){
        cout << ans << endl;
    }

    else if(k==2){
        // vector<ll> mk;
        // vector<tuple<ll,ll,ll>> vk;
        debug(ans);
        for(int x=0; x<len-1; x++){
            for(int y=x+1; y<len; y++){

                ll get= abs(v[x]-v[y]);
                ll f = lower_bound(v.begin(),v.end(), get) - v.begin();
                if (f < len) ans = min(ans, v[f] - get);
                if (f > 0) ans = min(ans, get - v[f - 1]);
                debug(f);
                // vk.pb({v[x],v[y],abs(v[x]-v[y])});
            }
        }

        // for(int x=0; x<len; x++){
        //     cout << get<0>(vk[x]) << ", " << get<1>(vk[x]) << ", " << get<2>(vk[x]) << endl;
        
        
        cout << ans << endl;
    
    }
    
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}