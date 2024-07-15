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
    ll q; cin >> q;

    vector<set<ll>> vv(q);
    set<ll> st;
    for(int x=1; x<=q; x++){
        ll len; cin >> len;

        for(int y=0; y<len; y++){
            ll values; cin >> values;
            vv[x-1].insert(values);
            st.insert(values);
        }
    }

    // debug(st);
    debug(vv);

    ll ans=INT_MIN;
    for(int check=1; check<=50; check++){
        set<ll> new_st;

        for(int y=0; y<q; y++){
            if(vv[y].find(check) == vv[y].end()){
                for(auto val: vv[y]){
                    new_st.insert(val);
                    // cout << val << " ";
                }
            }
        }
        if(st!=new_st) ans=max(ans,(ll)new_st.size());
    }

    

    cout << ans << endl;


}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}