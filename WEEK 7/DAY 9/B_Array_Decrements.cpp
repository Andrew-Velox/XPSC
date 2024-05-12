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
    vector<ll> v(len),v2(len);

    for(int x=0; x<len; x++) cin >> v[x];
    for(int x=0; x<len; x++) cin >> v2[x];

    ll mn_dif=INT_MAX;
    bool f=true;
    for(int x=0; x<len; x++){
        
        if(v[x] >= v2[x]){
            ll mk = v[x]-v2[x];
            if(mk < mn_dif && v2[x]==0 ) continue;
            mn_dif = min(mn_dif,mk);
        }
        else{
            f=false;
            break;
        }

    }

    ll get;
    for(int x=0; x<len; x++){
        get=v[x]-v2[x];
        if(mn_dif!=get){
            if(get < mn_dif && v2[x]==0 ) continue;
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