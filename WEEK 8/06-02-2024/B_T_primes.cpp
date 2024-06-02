#include <bits/stdc++.h>
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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl '\n'
#define fx(x) fixed<<setprecision(x)

void error_txt(){
    #ifdef velox
    freopen("error.txt","w",stderr);
    #endif
}

bool prime(ll n){
    if(n==1) return false;
    ll cnt=0;
    for(ll x=2; x*x<=n; x++){
        if(n%x==0) return false;
    }
    
    return true;
}


void solve(){
    ll len; cin >> len;

    vector<ll> v(len);
    for(ll x=0; x<len; x++) cin >> v[x];

    for(ll x=0; x<len; x++){
        bool get = prime(sqrtl(v[x]));
        ll third_divisor=sqrtl(v[x]);
        if(get && third_divisor*third_divisor==v[x]) YES;
        else NO;
    }


}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}