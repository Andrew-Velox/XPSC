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
    ll n; cin >> n;
    vector<ll> ans;
    ans.push_back(n);

    ll no_of_set_bits=__builtin_popcount(n);
    while(no_of_set_bits > 1){ // while n!=2^x; or 1110 != 1000
        ll zeros= __builtin_ctz(n); // no of 0 from end to last set bit;
        n-=(1<<zeros); // or we can use, pow(2,zeros);

        no_of_set_bits=__builtin_popcount(n);
        ans.push_back(n);
        debug(ans);
    }

    while(n>1){
        n/=2;
        ans.push_back(n);
    }

    cout << ans.size() << endl;
    for(auto val: ans) cout << val  << " ";
    cout << endl;
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}