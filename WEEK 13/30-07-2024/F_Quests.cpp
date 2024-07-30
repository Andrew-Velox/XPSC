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
    ll len,need,day; cin >> len >> need >> day;
    vector<ll> v(len);

    for(int x=0; x<len; x++) cin >> v[x];


    grtsrt(v);
    ll t_sm=0;
    for(int x=0; x<min(day,len); x++) t_sm+=v[x];

    ll mx=v.front();
    if(mx*day < need){
        cout << "Impossible" << endl;
        return;
    }
    if(t_sm>=need){
        cout << "Infinity" << endl;
        return;
    }

    debug(v);


    auto ok = [&](ll mid){
        ll get = 0;
        for(int x=0; x<day; x++){
			
            if(x%mid < len){
                get += v[x%mid];
            }
            debug(x,mid,x%mid);
		}
        debug(endl);

        return get>=need;
    };
    

    ll l=1,r=day+2, ans=0;

    while(l<=r){
        ll mid = l + (r - l) / 2;

        if(ok(mid)){
            ans=mid;
            l=mid+1;
        }
        else r = mid-1;
    }


    cout <<  ans-1 << endl;
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}