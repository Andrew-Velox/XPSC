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


ll set_bit_cnt(ll n){
    ll cnt=0;
    for(int x=0; x<=31; x++){
        if( ((n>>x)&1)==1 ) cnt++;
    }

    return cnt;
}



void solve(){
    ll n; cin >> n;

    // cout << set_bit_cnt(23243) << " ";
    // cout << __builtin_popcount(23243) << endl;


    ll get=__builtin_popcount(n);
    ll ans=1;
    while(n>0 && get>1){
        if(n%2==0) ans*=2;
        else get--;
        n/=2;
    }

    cout << ans << endl;

   
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}