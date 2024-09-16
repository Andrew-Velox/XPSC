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
    ll n,mc; cin >> n >> mc;

    vector<ll> v(mc);
    for(int x=0; x<mc; x++) cin >> v[x];

    srt(v);

    auto ok = [&](ll mid){
        ll cnt=0;
        bool f=true;
        ll tmp=mid;
        ll in=mc-1;
        while(tmp--){
            
            if(cnt>=v[in]){
                f=false;
                break;
            }
            else{
                cnt+=(n-v[in]);
            }
            in--;


        }
        return f;
    };





    ll l=0,r=mc,ans=0;
    while(l<=r){
        ll mid = l+ (r-l)/2;

        
        if(ok(mid)){
            ans=mid;
            l = mid+1;
            
        }
        else r=mid-1;
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