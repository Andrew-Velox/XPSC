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

const ll N = 2e5+10;
vector<ll> v(N);
vector<ll> mk(N);

void solve(){
    ll n,k,q;
    cin >> n >> k >> q;
    
    while(n--){
        ll a,b; cin >> a >> b;
        v[a]++;
        v[b+1]--;
    }
    for(int x=1; x<N; x++){
        v[x]=v[x-1]+v[x];
    }
    // for(int x=0; x<N; x++){
    //     if(v[x]>0) cout << v[x] << " ";
    // }
    // cout << endl;

    for(int x=1; x<N; x++){        
        if(v[x] >=k) mk[x] +=mk[x-1]+1;
        else mk[x]+=mk[x-1];

    }
    // for(int x=0; x<N; x++){
    //     if(mk[x]>0) cout << mk[x] << " ";
    // }
    // cout << endl;

    while(q--){
        ll l,r; cin >> l >> r;
        // debug(mk[r], mk[l-1]);
        cout << mk[r]-mk[l-1] << endl;
    }

    
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}