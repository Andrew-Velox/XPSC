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
const ll MOD = 1e9+7;

void error_txt(){
    #ifdef velox
    freopen("error.txt","w",stderr);
    #endif
}



void solve(){
    int len; cin >> len;
    int k; cin >> k;

    vector<int> v(len),vv(len);

    for(int x=0; x<len; x++) cin >> v[x];
    for(int x=0; x<len; x++) cin >> vv[x];
    
    srt(v);
    srt(vv);


    // vector<ll> sum;
 
    // for(int x=0; x<len; x++){
    //     for(int y=0; y<len; y++){
    //         sum.pb(v[x]+vv[y]);
    //     }
    // }
    // srt(sum);
    // debug(sum);


    auto ok=[&](ll mid){
        ll cnt=0;

        for(int x=0; x<len; x++){

            cnt+=upper_bound(vv.begin(),vv.end(),mid-v[x])-vv.begin();
        }

        return cnt>=k;
    };

    ll l=0,r=1e10+10,ans=0;

    while(l<=r){
        ll mid=l+(r-l)/2;

        if(ok(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }

    cout << ans << endl;
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}