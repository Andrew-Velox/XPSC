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
    ll len; cin >> len;
    vector<ll> v(len);
    for(int x=0; x<len; x++){
        cin >> v[x];
    }

    srt(v);


    ll min_a,min_b;
    ll mn=INT_MAX;
    for(int x=len-1; x>0; x--){
        ll get = v[x]-v[x-1];
        if(get<=mn){
            mn=get;
            min_a=v[x-1];
            min_b=v[x];
        }
    }

    vector<ll> after_a;
    bool f=false;
    ll in=0;
    for(int x=0; x<len; x++){
        if(v[x]==min_a && !f){
            in=x-1;
            x++;
            // if(min_a==min_b) x++;
            f=true;
            continue;
        }
        if(f){
            after_a.pb(v[x]);
        }
    }

    vector<ll> befor_b;
    
    for(int x=in; x>=0; x--){
        befor_b.pb(v[x]);
    }
    srt(after_a);
    srt(befor_b);
    // debug(after_a);
    // debug(befor_b);


    ll cnt=2;
    cout << min_a << " ";
    for(auto val: after_a) cout << val << " ";
    for(auto val: befor_b) cout << val << " ";
    cout << min_b << endl;
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}