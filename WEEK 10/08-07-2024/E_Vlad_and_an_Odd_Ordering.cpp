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
    ll n,k; cin >> n >> k;

    ll get=ceil(n*1.0/2.0);
    if(k<=get){

       if(n%2==0) cout << n-1-(abs(get-k)*2) << endl;
       else cout << n-(abs(get-k)*2) << endl;
       
    }
    else{
        ll a = 1;
        while(k > (n+1)/2) {
            a *= 2;
            k -= (n+1)/2;
            n /= 2;
            debug(a,k,n);
        }
        cout << (a*(k*2-1)) << endl;
    }
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}