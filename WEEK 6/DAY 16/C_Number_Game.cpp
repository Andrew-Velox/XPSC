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




    auto ok = [&] (ll mid){
        multiset<ll> ms;
        for(auto val: v) ms.insert(val);

        ll in=1;
        ll tmp=mid;
        bool f=true;
        while(tmp--){
            if(ms.empty()){
                f=false;
                break;
            }

            ll get=mid-in+1;
            in++;

            auto it = upper_bound(ms.begin(),ms.end(),get);
            if(it==ms.begin()){
                f=false;   
                break;
            }
            it--;
            

            ms.erase(it);
            if(!ms.empty()){
                it = ms.begin();
                ms.erase(it);
                ms.insert(*it+get);
            }
            debug(ms);

        }

        return f;

    };


    ll l=0,r=len, ans=0;

    while(l<=r){
        ll mid = l+(r-l)/2;

        if(ok(mid)){
            ans=mid;
            l=mid+1;
        }
        else r= mid-1;
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