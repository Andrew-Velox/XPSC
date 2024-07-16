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
    set<ll> st;
    for(int x=0; x<len; x++) {
        cin >> v[x];
        st.insert(v[x]);
    }

    if(st.size()==1){
        NO;
    }
    else{
        YES;

        ll d=0;
        vector<ll> get;
        for(int x=1; x<len; x++){
            if(v[0]!=v[x]){
                cout << 1 << " " << x+1 << endl;
                d=x+1;
            }
            else{
                get.pb(x+1);
            }

        }

        for(auto val: get){
            cout << d << " " << val << endl;
        }
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