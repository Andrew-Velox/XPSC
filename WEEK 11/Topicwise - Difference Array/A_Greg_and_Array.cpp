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
    ll len,k,q;
    cin >> len >> k >> q;
    ll kk=k,qq=q;
    vector<ll> v(len);

    for(int x=0; x<len; x++) cin >> v[x];

    vector<tuple<ll,ll,ll>> vt;
    while(k--){
        ll a,b,c; cin >> a >> b >> c;
        a--;b--;
        vt.pb({a,b,c});
    }

    vector<ll> dif_ar1(kk+1,0);
    while(q--){
        ll a,b;
        cin >> a >> b;
        a--,b--;
        dif_ar1[a]++;
        dif_ar1[b+1]--;
    }

    // debug(mp);
    
    debug(dif_ar1);
    for(int x=1; x<kk; x++) dif_ar1[x]+=dif_ar1[x-1];
    debug(dif_ar1);

    for(int x=0; x<kk; x++){
        get<2>(vt[x]) *= dif_ar1[x];
        // cout << get<2>(vt[x]) << " ";
    }
    // cout << endl;

    vector<ll> dif_ar2(len+1,0);
    for(int x=0; x<kk; x++){
        //get<0>(v[x])
        ll l = get<0>(vt[x]);
        ll r = get<1>(vt[x]);
        ll value = get<2>(vt[x]);
        dif_ar2[l] += value;
        dif_ar2[r+1] -= value;
    }

    for(int x=1; x<len; x++) dif_ar2[x]+=dif_ar2[x-1];
    debug(dif_ar2);

    for(int x=0; x<len; x++){
        cout << v[x]+dif_ar2[x] << " ";
    }
    cout << endl;

    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}