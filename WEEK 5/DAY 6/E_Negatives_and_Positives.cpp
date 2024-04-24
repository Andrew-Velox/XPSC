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



void solve(){
    ll len; cin >> len;


    ll cnt_neg=0;
    ll mn = INT_MAX;

    vector<ll> v(len);
    ll sum=0;

    for(int x=0; x<len; x++){
        cin >> v[x];
        mn=min(mn,abs(v[x]));
        sum+=abs(v[x]);
        if(v[x]<0) cnt_neg++;
    }
    // cout << sum << endl;
    if(cnt_neg%2==1) cout << sum-(mn*2) << endl;
    else cout << sum << endl;


    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}