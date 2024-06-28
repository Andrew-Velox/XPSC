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

#define ll long long
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define unq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) ((x/gcd(x,y))*y)
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl '\n'
#define fx(x) fixed<<setprecision(x)
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void error_txt(){
    #ifdef velox
    freopen("error.txt","w",stderr);
    #endif
}



void solve(){
    ll len, k; cin >> len >> k;
    vector<ll> v(len);

    for(int x=0; x<len; x++) cin >> v[x];

    ll l=0,r=0,ans=0;
    pbds<pair<ll,ll>> pbpr;
    while(r<len){
        pbpr.insert({v[r],r});

        if(r-l+1==k){
            auto mx = *pbpr.find_by_order(pbpr.size()-1);
            auto mn = *pbpr.find_by_order(0);
            debug(pbpr);
            cout << abs(mn.first-mx.first) << " ";
            pbpr.erase({v[l],l});
            l++;
        }
        r++;
    }
    cout << endl;
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}