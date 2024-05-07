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

    vector<ll> v(len);
    for(int x=0; x<len; x++) cin >> v[x];


    srt(v);


    auto ok = [&] (ll mid){
        ll cnt=1;
        ll l=0;

        for(int r=0; r<len; r++){
            if(v[r]-v[l] > 2*mid){
                cnt++;
                l=r;
            }
        }


        return cnt<=3;
    };


    ll l=0,r=1e9, ans=0;
    ll mid;


    while(l<=r){
        mid = l+(r-l)/2;

        if(ok(mid)){
            ans = mid;
            r=mid-1;
        }
        else l=mid+1;
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