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
    vector<ll> v(len),vv(len);

    for(int x=0; x<len; x++) cin >> v[x];
    for(int x=0; x<len; x++) cin >> vv[x];

    srt(v);
    srt(vv);

    ll cnt=0;
    bool f=true;

    ll get;
    for(int x=0; x<len; x++){
        ll mk = vv[x]-v[x];
        if(x==0) get=mk;

        if(v[x]>vv[x] || mk>1){
            f=false;
            break;
        }
    }

    if(f) YES;
    else NO;



    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}